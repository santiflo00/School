%{

/* Lab9 yacc file
 * FILE: lab9.y
   Added a symbol table help semantic action set.
   Using the symbol table yacc checks if variables have been declared
   and therefore can or cant be used
   Also yacc now does rudimentary type checking so that two different types cant be mixed
   Yacc take input tokens from lex
   and outputs any semantic or syntacticall errors. If no errors are found yacc calls ast to print the tree(from last lab)
 * 
   NEW 
   Main now reads input to generate a .asm file with a given name using -o argument when running the program
   Main now also prints 3 lines to the given file and calls emit_globals and emit_strings to print the MIPS
   code for writing strings and globals.
   Lastly  main calls emit_AST in emit.c to emit MIPS code based on the AST
   Inside the yacc code strings have been added in writestmt using a label instead of s1
   expr functions now also create temperary symbols used inside emit.c
   
 * Santiago Flores
 * 5/8/2020
 * 
 */

int yylex();
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "AST.h"
#include "symtable.h"
#include "emit.h"

ASTNode *GP; //global pointer

extern int linecount; // take the linecount from lex to print where error was found
int mydebug = 0;
int level = 0;
int offset = 0; //current offset
int GOFFSET;    //Global offset
int MAXOFFSET;  // the max amount of memory needed for the current function

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d\n", s, linecount);
}

%}

%union {
    int number;
    char *string;
    struct ASTNodeType *node;
    enum OPERATORS operator;
}

%start program

%token INT BOOLEAN VOID MYBEGIN END IF THEN ELSE WHILE DO MYRETURN READ WRITE AND OR TRUE FALSE NOT //keyword tokens
%token GE LE EQ NE   //relational operator symbols

%token <number> NUM
%token <string> ID
%token <string> STRING

%type <node> varlist vardec dec declist fundec params paramlist param locdec expr var simpexpr
%type <node> compstmt stmtlist stmt exprstmt selecstmt iterstmt assignstmt retstmt readstmt writestmt   //stmt nodes
%type <node> addexpr term factor call args arglist
%type <operator> typespec addop multop relop


%%	/* end specs, begin rules */

program :    declist {GP = $1;}
        ;

declist :   dec         { $$ = $1;}
        |   dec declist { $$ = $1;
                          $1->next = $2; 
                        }
        ;

dec     :   vardec {$$ = $1;}
        |   fundec {$$ = $1;} 
        ;
        
vardec  :   typespec varlist ';' {$$ = $2;
                                  ASTNode *p;
                                  p = $2;
                                  while(p != NULL){
                                    p->operator = $1;
                                    Search(p->name,level,0)->Type = $1; // add the type to the newly entered symbol
                                    p = p->s1;
                                    }//while
                                  }
        ;
        
varlist :   ID  {struct SymbTab *s;
                if(Search($1,level,0) != NULL){   //search to see if variable already exits before adding new entry, if it exits exit with error
                    yyerror("Duplicate Variable");
                    yyerror($1);
                    exit(1);
                  }//end if
                  else {//insert symbol
                     s = Insert($1, -1, 1, level, 1, offset, NULL); //Insert(name, operator type, isafunc, level, mysize, offset, ASTNode fparms)
                     offset=offset+1;
                     //Display();
                  }
                  $$ = ASTCreateNode(vardec);
                  $$->name = $1;
                  $$->size = 1;
                  $$->symbol = s;
                }//regular declaration 
                
        |   ID'['NUM']' {   struct SymbTab *s;
                            if( Search($1,level,0) != NULL){
                                yyerror("Duplicate Variable");
                                yyerror($1);
                                exit(1);
                            }//end if
                            else {
                                s = Insert($1, -1, 2, level, $3, offset, NULL); 
                                offset=offset+$3;
                                //Display();
                            }
                            $$ = ASTCreateNode(vardec);
                            $$->name = $1;
                            $$->size = $3;
                            $$->symbol = s;
                        }//array declaration
                        
        |   ID ',' varlist { struct SymbTab *s;
                             if(Search($1,level,0) != NULL){   //struct SymbTab * Search(char name[], int level, int recur)
                                yyerror("Duplicate Variable");
                                yyerror($1);
                                exit(1);
                             }//end if
                             else {//insert symbol
                                s = Insert($1, -1, 1, level, 1, offset, NULL); //Insert(name, operator type, isafunc, level, mysize, offset, ASTNode fparms)
                                offset=offset+1;
                                //Display();
                             }//end else
                             $$ = ASTCreateNode(vardec);
                             $$->name = $1;
                             $$->size = 1;
                             $$->s1 = $3;
                             $$->symbol = s;
                             
                           }//regular list
                           
        |   ID'['NUM']' ',' varlist  { struct SymbTab *s;
                                      if( Search($1,level,0) != NULL){
                                        yyerror("Duplicate Variable");
                                        yyerror($1);
                                        exit(1);
                                      }//end if
                                      else {
                                        s = Insert($1, -1, 2, level, $3, offset, NULL);
                                        offset=offset+$3;
                                        //Display();
                                      }
                                      $$ = ASTCreateNode(vardec);
                                      $$->name = $1;
                                      $$->size = $3;
                                      $$->s1 = $6;
                                      $$->symbol = s;
                                     }//array list declaration
        ;
        
