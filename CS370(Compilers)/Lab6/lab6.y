%{

/* Santiago Flores
   March 28, 2020
   Lab6 Abstract Syntax Tree
   FILE: lab6.y
   
   This yacc file creates a pointer to a data structure which represents the parsed program.
   At the end of each production rule a new node is created with specific information. The nodes each
   have different types to understand what the node is supposed to be representing.
*/


int yylex();
#include <stdio.h>
#include <ctype.h>
#include "AST.h"

ASTNode *GP;

extern int linecount; // take the linecount from lex to print where error was found

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d\n", s, linecount);
}

enum OPERATORS Cur_type;//used to get the type of a variable declaration since it is being shared with the operators

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
        
vardec  :   typespec varlist ';' {$$ = $2;}
        ;
        
varlist :   ID  { $$ = ASTCreateNode(vardec);
                  $$->name = $1;
                  $$->size = 1;
                  $$->operator = Cur_type;
                }//regular declaration 
                
        |   ID'['NUM']' {   $$ = ASTCreateNode(vardec);
                            $$->name = $1;
                            $$->size = $3;
                            $$->operator = Cur_type;
                        }//array declaration
                        
        |   ID ',' varlist { $$ = ASTCreateNode(vardec);
                             $$->name = $1;
                             $$->size = 1;
                             $$->operator = Cur_type;
                             $$->s1 = $3;
                           }//regular list
                           
        |   ID'['NUM']' ',' varlist  {$$ = ASTCreateNode(vardec);
                                      $$->name = $1;
                                      $$->size = $3;
                                      $$->operator = Cur_type;
                                      $$->s1 = $6;
                                     }//array list declaration
        ;
        
typespec:   INT      {$$ = intType;  Cur_type = $$;}
        |   VOID     {$$ = voidType; Cur_type = $$;}
        |   BOOLEAN  {$$ = boolType; Cur_type = $$;}
        ;
        
fundec  :   typespec ID '('params')' compstmt { $$ = ASTCreateNode(fundec);
                                                $$->name = $2;
                                                $$->operator = $1;
                                                $$->s1 = $4;
                                                $$->s2 = $6;
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
        
param   :   typespec ID        {$$ = ASTCreateNode(param);
                                $$->name = $2;
                                $$->operator = $1;
                                $$->size = 0;
                               }
                               
        |   typespec ID'['']'  {$$ = ASTCreateNode(param);
                                $$->name = $2;
                                $$->operator = $1;
                                $$->size = -1; //size is -1 to tell the c program that this is an array
                               }
        ;
        
compstmt:   MYBEGIN locdec stmtlist END {$$ = ASTCreateNode(block);
                                         $$->s1 = $2;
                                         $$->s2 = $3;
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
        
exprstmt:   expr ';' {$$ = $1;}
        |   ';'      {$$ = NULL;}
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
                                
                                         } //need to fix
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
        ;
        
assignstmt: var '=' simpexpr ';'  {$$ = ASTCreateNode(assignstmt);
                                   $$->s1 = $1;
                                   $$->s2 = $3;
                                   $$->operator = myEqual;
                                  }
        ;
        
expr    :   simpexpr         {$$ = $1;}
        ;
        
var     :   ID               {  $$ = ASTCreateNode(identifier);
                                $$->name = $1;
                             }//regular declaration 
        |   ID'['expr']'     {  $$ = ASTCreateNode(identifier);
                                $$->name = $1;
                                $$->size = -1;//to know that its an array
                                $$->s1 = $3;
                             }
        ;
        
simpexpr:   addexpr                  {$$ = $1;}
        |   simpexpr relop addexpr   {$$ = ASTCreateNode(expr);
                                      $$->s1 = $1;
                                      $$->s2 = $3;
                                      $$->operator = $2;
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
        |   term addop addexpr  {$$ = ASTCreateNode(expr);
                                 $$->s1 = $1;
                                 $$->s2 = $3;
                                 $$->operator = $2;
                                }
        ;
        
addop   :   '+'  {$$ = plus;}
        |   '-'  {$$ = minus;}
        ;
        
term    :   factor              {$$ = $1;}
        |   factor multop term  {$$ = ASTCreateNode(expr);
                                 $$->s1 = $1;
                                 $$->s2 = $3;
                                 $$->operator = $2;
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
                            }
        |   var             {$$ = $1;}
        |   call            {$$ = $1;}
        |   TRUE            {$$ = ASTCreateNode(mybool);
                             $$->size = 1; //use size one so that we know its true
                            }   
        |   FALSE           {$$ = ASTCreateNode(mybool);
                             $$->size = 0; //set to zero so we know to print false
                            }
        |   NOT factor      {$$ = ASTCreateNode(expr);
                             $$->s1 = $2;
                             $$->operator = myNot;
                            }
        ;
        
call    :   ID'('args')'    {$$ = ASTCreateNode(call);
                             $$->name = $1;
                             $$->s1 = $3;
                            }
        ;
        
args    :   arglist     {$$ = $1;}
        |   /*empty*/   {$$ = NULL;}
        ;
        
arglist :   expr                {$$ = $1;}
        |   expr ',' arglist    {$$ = $1;
                                 $1->next = $3;
                                }
        ;

%%	/* end of rules, start of program */

int main()
{ 
    yyparse();
    
    //print out the tree using the global pointer
    ASTprint(GP, 0);
}
