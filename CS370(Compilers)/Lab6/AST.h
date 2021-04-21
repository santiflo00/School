/*Santiago Flores
 * March 28, 2020
 * Lab6 Abstract Syntax tree
 * FILE AST.h
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
    mybool
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
    boolType,
    voidType,
    intType,
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
   struct ASTNodeType *s1, *s2, *next;
   char * name;
   int size;
   
    
}ASTNode;//

ASTNode * ASTCreateNode(enum NODETYPE DesiredType);
void printSpaces(int num);
void ASTprint(ASTNode *p, int level);



#endif
