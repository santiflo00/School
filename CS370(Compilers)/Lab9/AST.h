/*
 * 
 * Header file for AST.c
 * FILE: AST.h
 * 
 * The header file for AST.c
 * Creates a new struct called ASTNode which is used to create a pointer to the data structure
 * that is used to represent the parsed program.
 * ASTNode contains:
 *  enum NODETYPE - to hold the type of node when a new node is created
 *  enum OPERATORS - holds operators and datatypes
 *  ASTNodeType  s1, s2, next - nodes that point to other nodes connecting everything together
 *  char name - holds the name if needed
 *  int size - holds the size for nodes that have associated numbers if needed
 * 
 * Update lab7
 * ASTNode now holds the pointer to an entry in the symbol table called symbol
 * ASTNode now uses a new operator called sem_type to help yacc with type checking sem_type only holds a data type
 * ASTNode now also holds the function check_params
 * 
 * Update Lab9
 * Not changed
 * 
 * Santiago Flores
 * 5/8/2020
 */
#ifndef AST
#define AST


enum NODETYPE{  //nodetypes
    vardec,
    fundec, 
    param,
    block,
    whilestmt,
    myReturn,
    identifier,
    call,
    myWrite,
    myRead,
    myNum,
    expr,
    selecstmt,
    ifelse,
    ifelse1,
    assignstmt,
    mybool,
    exprstmt,
    arg
};

enum OPERATORS { ///operators and datatypes
    plus,
    minus,
    times,
    divide,
    myOr,
    myAnd,
    myTrue,
    myFalse,
    boolType,//datatype
    voidType,//datatype
    intType,//datatype
    greaterEqual,
    lessEqual,
    equal,
    notEqual,
    less,
    greater,
    myNot,
    myEqual

};

typedef struct ASTNodeType {
   enum NODETYPE type;
   enum OPERATORS operator;
   enum OPERATORS sem_type; //added the semantic type of the symbols
   struct ASTNodeType *s1, *s2, *next;
   struct SymbTab *symbol; //hold an pointer to an entry in the symbol table
   char * name;
   int size;
   char * label;
   
}ASTNode;//

ASTNode * ASTCreateNode(enum NODETYPE DesiredType);
void printSpaces(int num);
void ASTprint(ASTNode *p, int level);
int check_params(ASTNode *f, ASTNode *a); //added to check if the params match when calling a fucntion


#endif
