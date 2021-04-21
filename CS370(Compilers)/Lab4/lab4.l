/*                 Lab4 lab4.l
                   Santiago Flores
                   2/24/2020
                   

                   Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the lab2docalc.y YACC routine which
                   is a simple calculator

*/
%{

int mydebug=0;
#include "y.tab.h"
%}


%%
int         {if (mydebug) fprintf(stderr, "Fount int\n"); return (INT);}

[a-zA-Z][a-zA-Z0-9]*		{if (mydebug) fprintf(stderr,"Vairable found\n"); //Variable contains at least one letter lower or upper case followed by 0 or moreletters/num
                       yylval.string = strdup(yytext); return(VARIABLE);}
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                       yylval.number=atoi((const char *)yytext); return(INTEGER);}
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=\-+*/%&|();] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext);  //parenthasis added to list 
                       return (*yytext);}                  
                       
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                       return (*yytext);}
%%

int yywrap(void)
{ return 1;}


