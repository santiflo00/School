%{

/*Lab5  lab5.y
  Santiago Flores
  03/2/2020
  
  Yacc routine that will parse input(currently only checking syntax) that matches the language definition ALGOL_C. Yacc checks for syntactically correct code and if it finds syntax errors it returns with the line number of the error

*/


int yylex();
#include <stdio.h>
#include <ctype.h>

extern int linecount; // take the linecount from lex to print where error was found

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d\n", s, linecount);
}


%}

%union {
    int number;
    char *string;
}

%start program

%token INT BOOLEAN VOID MYBEGIN END IF THEN ELSE WHILE DO MYRETURN READ WRITE AND OR TRUE FALSE NOT //keyword tokens
%token GE LE EQ NE   //relational operator symbols

%token <number> NUM
%token <string> ID



%%	/* end specs, begin rules */

program :    declist
        ;

declist :   dec 
        |   dec declist
        ;

dec     :   vardec
        |   fundec
        ;
        
vardec  :   typespec varlist';'
        ;
        
varlist :   ID 
        |   ID'['NUM']' {fprintf(stderr, "found number %d\n",$3);}
        |   ID ',' varlist
        |   ID'['NUM']' ',' varlist  {fprintf(stderr, "found number %d\n",$3);}
        ;
        
typespec:   INT
        |   VOID
        |   BOOLEAN
        ;
        
fundec  :   typespec ID'('params')' compstmt
        ;
        
params  :   VOID
        |   paramlist
        ;
        
paramlist:  param 
        |   param ',' paramlist
        ;
        
param   :   typespec ID
        |   typespec ID'['']'
        ;
        
compstmt:   MYBEGIN locdec stmtlist END
        ;
        
locdec  :   /*empty */
        |   vardec locdec
        ;
        
stmtlist:   /*empty*/
        |   stmt stmtlist
        ;
        
stmt    :   exprstmt
        |   compstmt
        |   selecstmt
        |   iterstmt
        |   assignstmt
        |   retstmt
        |   readstmt
        |   writestmt
        ;
        
exprstmt:   expr ';'
        |   ';'
        ;
        
selecstmt:  IF expr THEN stmt
        |   IF expr THEN stmt ELSE stmt
        ;
        
iterstmt:   WHILE expr DO stmt
        ;
        
retstmt :   MYRETURN ';'
        |   MYRETURN expr ';'
        ;
        
readstmt:   READ var ';'
        ;
        
writestmt:  WRITE expr ';'
        ;
        
assignstmt: var '=' simpexpr ';'
        ;
        
expr    :   simpexpr
        ;
        
var     :   ID
        |   ID'['expr']'
        ;
        
simpexpr:   addexpr
        |   simpexpr relop addexpr
        ;
        
relop   :   GE | LE | EQ | NE | '<' | '>'
        ;
        
addexpr :   term
        |   term addop addexpr
        ;
        
addop   :   '+' | '-'
        ;
        
term    :   factor
        |   factor multop term
        ;
        
multop  :   '*' | '/' | AND | OR
        ;
        
factor  :   '('expr')'
        |   NUM             {fprintf(stderr, "found number %d\n",$1);}
        |   var
        |   call
        |   TRUE
        |   FALSE
        |   NOT factor
        ;
        
call    :   ID'('args')'
        ;
        
args    :   arglist
        |
        ;
        
arglist :   expr
        |   expr ',' arglist
        ;

%%	/* end of rules, start of program */

int main()
{ 
    yyparse();
}
