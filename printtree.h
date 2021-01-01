#ifndef PRINT_TREE
#define PRINT_TREE

#include <stdbool.h> 
#include "ScanType.h"

extern int yylineno;
typedef int OpKind;
extern bool PAST;

typedef enum {DeclK, StmtK, ExprK} NodeKind;
typedef enum {FuncK, VarK, ParamK} DeclKind;
typedef enum {NullK, ElsifK, IfK, WhileK, LoopK, LoopForeverK, CompoundK, RangeK, ReturnK, BreakK} StmtKind;
typedef enum {OpK, ConstantK, IdK, AssignK, InitK, CallK} ExpKind;      //InitK is never used in Grammar
typedef enum {Void, Integer, Bool, Char, CharInt, Equal, UndefinedType, Static} ExpType;
static const char * EnumStrings[] = { "void", "int", "bool","char", "char", "ERR", "Undefined Type" };
typedef enum {None, Local, Global, Parameter, LocalStatic} VarKind;     //Not used yet



#define  MAXCHILDREN 3   

typedef struct treeNode
{
    // connectivity in the tree
   struct treeNode *child[MAXCHILDREN];   // children of the node
   struct treeNode *sibling;              // siblings for the node

    // what kind of node
   int lineno;                            // linenum relevant to this node
   NodeKind nodekind;                     // type of node
   TokenData *TD;

    union                               // subtype of type
    {
      DeclKind decl;                     // used when DeclK
      StmtKind stmt;                     // used when StmtK
      ExpKind expr;                       // used when ExpK
    }kind;
    
    // extra properties about the node depending on type of the node
    union                                  // relevant data to type -> attr
    {
      OpKind op;                         // type of token (same as in bison)
	   int value;                         // used when an integer constant or boolean
      unsigned char cvalue ;              // used when a character
	   char *string;                      // used when a string constant
	   char *name ;                        // used when IdK
    }attr;   

    ExpType type;		           // used when ExpK for type checking
    VarKind vType;                        //Variable type 
    bool isArray;                          // is this an array
      int arraySize;                         //Size of array
    bool isStatic;                         // is staticly allocated?
    bool isInit;                           //var is initilized 
    bool isUsed;                          //var is used
    bool unary;
    bool isErr;

    // even more semantic stuff will go here in later assignments.
} TreeNode;

TreeNode *newStmtNode(StmtKind kind, int lineNo);
TreeNode *newExpNode(ExpKind kind, int lineNo);
TreeNode *newDecNode(DeclKind kind, int lineNo);
TreeNode *addSibling(TreeNode *t, TreeNode *s);

void typeToSibs(TreeNode *t, ExpType typ);
void TreePrint(TreeNode *t, int sib);
void TokenPrint(OpKind token, const char *tokenString);
void exprTypePrint(ExpType t);
void spcaes(int n);



#endif