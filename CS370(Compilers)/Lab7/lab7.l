%{
/* Santiago Flores
   April 15, 2020
   Lab7  Symbol table
   FILE: lab7.l
   
   Lex finds keyword tokens for yacc to use in parsing
   
   Keyword tokens:
   int, boolean
   void
   begin, end
   if, then, else
   while, do
   return
   read, write
   and, or
   true, false, not
   
   Tokens with attributes:
   ID
   NUM
*/


int linecount = 1; //count lines starting with 1
#include "AST.h"
#include "symtable.h"
#include "y.tab.h"


%}
/*Tokens
%token INT BOOLEAN VOID BEGIN END IF THEN ELSE WHILE DO RETURN READ WRITE AND OR TRUE FALSE NOT
%token EQ NE LE GE
*/
%%
int         {return(INT);}
boolean     {return(BOOLEAN);}
void        {return(VOID);}
begin       {return(MYBEGIN);}
end         {return(END);}
if          {return(IF);}
then        {return(THEN);}
else        {return(ELSE);}
while       {return(WHILE);}
do          {return(DO);}
return      {return(MYRETURN);}
read        {return(READ);}
write       {return(WRITE);}
and         {return(AND);}
or          {return(OR);}
true        {return(TRUE);}
false       {return(FALSE);}
not         {return(NOT);}
"=="        {return(EQ);}
"!="        {return(NE);}
"<="        {return(LE);}
">="        {return(GE);}

[a-zA-Z][a-zA-Z0-9]*    {yylval.string = strdup(yytext); return(ID);}
[0-9][0-9]*             {yylval.number=atoi((const char *)yytext);return(NUM);}
[\[\]\-+*%=/,\)\(<>;]       {return(*yytext);}
\n                      {linecount++;}
[ \t]                   {/*Eat whitespace*/}

%%

int yywrap(void){
    return 1;
}
