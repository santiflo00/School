#Santiago Flores
#Lab2.2 Makefile
#2/4/2020
#
#YACC created files: y.tab.c  y.tab.h
#LEX created files: lex.yy.c
#Yacc takes the tokens that were found through the lex program which are shared through y.tab.h so compiling of lex.yy.c does not have all the data.

all: lab2_2

lab2_2: y.tab.c
	gcc y.tab.c -o lab2_2

y.tab.c: lab2docalc.l
	lex lab2docalc.l

lab2docalc.l: lab2docalc.y
	yacc -d lab2docalc.y
	