typespec:   INT      {$$ = intType; }
        |   VOID     {$$ = voidType;}
        |   BOOLEAN  {$$ = boolType;}
        ;
        
fundec  :   typespec ID '(' {  if(Search($2,level,0) != NULL) {
                                  yyerror("Duplicate name");
                                  yyerror($2);
                                  exit(1);
                                }
                                else {//insert with no size or offset
                                  Insert($2,$1, 0,level, 0, 0,NULL);
                                }
                             GOFFSET = offset; //save global offset before entering a function 
                             offset = 2; //change to 2 later
                             MAXOFFSET = offset;
                            }                   //entering a function save offset to global offset and set offset to zero
            params')'{ Search($2,level,0)->fparms = $5;} compstmt {
                                                struct SymbTab *s;
                                                $$ = ASTCreateNode(fundec);
                                                $$->name = $2;
                                                $$->operator = $1;
                                                $$->s1 = $5;
                                                $$->s2 = $8;
                                                $$->size = MAXOFFSET;
                                                s = Search($2,0,0);
                                                offset = GOFFSET;
                                                Search($2,0,0)->mysize = MAXOFFSET;
                                                $$->symbol = s;
                                                //Display();
                                              }
        ;
        
params  :   VOID       {$$ = NULL;}
        |   paramlist  {$$ = $1;}
        ;
        
paramlist:  param                {$$ = $1;}
        |   param ',' paramlist  {$$ = $1;
                                  $1->next = $3;
                                 }
        ;
        
param   :   typespec ID        {if( Search($2,level+1, 0) != NULL ) { //set one level up(inside function) since it starts at function level
                                    yyerror("Duplicate Vairable");
                                    yyerror($2);
                                    exit(1);
                                 }
                                else {
                                    Insert($2, $1, 1, level+1, 1, offset, NULL);
                                    offset = offset+1;
                                }
                                $$ = ASTCreateNode(param);
                                $$->name = $2;
                                $$->operator = $1;
                                $$->size = 0;
                                $$->sem_type = $1;
                               }
                               
        |   typespec ID'['']'  {if( Search($2,level+1, 0) != NULL ) {
                                    yyerror("Duplicate Vairable");
                                    yyerror($2);
                                    exit(1);
                                 }
                                else {
                                    Insert($2, $1, 2, level+1, 1, offset, NULL);
                                    offset = offset+1;
                                }
                                $$ = ASTCreateNode(param);
                                $$->name = $2;
                                $$->operator = $1;
                                $$->size = -1; //size is -1 to tell the c program that this is an array
                                $$->sem_type = $1;
                               }
        ;
        
compstmt:   MYBEGIN {level++;} locdec stmtlist END {
                                         $$ = ASTCreateNode(block);
                                         $$->s1 = $3;
                                         $$->s2 = $4;
                                         if (offset > MAXOFFSET) MAXOFFSET = offset;
                                         Display();
                                         offset -= Delete(level);//reset offset when leaving a compstmt
                                         level--; //reduce level

                                        }
        ;
        
locdec  :   /*empty */    {$$ = NULL;}

        |   vardec locdec {$$ = $1;
                           $1->next = $2;
                          }
        ;
        
stmtlist:   /*empty*/     {$$ = NULL;}

        |   stmt stmtlist {$$ = $1;
                           $1->next = $2;
                          }
        ;
        
stmt    :   exprstmt     {$$ = $1;}
        |   compstmt     {$$ = $1;}
        |   selecstmt    {$$ = $1;}
        |   iterstmt     {$$ = $1;}
        |   assignstmt   {$$ = $1;}
        |   retstmt      {$$ = $1;}
        |   readstmt     {$$ = $1;}
        |   writestmt    {$$ = $1;}
        ;
        
exprstmt:   expr ';' {$$ = ASTCreateNode(exprstmt);
                      $$->s1 = $1;}
        |   ';'      {$$ = ASTCreateNode(exprstmt);
                      $$->s1 = NULL;}
        ;
        
selecstmt:  IF expr THEN stmt            {$$ = ASTCreateNode(selecstmt);
                                          $$->s1 = $2;
                                          $$->s2 = $4;
                                         }
        |   IF expr THEN stmt ELSE stmt  {ASTNode *p;
                                          $$ = ASTCreateNode(ifelse);
                                          p = ASTCreateNode(ifelse1);
                                          
                                          $$->s1 = $2;
                                          $$->s2 = p;
                                          
                                          p->s1 = $4;
                                          p->s2 = $6;
                                
                                         }
        ;
        
