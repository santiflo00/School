/*Santiago Flores
 * Feb 7, 2020
 * Symbol Table
 * Code taken from 'http://forgetcode.com/C/101-Symbol-table' 
 * The code takes in a symbol and stores it into a linked list data structure
 * The code has 6 functions: 1.Insert: enter a symbol  2.Display: display the symbol requested 3. Delete: delete a symbol from the table
 * 4.Search: search for a symbol  5.Modify change a specific symbol 6. End: exit program
 */

#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"

int size=0;
int offset=0;
void Insert();
void Display();
void Delete();
int Search(char lab[]);void Modify();
struct SymbTab
{
    char label[10],symbol[10];
    int addr;
    struct SymbTab *next;
};

struct SymbTab *first,*last;

void main()
{
//     int op,y;
//     char la[10];
//     do 
//     {
//         printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
//         printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n"); 
//         printf("\n\tEnter your option : "); //ask user to enter an option
//         scanf("%d",&op);
//         switch(op)
//         {
//             case 1:
//                 Insert(); //go to insert function
//                 break;
//                 
//             case 2:
//                 Display(); //enter 2 and go to display funtion
//                 break;
//                 
//             case 3:
//                 Delete();//3 is entered go to delete function
//                 break;
//                 
//             case 4: //4 is entered go to search fucntion
//                 printf("\n\tEnter the label to be searched : ");
//                 scanf("%s",la);
//                 y=Search(la);
//                 printf("\n\tSearch Result:");
//                 
//                 if(y==1)
//                     printf("\n\tThe label is present in the symbol table\n");
//                 
//                 else
//                     printf("\n\tThe label is not present in the symbol table\n");
//                 break;
//                 
//             case 5: //5 entered go to modify
//                 Modify();
//                 break;
//                 
//             case 6: //6 entered go to exit and end program
//                 exit(0);
//         }//end switch
//         
//     } while(op<6);
    
}  /* end of main */

void Insert()
{
    int n;
    char l[10];
    
    printf("\n\tEnter the label : ");
    scanf("%s",l);
    n=Search(l);
    
    if(n==1) //if a value already exists then do not insert
        printf("\n\tThe label exists already in the symbol table\n\tDuplicate can.t be inserted");
    else
    {
        struct SymbTab *p;
        p=malloc(sizeof(struct SymbTab));
        strcpy(p->label,l);
        printf("\n\tEnter the symbol : ");
        scanf("%s",p->symbol);
        printf("\n\tEnter the address : ");
        scanf("%d",&p->addr);
        p->next=NULL;
        if(size==0)
        {
            first=p;
            last=p;
        }
        else
        {
            last->next=p;
            last=p;
        }
        size++;
    }
    printf("\n\tLabel inserted\n");
}//end Insert

// void Display() //print out label symbol and address
// {
//     int i;
//     struct SymbTab *p;
//     p=first;
//     printf("\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");
//     for(i=0;i<size;i++)
//     {
//         printf("\t%s\t\t%s\t\t%d\n",p->label,p->symbol,p->addr);
//         p=p->next;
//     }
// }//end Display

int Search(char lab[]) //search for value using for loop
{
    int i,flag=0;
    struct SymbTab *p;
    p=first;
    for(i=0;i<size;i++)
    {
        if(strcmp(p->label,lab)==0)
            flag=1;
        p=p->next;
    }
    return flag;
}//end Search

void Modify() //change the specified label or address or both
{
    char l[10],nl[10];
    int add,choice,i,s;
    struct SymbTab *p;
    p=first;
    printf("\n\tWhat do you want to modify?\n");
    printf("\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n");
    printf("\tEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: //case 1 changes the label only
            printf("\n\tEnter the old label : ");
            scanf("%s",l);
            s=Search(l);
            if(s==0)
                printf("\n\tLabel not found\n");
            else
            {
                printf("\n\tEnter the new label : ");
                scanf("%s",nl);
                for(i=0;i<size;i++)
                {
                    if(strcmp(p->label,l)==0)
                        strcpy(p->label,nl);
                    p=p->next;
                }
                printf("\n\tAfter Modification:\n");
                Display();
            }
            break;
            
        case 2:  //case 2 changes only the address
            printf("\n\tEnter the label where the address is to be modified : ");
            scanf("%s",l);
            s=Search(l);
            if(s==0)
                printf("\n\tLabel not found\n");
            else
            {
                printf("\n\tEnter the new address : ");
                scanf("%d",&add);
                for(i=0;i<size;i++)
                {
                    if(strcmp(p->label,l)==0)
                        p->addr=add;
                    p=p->next;
                }
                printf("\n\tAfter Modification:\n");
                Display();
            }
            break;
            
        case 3: //case 3 changes both address and label
            printf("\n\tEnter the old label : ");
            scanf("%s",l);
            s=Search(l);
            if(s==0)
                printf("\n\tLabel not found\n");
            else
            {
                printf("\n\tEnter the new label : ");
                scanf("%s",nl);
                printf("\n\tEnter the new address : ");
                scanf("%d",&add);
                for(i=0;i<size;i++)
                {
                    if(strcmp(p->label,l)==0)
                    {
                        strcpy(p->label,nl);
                        p->addr=add;
                    }
                    p=p->next;
                }
                printf("\n\tAfter Modification:\n");
                Display();
            }
            break;
    }
}//end Modify

void Delete() //search for specified symbol and remove it
{
    int a;
    char l[10];
    struct SymbTab *p,*q;
    p=first;
    printf("\n\tEnter the label to be deleted : ");
    scanf("%s",l);
    a=Search(l);
    if(a==0)
        printf("\n\tLabel not found\n");
    else
    {
        if(strcmp(first->label,l)==0)
            first=first->next;
        else if(strcmp(last->label,l)==0)
        {
            q=p->next;
            while(strcmp(q->label,l)!=0)
            {
                p=p->next;
                q=q->next;
            }
            p->next=NULL;
            last=p;
        }
        else
        {
            q=p->next;
            while(strcmp(q->label,l)!=0)
            {
                p=p->next;
                q=q->next;
            }
            p->next=q->next;
        }
        size--;
        printf("\n\tAfter Deletion:\n");
        Display();
    }
}//end delete

