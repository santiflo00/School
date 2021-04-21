%{

/*Lab4  lab4.y
  Santiago Flores
  2/24/2020
  Takes input from user and sets integer variable that can be used in the calculator with the given value
  outputs the solutions to user input calculations
  Example: int x;
           x = 3
           x + 7
           answer is 10
*/

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correc   Shaun Cooper
    January 2015t memmory look up or the storage depending
   on position

   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in
   
*/


	/* begin specs */

int yylex();
#include <stdio.h>
#include <ctype.h>
#include "symtable.h"

#define MAX_VAR 5 //Max number of variables that can be declared

int regs[26];
int base, debugsw;
int offset = 0;
int exists;//to see if the varible being used

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}

%union {
    int number;
    char *string;
}

%start program

%token <number> INTEGER
%token <string> VARIABLE
%token <string> INT

%type <number> expr

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


%%	/* end specs, begin rules */

program: DECLS list
       ;
       
DECLS : DEC DECLS
      |/*empty */
      ;
                            //if the max number of varibles has not been met then try to insert, if variable already exists throw error
DEC : INT VARIABLE ';' '\n' { if(offset >= MAX_VAR) fprintf(stderr, "Cannot insert %s, max variable declerations met\n",$2);
                              else if(Search($2) == 0 ){Insert($2,offset); offset++; printf("inserting %s to table\n\n",$2); }
                              else fprintf(stderr, "error variable already exists\n\n");    }//if it does find variable throw error
    ;

list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ yyerrok; }
	;

stat	:	expr   //dont give answer if the variable doesnt exists
			{ if(exists)fprintf(stderr,"the anwser is %d\n", $1); else {} }
	|	VARIABLE '=' expr
			{ if(Search($1) == 1) regs[getAddr($1)] = $3; 
			  else {fprintf(stderr, "variable %s doesn't exist\n",$1);}  } //change the variable only if the Variable exists in symbol table 
	;

expr	:	'(' expr ')'
			{ $$ = $2; }
	|	expr '-' expr
			{ $$ = $1 - $3; }
	|	expr '+' expr
			{ $$ = $1 + $3; }
	|	expr '/' expr
			{ $$ = $1 / $3; }
    |   expr '*' expr             //Added multiplication
            { $$ = $1 * $3; }
	|	expr '%' expr
			{ $$ = $1 % $3; }
	|	expr '&' expr
			{ $$ = $1 & $3; }
	|	expr '|' expr
			{ $$ = $1 | $3; }
	|   '-' expr	%prec UMINUS  //removed extra expression 
			{ $$ = -$2; }
	|	VARIABLE               //Error if the variable has not been declared/can't be found in symbol table.
			{ if(Search($1)) {$$ = regs[getAddr($1)]; fprintf(stderr,"found a variable value = %s \n",$1);exists=1;}
			  else {fprintf(stderr, "error variable %s does not exists\n",$1); exists=0;} }
	|	INTEGER {$$=$1; fprintf(stderr,"found an integer\n");}
	;



%%	/* end of rules, start of program */

int main()
{ 
    yyparse();
}