iterstmt:   WHILE expr DO stmt  {$$ = ASTCreateNode(whilestmt);
                                 $$->s1 = $2;
                                 $$->s2 = $4;
                                }
        ;
        
retstmt :   MYRETURN ';'       {$$ = ASTCreateNode(myReturn);}
        |   MYRETURN expr ';'  {$$ = ASTCreateNode(myReturn);
                                $$->s1 = $2;
                               }
        ;
        
readstmt:   READ var ';'     {$$ = ASTCreateNode(myRead);
                              $$->s1 = $2;
                             }
        ;
        
writestmt:  WRITE expr ';'   {$$ = ASTCreateNode(myWrite);
                              $$->s1 = $2;
                             }
                             
        |   WRITE STRING ';' {$$ = ASTCreateNode(myWrite);
                              $$->name = $2;
                              $$->label = genlabel();
                             }
        ;
        
assignstmt: var '=' simpexpr ';'  {if($1->sem_type != $3->sem_type){//type checking - if they dont have the same type, error and exit
                                        yyerror("type conflict in assignstmt");
                                        exit(1);
                                   }
                                   $$ = ASTCreateNode(assignstmt);
                                   $$->s1 = $1;
                                   $$->s2 = $3;
                                   $$->operator = myEqual;
                                   $$->name = CreateTemp();
                                   $$->symbol = Insert($$->name, intType, 0, level,1,offset,NULL);
                                   offset++;
                                  }
        ;
        
expr    :   simpexpr         {$$ = $1;}
        ;
        
var     :   ID               {  struct SymbTab *p = Search($1, level, 1);//search all level up
                                if(p == NULL){
                                    yyerror("Variable does not exist");
                                    yyerror($1);
                                    exit(1);
                                }
                                if(p->IsAFunc != 1){ //error if not a scalar
                                    yyerror("Variable is not scalar");
                                    yyerror($1);
                                    exit(1);
                                }
                                $$ = ASTCreateNode(identifier);
                                $$->name = $1;
                                $$->symbol = p; //add the symbol to the ast
                                $$->sem_type = p->Type; //set the semantic type to the same type of the symbol
                             }//regular declaration 
        |   ID'['expr']'     {  struct SymbTab *p;
                                p = Search($1,level,1);
                                if(p == NULL) { // Check to make sure the variable exist in the table
                                    yyerror("Variable does not exist");
                                    yyerror($1);
                                    exit(1);
                                }
                                if(p->IsAFunc != 2) { //the symbol does exist so check if id is not an array throw error and exit
                                    yyerror("Variable is not an array");
                                    yyerror($1);
                                    exit(1);
                                }
                                $$ = ASTCreateNode(identifier);
                                $$->name = $1;
                                $$->s1 = $3;
                                $$->symbol = p;
                                $$->sem_type = p->Type;
                             }
        ;
        
simpexpr:   addexpr                  {$$ = $1;}
        |   simpexpr relop addexpr   {if($1->sem_type != $3->sem_type) { //type checking
                                        yyerror("type conflict in simpexpr");
                                        exit(1);
                                      }
                                      $$ = ASTCreateNode(expr);
                                      $$->s1 = $1;
                                      $$->s2 = $3;
                                      $$->operator = $2;
                                      $$->sem_type = $1->sem_type; //pass up the type of the symbol 
                                      $$->name = CreateTemp();
                                      $$->symbol = Insert($$->name, intType, 0, level,1,offset,NULL);
                                      offset++;
                                     }
        ;
        
relop   : GE   {$$ = greaterEqual;}
        | LE   {$$ = lessEqual;}
        | EQ   {$$ = equal;}
        | NE   {$$ = notEqual;}
        | '<'  {$$ = less;}
        | '>'  {$$ = greater;}
        ;
        
addexpr :   term                {$$ = $1;}
        |   addexpr addop term  {if($1->sem_type != $3->sem_type){ //type checking
                                    yyerror("type conflict in addexpr");
                                    exit(1);
                                 }
                                 $$ = ASTCreateNode(expr);
                                 $$->s1 = $1;
                                 $$->s2 = $3;
                                 $$->operator = $2;
                                 $$->sem_type = $1->sem_type;
                                 $$->name = CreateTemp();
                                 $$->symbol = Insert($$->name, intType, 0, level,1,offset,NULL);
                                 offset++;
                                }
        ;
        
addop   :   '+'  {$$ = plus;}
        |   '-'  {$$ = minus;}
        ;
        
