%{
         /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Santiago Flores
            Feburary 2020
 
         */
        int comment = 0;
        int debug=1;  /* prints out debug statements if desired */
        int lineCount = 1;
%}

%%
"/*"	{
	if (comment && debug) fprintf(stderr,
		" >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n" , lineCount);
	comment = 1;
	}
"\n"    {
        lineCount++;
        printf("\n");
        }

"*/"	{
          if (!comment) printf("%s",yytext); /*print out if it is not in a comment */
  	  comment = 0;
	}
.       { if (!comment) printf("%s",yytext);}

%%

int yywrap(void)
{ return 1;
}

int main()
{
  yylex();
  
}

