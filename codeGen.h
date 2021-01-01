#ifndef CODEGEN
#define CODEGEN

#include "emitcode.h"
#include "printtree.h"
#include "ScanType.h"
#include "symbolTable.h"
extern int emitLoc;
void IOSetup(TreeNode* tree);
void treeCode(TreeNode* tree);
void init();
void opCode(TreeNode* tree);
int frame(treeNode* tree);

#endif