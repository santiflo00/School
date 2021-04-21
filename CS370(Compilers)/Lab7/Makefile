#Santiago Flores
#
#Makefile for Lab7
all:
	yacc -d lab7.y
	lex lab7.l
	gcc lex.yy.c y.tab.c AST.c symtable.c -o lab7

clean:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm lab7