term    :   factor              {$$ = $1;}
        |   term multop factor  {if($1->sem_type != $3->sem_type){ //type checking
                                    yyerror("type conflict in term");
                                    exit(1);
                                 }
                                 $$ = ASTCreateNode(expr);
                                 $$->s1 = $1;
                                 $$->s2 = $3;
                                 $$->operator = $2;
                                 $$->sem_type = $1->sem_type;
                                 $$->name = CreateTemp();
                                 $$->symbol = Insert($$->name, intType, 0, level,1,offset,NULL);
                                 offset++;
                                }
        ;
        
multop  : '*'     {$$ = times;} 
        | '/'     {$$ = divide;}
        | AND     {$$ = myAnd;}
        | OR      {$$ = myOr;}
        ;
        
factor  :   '('expr')'      {$$ = $2;}
        |   NUM             {$$ = ASTCreateNode(myNum);
                             $$->size = $1;
                             $$->sem_type = intType; //all numbers have type int
                            }
        |   var             {$$ = $1;}
        |   call            {$$ = $1;}
        |   TRUE            {$$ = ASTCreateNode(mybool);
                             $$->size = 1; //use size one so that we know its true
                             $$->sem_type = boolType; //true is a boolean type
                            }   
        |   FALSE           {$$ = ASTCreateNode(mybool);
                             $$->size = 0; //set to zero so we know to print false
                             $$->sem_type = boolType; //false is a boolean type

                            }
        |   NOT factor      {if($2->sem_type != boolType){ //only booleans can have NOT in front
                                exit(1);
                             }
                             $$ = ASTCreateNode(expr);
                             $$->s1 = $2;
                             $$->operator = myNot;
                             $$->sem_type = $2->sem_type;
                             $$->name = CreateTemp();
                             $$->symbol = Insert($$->name, intType, 0, level,1,offset,NULL);
                             offset++;
                            }
       // |   '"'STRING'"'    {$$ = ASTCreateNode(mystring);
                            
        ;
        
call    :   ID'('args')'    {struct SymbTab *p = Search($1,level,1);
                             if(p == NULL){
                                yyerror("The function does not exist");
                                yyerror($1);
                                exit(1);
                             }
                             if(p->IsAFunc != 0) { // symbol must be a function
                                yyerror("The ID is not a function");
                                exit(1);
                             }
                             if(check_params(p->fparms, $3) != 1){ //the function call must have the correct parameters as the actual function
                                yyerror("Function acutal and formal parameters mismatch");
                                exit(1);
                             }
                             $$ = ASTCreateNode(call);
                             $$->name = $1;
                             $$->s1 = $3;
                             $$->symbol = p;
                             $$->sem_type = p->Type;
                            }
        ;
        
args    :   arglist     {$$ = $1;}
        |   /*empty*/   {$$ = NULL;}
        ;
        
arglist :   expr                {$$ = ASTCreateNode(arg);
                                 $$->sem_type = $1->sem_type;
                                 $$->s1 = $1;
                                 $$->next = NULL;
                                 $$->name = CreateTemp();
                                 $$->symbol = Insert($$->name, intType, 0, level,1,offset,NULL);
                                 offset++;
                                }
        |   expr ',' arglist    {
                                 ASTCreateNode(arg);
                                 $$->sem_type = $1->sem_type;
                                 $$->s1 = $1;
                                 $$->next = $3;
                                 $$->name = CreateTemp();
                                 $$->symbol = Insert($$->name, intType, 0, level,1,offset,NULL);
                                 offset++;
                                }
        ;

%%	/* end of rules, start of program */

int main(int argc, char * argv[]) {

    FILE *fp;
    char s[100];
    int i = 1;
    int found = 0;
    
    //if -d is given when running the code turn on debug
    while(i < argc) {
        if (strcmp(argv[i], "-d")==0) {
            mydebug = 1;
            i = i + 1;
        }// use the argument after -o to get the name of the .asm file -o must be given followed by a name
        else if (strcmp(argv[i], "-o")==0) {
            if(argc > i+1) found = 1;
            sprintf(s,"%s.asm",argv[i+1]);
            i=i+2;
        }
    else i = i+1;
    }
    
    if(found == 0) {
        printf("An argument must be given after -o\n");
        exit(1);
    }
    fp = fopen(s,"w");
    if (fp == NULL){
        printf("The file %s cannot be opened \n",s);
        exit(1);
    }
    
    printf("My file is %s\n", s);        

    yyparse();
    
    //print out the tree using the global pointer
    ASTprint(GP, 0);
    
    fprintf(fp, ".data\n");
    emit_strings(GP,fp); //find string and create labels in the file before writing other code
    fprintf(fp, "\n.align 2\n\n");
    emit_globals(GP,fp);//find global variables and create before code
    fprintf(fp, "\n.text\n\n");

    emit_AST(GP,fp); //call to write MIPS code to file
    
}//end main
