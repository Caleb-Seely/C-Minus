#ifndef SEMANTIC
#define SEMANTIC
#include "printtree.h"
#include "ScanType.h"
#include "symbolTable.h"
void spaces(int n);
void analyze(TreeNode *tree);
void checkType(TreeNode *tree, OpKind token); 
void checkInit(TreeNode *tree, int side);
void wasUsed(std::string sym, void *ptr);
void dealWithArrays(TreeNode *tree);
void allreadyDeclared(TreeNode *tree, char* sym, int line);
void notWithArrays(TreeNode *tree);
void unaryError(TreeNode *tree, char* expected);
void onlyArrays(TreeNode *tree);
void typeInts(TreeNode *tree);

#endif