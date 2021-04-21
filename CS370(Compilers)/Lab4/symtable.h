//symtable.h file
//Santiago Flores
//Feb 24, 2020

#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#ifndef SYMBTAB
#define SYMBTAB

void Insert(char *sym, int offset);
int Search(char *sym);
int getAddr(char *sym);

#endif // of SYMBTAB
