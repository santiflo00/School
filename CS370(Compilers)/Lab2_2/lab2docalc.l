/*                 Lab2.2 lab2docalc.l
                   Santiago Flores
                   2/4/2020
                   

                   Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the lab2docalc.y YACC routine which
                   is a simple calculator

*/
%{

int mydebug=1;
#include "y.tab.h"
%}


%%
int         {if (mydebug) fprintf(stderr, "Fount int\n"); return (INT);}

[a-z]		{if (mydebug) fprintf(stderr,"Letter found\n"); 
                       yylval=*yytext-'a'; return(VARIABLE);}
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                       yylval=atoi((const char *)yytext); return(INTEGER);}
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=\-+*/%&|();] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext);  //parenthasis added to list 
                       return (*yytext);}
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                       return (*yytext);}
%%

int yywrap(void)
{ return 1;}


