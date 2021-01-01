#include <string.h>
#include "IO.h"
#include "symbolTable.h"
#include "printtree.h"

extern SymbolTable st;

void  prototype(){
   TreeNode *tmp;

   tmp = newDecNode(FuncK, -1);
   tmp->isUsed = true;
   tmp->isIOControl = true;
   tmp->attr.name = strdup("output");
   tmp->type = Integer;
   st.insert(tmp->attr.name, (TreeNode *) tmp);

   tmp = newDecNode(FuncK, -1);
   tmp->isUsed = true;
   tmp->isIOControl = true;
   tmp->attr.name = strdup("outputb");  
   tmp->type = Bool; 
   st.insert(tmp->attr.name, (TreeNode *) tmp);

   tmp = newDecNode(FuncK, -1);
   tmp->isUsed = true;
   tmp->isIOControl = true;
   tmp->attr.name = strdup("outputc");   
   tmp->type = Char;
   st.insert(tmp->attr.name, (TreeNode *) tmp);

   tmp = newDecNode(FuncK, -1);
   tmp->isUsed = true;
   tmp->isIOControl = true;
   tmp->attr.name = strdup("input");   
   tmp->type = Integer;
   st.insert(tmp->attr.name, (TreeNode *) tmp);

   tmp = newDecNode(FuncK, -1);
   tmp->isUsed = true;
   tmp->isIOControl = true;
   tmp->attr.name = strdup("inputc");  
   tmp->type = Char; 
   st.insert(tmp->attr.name, (TreeNode *) tmp);

   tmp = newDecNode(FuncK, -1);
   tmp->isUsed = true;
   tmp->isIOControl = true;
   tmp->attr.name = strdup("inputb");  
   tmp->type = Bool; 
   st.insert(tmp->attr.name, (TreeNode *) tmp);

   tmp = newDecNode(FuncK, -1);
   tmp->isUsed = true;
   tmp->isIOControl = true;
   tmp->attr.name = strdup("outnl");   
   st.insert(tmp->attr.name, (TreeNode *) tmp);
}