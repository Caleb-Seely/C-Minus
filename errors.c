#include <string.h>
#include "semantic.h"
extern SymbolTable st;
extern int numErrs;

void countPerams(TreeNode *tree){
   //printf("Counting\n");
   int count = 0;
   TreeNode *tmp = NULL;
   tmp = tree->child[0];
   
      while (tmp != NULL)  
      {
         count++;
         tmp = tmp->sibling;
      }

      //printf("NUm of sibs is %d\n", count);

      tree->numParams = count;
      //printf("COUNT IS %d for %s\n", count, tree->attr.name);
      if(strcmp("main", tree->attr.name) == 0){
         //printf("MAIN FOUND \n");
         tree->numParams = 0;             //main takes no parameters
      }
}

void compareParams(TreeNode *tree){
   TreeNode *def = NULL, *params;
   int count = 0, dec_line = 0, dec_count;
   bool isIo = false;
   //printf("Comparing params %s\n", tree->attr.name);
   def = st.lookupNode(tree->attr.name);        //def now points to the declared function def

   
   if(def != NULL){
      //printf("Comparing params %s\n", def->attr.name);
      dec_line = def->lineno;
      dec_count = def->numParams;
      isIo = def->isIOControl;         //IO can have unlimited params
   }
   //count and check types
   params = tree->child[0];      //the call parameters
   def = def->child[0];          //the defined parameters 

   // if(params == NULL) printf("Param NUll\n");
   // if(def == NULL) printf("%s NUll\n", tree->attr.name);
   //if(params != NULL && def == NULL) count++;      //when the func def has no params, its child is null and so type are never checked
   //check types                                     and count doesn't account for if the call has params.
   while (params != NULL && def != NULL)
   {
      count++;
      if(def->isArray && !params->isArray){
         printf("ERROR(%d): Expecting array in parameter %i of call to '%s' declared on line %d.\n", tree->lineno, count, tree->attr.name, dec_line );
         numErrs++;
      }
      else if(!def->isArray && (params->isArray && params->child[0] == NULL )) //if child is not null, then we are sending the index of the array, not the array itself 
      {
         printf("ERROR(%d): Not expecting array in parameter %i of call to '%s' declared on line %d.\n" ,tree->lineno, count, tree->attr.name, dec_line );
         numErrs++;
      }
      
       if(def->type != params->type &&(params->type != UndefinedType)){
         printf("ERROR(%d): Expecting ", tree->lineno);
         exprTypePrint(def->type);
         printf(" in parameter %i of call to '%s' declared on line %d but got ", count, tree->attr.name, dec_line);
         exprTypePrint(params->type);
         printf(".\n");
         numErrs++;
      }

      params = params->sibling;
      def = def->sibling;

   }

   if(params != NULL) count++;   //when the call param != dec param #, this offsets the count

   //printf("TOTALS dec %d call %d LINE %d\n", dec_count, count, tree->lineno);
   //check equal number of params
   if(count > dec_count && !isIo){
      printf("ERROR(%d): Too many parameters passed for function '%s' declared on line %d.\n", tree->lineno, tree->attr.name, dec_line);
      numErrs++;
   }
   if(count < dec_count && !isIo){
      printf("ERROR(%d): Too few parameters passed for function '%s' declared on line %d.\n", tree->lineno, tree->attr.name, dec_line);
      numErrs++;
   }
}