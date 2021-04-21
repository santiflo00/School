%{

/*Lab2.2  lab2docalc.y
  Santiago Flores
  2/4/2020
  Takes input from user and does calculations
  outputs the solutions to user input calculations
  Example: -(3 * 9) will output -27
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
   
   1) Add rules to yacc
   2) Fix symbol table 
   3) Enhance lex
   4)
*/


	/* begin specs */

int yylex();
#include <stdio.h>
#include <ctype.h>


int regs[26];
int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated 
%union{
    int value;
    char * string;
    }
    <value>
    
*/

%start program

%token INTEGER
%token VARIABLE
%token INT

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
      
DEC : INT VARIABLE ';' '\n'
    ;

list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ yyerrok; }
	;

stat	:	expr
			{ fprintf(stderr,"the anwser is%d\n", $1); }
	|	VARIABLE '=' expr
			{ regs[$1] = $3; }
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
	|	VARIABLE
			{ $$ = regs[$1]; fprintf(stderr,"found a variable value =%d\n",$1); }
	|	INTEGER {$$=$1; fprintf(stderr,"found an integer\n");}
	;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
