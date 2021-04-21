/*symtable.c data structure that holds variables as symbols from yacc
  Santiago Flores
  Feb 24, 2020
  Uses a linked list to hold each symbol. each symbol has a string and and address attached to it
  
*/

#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"

void Insert(char *sym, int offset);
int  Search(char *sym);
int  getAddr(char *sym);

struct SymbTab {
    struct SymbTab *next;
    char *symbol; //the symbol it self
    int addr; //where the symbol is stored 
};

//set debug to 1 to test functions
int debug = 0;

struct SymbTab *first, *last;

//inserts the given symbol only if it doesn't exists in the table already
void Insert(char *sym, int offset) {
    int exists;
    exists = Search(sym);
    
    if(exists == 1){
        printf("The symbol exists in the table\n");
    }
    else{
        
        struct SymbTab *p; //pointer to add new symbol
        p = malloc(sizeof(struct SymbTab));
        p->next = NULL;
    
        if(offset == 0) { //the table is empty automatically enter symbol
            first = p;
            last = p;
        }//of if
    
        else{
            last->next = p;
            last = p;
        }//of else
        
        p->symbol = strdup(sym);
        p->addr = offset;
        if(debug == 1)printf("The symbol %s has been inserted\n\n",sym); 
    }//of else
    
}//of Insert

//Search to see if the symbol given exists inside the table return address if it does otherwise return -1
int Search(char *sym){ //return 1 if exists and zero if it doesn't
    int found = 0;
    struct SymbTab *p;
    p = first;
    
    while(p != NULL) {
        if(strcmp(p->symbol,sym)==0) {  //strcmp compare the strings if = 0 strings are equal
            found = 1;
        }//of if
            p = p->next;
    }//of while
    
    //debug statements
    if(debug == 1 && found == 1) printf("The string %s exists in the table\n\n" ,sym);
    else if(debug == 1 && found == 0)printf("The string %s does not exists in the table\n\n",sym);
    
    return found;
    
}//of Search

//Return the address of the given symbol
int getAddr(char *sym) {
    int x = -1; //x initially set with -1 if no address is found
    struct SymbTab *p;
    p = first;
    
    while(p != NULL) {
        if(strcmp(p->symbol,sym)==0) {  //strcmp compare the strings if = 0 strings are equal
            x = p->addr;//store x with address when found
        }//of if
            p = p->next;
    }//of while
    if(debug == 1) printf("The symbol %s has offset %d\n\n", sym,x);
    return x;
}//of offset

//Test to see if the symtable is working
// void main() {
// 
//     Insert("V1");
//     Search("V4");
//     Search("V1");
//     Insert("V2");
//     Insert("V3");
//     getOffset("V1");
//     getOffset("V3");
//     getOffset("V2");
//     Search("V2");
//     Search("vds");
//     
// }//of main
    
