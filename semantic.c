#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"
#include "symbolTable.h"
#include "parser.tab.h" 
#include "printtree.h"
extern int numErrs, numWarns, Loffset, Goffset;  
extern SymbolTable st;
bool err;
bool initialize = false;
bool NEW_SCOPE = false;
bool inCall = false;
bool inLoop = false;
int loopDepth = 0;
bool Return_FLAG = false;
int bug = 0;
char* currentScope;
bool REDECLARED;


void analyze(TreeNode *tree){
   
   TreeNode *tmp, *tmp2;
   bool fWhile = false; 
   
   while (tree != NULL)
   {
      if(bug) printf("Tree->nodekind: %d\n", tree->nodekind);

      if(tree->nodekind == StmtK){
        if(bug) printf("---Stmt---\n");

         switch (tree->kind.stmt)
         {
         case IfK :
          if(bug)  printf("If [line: %d]\n", tree->lineno);
            analyze(tree->child[0]);
            //exprTypePrint(tree->child[0]->type);

             if(tree->child[0]->type != Bool && !tree->child[0]->isErr){
               printf("ERROR(%d): Expecting Boolean test condition in if statement but got ", tree->lineno);
               exprTypePrint(tree->child[0]->type);
               printf(".\n");
               numErrs++;
            }
            if(tree->child[0]->isArray){
               printf("ERROR(%d): Cannot use array as test condition in if statement.\n", tree->lineno);
               numErrs++;
            }
            analyze(tree->child[1]);
            analyze(tree->child[2]);


            break;
         case NullK :
           if(bug) printf("NULL [line: %d]\n", tree->lineno);
            break;

         case ElsifK :
           if(bug) printf("Elsif [line: %d]\n", tree->lineno);
            analyze(tree->child[0]);


             if(tree->child[0]->type != Bool && !tree->child[0]->isErr){
               printf("ERROR(%d): Expecting Boolean test condition in elsif statement but got ", tree->lineno);
               exprTypePrint(tree->child[0]->type);
               printf(".\n");
               numErrs++;
            }
            if(tree->child[0]->isArray){
               printf("ERROR(%d): Cannot use array as test condition in elsif statement.\n", tree->lineno);
               numErrs++;
            }
            analyze(tree->child[1]);
            analyze(tree->child[2]);

            break;

         case WhileK :
            if(bug) printf("While [line: %d]\n", tree->lineno);
            
            loopDepth++;

            if(tree->child[1] != NULL && tree->child[1]->nodekind == StmtK && tree->child[1]->kind.stmt == CompoundK){
               if(bug) printf("Complex While %d\n", tree->child[1]->lineno);
               st.enter((char*)"WHILE");
               NEW_SCOPE = true;
            }
            else
            {
               if(bug) printf("Simple while %d\n", tree->lineno); 
               st.enter((char*)"simple_While");
            }

            analyze(tree->child[0]);

             if(tree->child[0]->type != Bool && !tree->child[0]->isErr){
               printf("ERROR(%d): Expecting Boolean test condition in while statement but got ", tree->lineno);
               exprTypePrint(tree->child[0]->type);
               printf(".\n");
               numErrs++;
            }
            if(tree->child[0]->isArray){
               printf("ERROR(%d): Cannot use array as test condition in while statement.\n", tree->lineno);
               numErrs++;
            }
            analyze(tree->child[1]);


            if(tree->child[1] != NULL && tree->child[1]->nodekind == StmtK && tree->child[1]->kind.stmt == CompoundK){
               // this is a while with {} so compound handles it
               if(bug) printf("LEAVING Complex While %d\n", tree->child[1]->lineno);
            }
            else
            {  //leave simple while stmt
               if(bug) printf("LEVING WHILE %d\n", tree->lineno);
               st.applyToAll(wasUsed);
               st.leave();
            }

            //printf("Setting to false %d\n", tree->lineno);
            loopDepth--;
            
            break;

         case LoopK :
           if(bug) printf("Loop [line: %d]\n", tree->lineno);
            inLoop = true;
            loopDepth++;

            if(tree->child[2] != NULL && tree->child[2]->nodekind == StmtK && tree->child[2]->kind.stmt == CompoundK){
               // this is a loops with {} so compound handles it
               //printf("Complex loop %d\n", tree->child[1]->lineno);
               if(bug) printf("Complex loop %d\n", tree->child[1]->lineno);
               st.enter((char*)"Loop");
               NEW_SCOPE = true;
            }
            else
            {  //leave simple loop stmt
               if(bug) printf("SImple Loop %d\n", tree->lineno);
               st.enter((char*)"Loop");
               NEW_SCOPE = true;
            }


            analyze(tree->child[0]);   
            
            analyze(tree->child[1]);

            analyze(tree->child[2]);
            
            if(bug)st.print(pointerPrintStr);

            if(tree->child[2] != NULL && tree->child[2]->nodekind == StmtK && tree->child[2]->kind.stmt == CompoundK){
               // this is a while with {} so compound handles it
               //printf("Complex %d\n", tree->child[1]->lineno);
               if(bug) printf("LEAVING Complex Loop %d\n", tree->child[1]->lineno);
            }
            else
            {  //leave simple while stmt
               st.applyToAll(wasUsed);
               st.leave();
            }
            //st.applyToAll(wasUsed);
            //st.leave();
            loopDepth--;
            inLoop = false;
            Loffset++;     //free the tmp loop var

            break;

         case LoopForeverK :
           if(bug) printf("LoopForever [line: %d]\n", tree->lineno);

           loopDepth++;
           inLoop = true;

           analyze(tree->child[1]);
           
           inLoop = false;
           loopDepth--;

            break;

         case CompoundK :
           if(bug) printf("Compound [line: %d]\n", tree->lineno);
            if(!NEW_SCOPE) {
               Loffset = -2;
               st.enter((char*)"compund");
            }
            NEW_SCOPE = false;      
            analyze(tree->child[0]);
            analyze(tree->child[1]);
            //printf("LEAVINGGNG\n");
            if(bug)st.print(pointerPrintStr);
            st.applyToAll(wasUsed);
            st.leave();

            if(inLoop){
               Loffset++; 
            }
            break;

         case RangeK :
           if(bug) printf("Range [line: %d]\n", tree->lineno);
            analyze(tree->child[0]);
            analyze(tree->child[1]);
            analyze(tree->child[2]);

            if(inLoop && (tree->child[0]->isArray || tree->child[1]->isArray || tree->child[2]->isArray)){
               printf("ERROR(%d): Cannot use array in range for loop statement.\n", tree->lineno);
               numErrs++;
            }

            if(inLoop && !tree->child[0]->isErr && (tree->child[0]->type != Integer && tree->child[0]->type != UndefinedType)){
               printf("ERROR(%d): Expecting integer in range for loop statement but got ", tree->lineno);
               exprTypePrint(tree->child[0]->type);
               printf(".\n");
               numErrs++;
            }
            if(inLoop && !tree->child[1]->isErr && (tree->child[1]->type != Integer && tree->child[1]->type != UndefinedType)){
               printf("ERROR(%d): Expecting integer in range for loop statement but got ", tree->lineno);
               exprTypePrint(tree->child[1]->type);
               printf(".\n");
               numErrs++;
            }
            if(inLoop && tree->child[2] != NULL && !tree->child[2]->isErr && (tree->child[2]->type != Integer && tree->child[2]->type != UndefinedType)){
               printf("ERROR(%d): Expecting integer in range for loop statement but got ", tree->lineno);
               exprTypePrint(tree->child[2]->type);
               printf(".\n");
               numErrs++;
            }
            
            
            break;

         case ReturnK :
           if(bug) printf("Return [line: %d]\n", tree->lineno);

            Return_FLAG = true;
            
            analyze(tree->child[0]);    //analyze the child if there is one 
            
            if(bug) printf("CURRETN SCOPE %s\n", currentScope);

            tmp2 = st.lookupNode(currentScope);  

           if(tree->child[0] != NULL && tree->child[0]->nodekind == ExprK && tree->child[0]->kind.expr == IdK){   //if we are returning an ID
              
               

              tmp = st.lookupNode(tree->child[0]->attr.name);
              if(tmp!= NULL && tmp->isArray){ 
                  printf("ERROR(%d): Cannot return an array.\n", tree->lineno);
                  numErrs++;
               }
               else if(tmp2 != NULL && tmp != NULL && tmp2->type != tmp->type && tmp2->type != Void ){
                  printf("ERROR(%d): Function '%s' at line %d is expecting to return ", tree->lineno, currentScope,tmp2->lineno );
                  exprTypePrint(tmp2->type);
                  printf(" but got ");
                  exprTypePrint(tmp->type);
                  printf(".\n");
                  numErrs++;
                  tmp->isUsed = true;
                  tree->type = tmp->type;
               }
           }
           else if( tree->child[0] != NULL && tree->child[0]->type != tmp2->type && tmp2->type != Void){
                  printf("ERROR(%d): Function '%s' at line %d is expecting to return ", tree->lineno, currentScope,tmp2->lineno );
                  exprTypePrint(tmp2->type);
                  printf(" but got ");
                  exprTypePrint(tree->child[0]->type);
                  printf(".\n");
                  numErrs++;
           }

               if(tree->child[0] != NULL && tmp2->type == Void){
                  printf("ERROR(%d): Function '%s' at line %d is expecting no return value, but return has return value.\n", tree->lineno, currentScope, tmp2->lineno);
                  numErrs++;
               }
         
            if(tmp2 != NULL && tmp2->type != Void && tree->child[0] == NULL){
               printf("ERROR(%d): Function '%s' at line %d is expecting to return ", tree->lineno, tmp2->attr.name, tmp2->lineno);
               exprTypePrint(tmp2->type);
               printf(" but return has no return value.\n");
               numErrs++;
            }
            
            //printf("Looking at line %d\n", tree->lineno);
            //if( tree->child[0] != NULL) exprTypePrint(tree->child[0]->type);
            //if(tmp2 != NULL) exprTypePrint(tmp2->type);
            break;

         case BreakK :
           if(bug) printf("Break [line: %d]\n", tree->lineno);

           if( loopDepth == 0){
              printf("ERROR(%d): Cannot have a break statement outside of loop.\n", tree->lineno);
              numErrs++;
            }

            break;

         default:
           if(bug) printf("Unkown Stmt LINE: %d\n", tree->lineno);
            break;
         }
      }

      else if (tree->nodekind == ExprK)
      {
       if(bug) printf("---Expr---\n");  

         switch (tree->kind.expr)
         {
         case OpK:
           if(bug){ printf("Op\n"); TokenPrint(tree->attr.op, ""); printf("\n");}

            analyze(tree->child[0]);
            analyze(tree->child[1]);
            checkType(tree, tree->attr.op);
            
            break;
         
         case ConstantK:        
            if(tree->type == Bool ){
             if(bug)  printf("Const bool line%d\n", tree->lineno);

            }  
            else if(tree->type == CharInt){
              if(bug) printf("Const char line %d\n", tree->lineno);
            }
            else 
            {
              if(bug) printf("Const: %d [line: %d]\n", tree->attr.value, tree->lineno);
              if(bug){exprTypePrint(tree->type); printf("\n");}
              if(tree->kind.expr == IdK){
                 tmp = st.lookupNode(tree->attr.name);
                 if(tmp == NULL){
                    printf("ERROR(%d): Symbol '%s' is not declared.\n", tree->lineno, tree->attr.name);
                    numErrs++;
                    tree->isErr = true;
                 }
              }
            } 
            break;

         case IdK:
           if(bug) printf("Id: %s [line: %d]\n",tree->attr.name, tree->lineno);  

            tmp =  st.lookupNode(tree->attr.name);
            //st.print(pointerPrintStr); 
            if(bug)if(tmp == NULL) printf("ID NOT FOUND\n");
            if(bug && tree->isArray) printf("^ Same ID as ^ %s is array at line %d\n", tree->attr.name, tree->lineno);
            
            if(tmp == NULL){
               //st.print(pointerPrintStr); 
               printf("ERROR(%d): Symbol '%s' is not declared.\n",tree->lineno, tree->attr.name );
               numErrs++;
               tree->isErr = true;
               
               err = true;
            }                   
            if(tmp != NULL && (tmp->kind.decl == VarK || tmp->kind.decl == ParamK)){
               
               //if(1)printf("FOUD a declaration %s %d\n", tmp->attr.name, tmp->isInit);
               
               tree->type = tmp->type;    //sets ID to what it was declared as
               tree->isInit = tmp->isInit;
               tree->isStatic = tmp->isStatic;
               tree->isArray = tmp->isArray;
               
               checkInit(tree, 1);     
            }
            if(tmp != NULL && tmp->kind.decl == FuncK){
               printf("ERROR(%d): Cannot use function '%s' as a variable.\n", tree->lineno, tree->attr.name);
               err = true;
               numErrs++;
               tree->isErr = true;
               tmp->isErr = true;
            }
             
           

            if(tmp != NULL){ //id is declared
               tmp->isUsed = true;

               
               tree->memType = tmp->memType;    //set the current id node (for printing)
               tree->memSize = tmp->memSize;
               tree->offset = tmp->offset;
               if(tmp->isArray){
                  tmp->memSize = tmp->arraySize+1;
               }
            }

            break;

         case AssignK:
           if(bug) printf("Assign [line %d]\n", tree->lineno);
           bool possibleInit;
           

            if(tree->child[0]->kind.expr==IdK) tmp = st.lookupNode(tree->child[0]->attr.name);  //An ID

            if(tree->child[0]->kind.expr == OpK && tree->child[0]->child[0]->kind.expr == IdK) {   //An array
               tmp = st.lookupNode(tree->child[0]->child[0]->attr.name);            
            }

            if(tmp != NULL) possibleInit  = tmp->isInit;       // Hold the var if the found ID is init or not

            tree->child[0]->isInit = true;
            if(tmp != NULL) tmp->isInit = true;
            analyze(tree->child[0]);            //when we are looking at child 0, its inherently initilized
      
            tree->child[0]->isInit = possibleInit;     // If/ when the left ID is used on itself, it must be whatever init state it was before we just initilized it (possibly again)
            if(tmp != NULL) {tmp->isInit = possibleInit;}

            
            analyze(tree->child[1]);                  // x= x+3; x is not init until after we process child 1

            tree->child[0]->isInit = true;      // now it is deffinitly initilized
            if(tmp != NULL) tmp->isInit = true;                 //Set the declared node to init

            checkType(tree, tree->attr.op);
            tree->type = tree->child[0]->type;
            
            break;

         case CallK:
           if(bug) printf("Call: %s [line: %d]\n", tree->attr.name, tree->lineno);
            //st.print(pointerPrintStr);
            
            tmp = st.lookupNode(tree->attr.name);
            if(tmp != NULL){
               tree->type = tmp->type;
               if(tmp->kind.decl == VarK || tmp->kind.decl == ParamK){
                  printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n", tree->lineno, tree->attr.name);
                  tree->isErr = true;
                  numErrs++;
               }
               
            } 
            else
            {
               printf("ERROR(%d): Symbol '%s' is not declared.\n", tree->lineno, tree->attr.name);
               numErrs++;
               tree->isErr = true;
               err = true;
            } 

            analyze(tree->child[0]);

            if(!tree->isErr) compareParams(tree);     //Done after we process the call params aka child 0

            if(tmp != NULL) tmp->isUsed = true;

            break;

         default:
           if(bug) printf("Unknown ExpK LINE %d\n", tree->lineno);
            break;
         }
      }
      else if (tree->nodekind == DeclK){
         if(bug) printf("---Declk--- %s\n", tree->attr.name);
         //printf("THE NAME %s\n", tree->TD->Token_Str);
         if(tree->isArray){
            if(tree->TD != NULL){
               if(bug)printf("DEClK is array and TD is NOT NULL\n");
               tmp = (TreeNode*) st.lookupSingle(tree->TD->Token_Str);
               if(tmp != NULL) allreadyDeclared(tree, tree->TD->Token_Str, tmp->lineno);
            } 
            else
            {  
               if(bug)printf("DEClK is array NULL\n");
               tmp =(TreeNode*) st.lookupSingle(tree->attr.name);
               if(tmp != NULL) {allreadyDeclared(tree,tree->attr.name, tmp->lineno);}
            }  
         }
         else
         {
            
            tmp = (TreeNode*) st.lookupSingle(tree->attr.name);      //Look up single bc provided lookup function is broken and returns true if found in global.
            
            if(tmp != NULL) {
               allreadyDeclared(tree,tree->attr.name, tmp->lineno);
            }
         }
         
          //st.print(pointerPrintStr);  
         switch (tree->kind.decl){
            case FuncK:
             if(bug)  printf("Func %s line %d \n", tree->attr.name, tree->lineno );

               countPerams(tree);               //Set number of parameters

               tmp = st.lookupNode(tree->attr.name);
               
               if(tmp == NULL) {st.insert(tree->attr.name, (TreeNode*) tree); }
               if(strcmp("main", tree->attr.name) == 0){
                  //printf("Main found!\n");
                  tree->isUsed = true;
               }
                  st.enter(tree->attr.name);
                  NEW_SCOPE = true; 
                  currentScope = strdup(tree->attr.name); 
                  Return_FLAG = false;
               //printf("ENTERED\n");
               tree->offset = 0;  
               Loffset = -2;                 //Set the offset before looking at children
               analyze(tree->child[0]);    //compound stmt will handle any param
               analyze(tree->child[1]); 
               if(!Return_FLAG && tree->type != Void){
                  printf("WARNING(%d): Expecting to return ", tree->lineno);
                  exprTypePrint(tree->type);
                  printf(" but function '%s' has no return statement.\n", tree->attr.name);
                  numWarns++;
               }
               if(tree->child[1] == NULL){
                  //printf("CHild 1 is null in funck %d\n", tree->lineno);
                  st.applyToAll(wasUsed);
                  st.leave();
               }
               
               tree->memType = Global;
               tree->memSize = 1;
               
                   //space for other info
               
               //st.print(pointerPrintStr);            
               //printf("LEVING\n");
               break;

            case VarK:
               //printf("VAR static %d\n", tree->isStatic);
               if(tree->child[0] != NULL){
                  analyze(tree->child[0]);

                  if( tree->child[0]->type != tree->type){
                     printf("ERROR(%d): Variable '%s' is of ", tree->lineno, tree->attr.name);
                     exprTypePrint(tree->type);
                     printf(" but is being initialized with an expression of ");
                     exprTypePrint(tree->child[0]->type);
                     printf(".\n");
                     numErrs++;
                  }
                  if(tree->child[0]->kind.expr == IdK){
                     printf("ERROR(%d): Initializer for variable '%s' is not a constant expression.\n", tree->lineno, tree->attr.name);
                     numErrs++;
                  }
                  tree->isInit = true;
               }       

               if (tree->isArray == true){
                  if(bug)   printf("Var %s is array line %d \n", tree->TD->Token_Str, tree->lineno );   
                  st.insert(tree->TD->Token_Str, (TreeNode*) tree); 
                  //printf("Size %d\n", tree->arraySize);
                  tree->memSize = tree->arraySize+1;     //mem mgmt
                  tree->offset = Loffset-1;     //the offset is where the array starts and justbefore it is the size
                  Loffset = Loffset - tree->arraySize-1; //memory is +1 from the size
               }
               else
               {
                if(bug)  printf("Var %s line %d \n", tree->attr.name, tree->lineno ); //   
                  st.insert(tree->attr.name, (TreeNode*) tree); 
                  tree->memSize = 1;
                  tree->offset = Loffset--;
               }
   
               //printf("DEPTH %d ver %s\n", st.depth(), tree->attr.name);
              
               if(st.depth() == 1){        // Global
                  tree->isInit = true;     // B/c globablas are always init?
                  tree->memType = Global;
                  tree->offset = Goffset--;
                  if(tree->isArray && !REDECLARED){
                     Loffset = Loffset + tree->arraySize; //if its global, the local scope may not matter b/c i set it to 0 every time
                     tree->offset = Goffset--;
                     Goffset = Goffset - tree->arraySize+1; //mem of array is +1 of its size;
                  }
               }
               else
               {
                  if(tree->isStatic){
                     tree->memType = LocalStatic;
                     tree->offset = Goffset--;
                     Loffset++;  // static is technically global

                     if(tree->isArray){
                        tree->offset = Goffset--;
                        Goffset = Goffset - tree->arraySize+1;
                        Loffset = Loffset + tree->arraySize; //if its global, the local scope may not matter b/c i set it to 0 every time
                     }
                  }
                  else
                  {
                     tree->memType = Local;
                  }  
               }
               
               if(REDECLARED  && tree->memType == Local){
                  Loffset++;
                  tree->offset = 0;
                  REDECLARED = false;
               }
               if(REDECLARED && (tree->memType == Global || tree->memType == LocalStatic)) {
                  Goffset++;
                  tree->offset = 0;
                  REDECLARED = false;
               }
               break;

            case ParamK:

               tmp = st.lookupNode(tree->attr.name);
               tree->isInit = true;
               if(tree->isArray){    

                if(bug)  printf("Param %s is array line %d  \n", tree->attr.name, tree->lineno);  

                  if(tmp != NULL){
                     //allreadyDeclared(tree, tmp->lineno); //checked before entering switch stmt
                  }
                  else
                  {
                     st.insert(tree->attr.name, (TreeNode*) tree);
                     
                  }
                  tree->memType = Parameter; 
               }
               else{
                  if(bug)  printf("Param %s line %d \n", tree->attr.name, tree->lineno);

                  st.insert(tree->attr.name, (TreeNode*) tree);
                  tree->memType = Parameter;
               }

               tree->memSize = 1;
               tree->offset = Loffset--;

               if(REDECLARED){
                  Loffset++;
                  tree->offset = 0;
                  REDECLARED = false;
               }

               break;

            default:
               printf("PROBLEM! Unknown DecK LINE %d\n", tree->lineno);
               break;
         }
      }
      else
      {
         printf("BIG PROBLEM! Unknown node type: %d LINE %d\n", tree->nodekind, tree->lineno);
      }

      tree = tree->sibling;      
   }

}

//-----------------------------------------------------------------------------------------

void checkType(TreeNode *tree, OpKind token ){

TreeNode *left, * right, *tmp;
if(tree->child[0] != NULL) left = tree->child[0];
if(tree->child[1] != NULL) right = tree->child[1];

   switch (token){
      
      case GRET :
      case LESS :
      case GRETEQ :
      case LESSEQ :
         // if(left != NULL) checkInit(left, 0);
         // if(right!= NULL ) checkInit(right, 1);
            // printf("' looking for lhs is of ");
            // exprTypePrint(right->type);
            // printf(" %d\n", tree->lineno);
         if(left->type != Integer && left->type != Char && left->type != UndefinedType){
            //printf("NAME %s type %d \n", tree->child[0]->attr.name, tree->child[0]->type);
            printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of type char or type int but lhs is of ");
            exprTypePrint(left->type);
            printf(".\n");
            //printf("Left %s \n", tree->child[0]->attr.name);
            numErrs++;
            left->isErr = true;
         }
          if(right->type != Integer && right->type != Char && right->type != UndefinedType){
            //printf("NAME %s type %d \n", tree->child[0]->attr.name, tree->child[0]->type);
            printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of type char or type int but rhs is of ");
            exprTypePrint(right->type);
            printf(".\n");
            //printf("Left %s \n", tree->child[0]->attr.name);
            numErrs++;
            right->isErr = true;
         }

         else if(left->type != right->type && left->type != UndefinedType && right->type != UndefinedType ){
            //printf("NAME %s type %d \n", tree->child[0]->attr.name, tree->child[0]->type);
            printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of the same type but lhs is ");
            exprTypePrint(tree->child[0]->type);
            printf(" and rhs is ");
            exprTypePrint(tree->child[1]->type);
            printf(".\n");
            //printf("Left %s \n", tree->child[0]->attr.name);
            numErrs++;
         }
         notWithArrays(tree);
   break;

      case EQ: 
         if(left->kind.expr==IdK) tmp = st.lookupNode(left->attr.name);
         if(tmp != NULL) tmp->isInit = true;
         tree->type = left->type;
         left->isInit = true;    //being on the left of an equal inits it

      case EQEQ:
      case NOTEQ:

         // if(left != NULL) checkInit(left, 0);
         // if(right!= NULL ) checkInit(right,1);         
//printf("Tyep %d and %d line %d\n", left->type, right->type, tree->lineno);
         if(left->type != right->type && left->type != UndefinedType && right->type != UndefinedType && left->type != Void && right->type != Void){
            
            //printf("NAME %s type %d \n", tree->child[0]->attr.name, tree->child[0]->type);
            printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of the same type but lhs is ");
            exprTypePrint(left->type);
            printf(" and rhs is ");
            exprTypePrint(right->type);
            printf(".\n");
            //printf("Left %s \n", tree->child[0]->attr.name);
            numErrs++;
            tree->isErr = true;
         }
         else if(left->type != Integer && left->type != Char && left->type != Bool && left->type != UndefinedType){
            //printf("NAME %s type %d \n", tree->child[0]->attr.name, tree->child[0]->type);
            printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of type bool, char, or int but lhs is of  ");
            exprTypePrint(left->type);
            printf(".\n");
            //printf("Left %s \n", tree->child[0]->attr.name);
            numErrs++;
            left->isErr = true;
         }
        else  if(right->type != Integer && right->type != Char && right->type != Bool && right->type != UndefinedType){
            //printf("NAME %s type %d \n", tree->child[0]->attr.name, tree->child[0]->type);
            printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of type bool, char, or int but rhs is of ");
            exprTypePrint(right->type);
            printf(".\n");
            //printf("Left %s \n", tree->child[0]->attr.name);
            numErrs++;
            right->isErr = true;
         }
         err = false;
         

   break;

      case AND:
      case OR :
         // if(left != NULL) checkInit(left, 0);
         // if(right!= NULL ) checkInit(right,1);
         if(left->type != Bool && left->type != UndefinedType){
            printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of type bool but lhs is of ");
            exprTypePrint(left->type);
            printf(".\n");
            numErrs++;
         }
          if(right->type != Bool && right->type != UndefinedType){
            printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of type bool but rhs is of ");
            exprTypePrint(right->type);
            printf(".\n");
            numErrs++;
         }
      notWithArrays(tree);
break;

      case NOT:
         
         if(left->kind.expr == IdK){
            tmp = st.lookupNode(left->attr.name);
            if(tmp != NULL && tmp->type != Bool){
               unaryError(tree, (char*)"bool");
            }
         }
         else if(left->type != Bool){
            unaryError(tree, (char*)"bool");
         }
         notWithArrays(tree);
      
break;

      case ADDASS :
      case SUBASS :
      case MULASS :
      case DIVASS :

         if(left != NULL && left->kind.expr == IdK){
            tmp = st.lookupNode(left->attr.name);
            if(tmp != NULL) tmp->isInit = true;        
         }  
         tree->type = left->type;
         left->isInit = true;    //being on the left of an equal inits it

         left->isInit = true;                    //For += -= /= *=
         // if(right!= NULL ) checkInit(right, 1);

         typeInts(tree);

break;

      case DIV :
      case PLUS :
      case PERCENT :

      

      // if(left != NULL) checkInit(left, 0);
      // if(right!= NULL ) checkInit(right, 1);
       

      //if(tree->child[0]->attr.name != NULL); tmp =  st.lookupNode(tree->child[0]->attr.name);
      typeInts(tree);
      notWithArrays(tree);  
         break;

      case DEC :
      case INC :
      case QMARK : 
      notWithArrays(tree);  
      if(left->type != Integer){
         unaryError(tree, (char *) "int");
      } 
      
break;

      case MINUS : 

         if(left->kind.expr == IdK){
            tmp = st.lookupNode(left->attr.name);
            if(tmp != NULL && tmp->type != Integer){
               unaryError(tree, (char*)"int");
            }
         }
         else if(left->type != Integer){
            unaryError(tree, (char*)"int");
         }

         

      notWithArrays(tree);  


      case MULTIPLY :

      if(tree->unary && token == MULTIPLY){ if(bug) printf("UNARY %d\n", tree->lineno); onlyArrays(tree);}

      if(!tree->unary) typeInts(tree);

      if(bug) printf("MIN MUL %d\n", tree->lineno);
      // if(left != NULL && !tree->unary) checkInit(left, 0);
      // if(right!= NULL && !tree->unary) checkInit(right, 1);
      
break;

      case LIndex :
         //printf("L: %s R: %s\n", tree->child[0]->attr.name, tree->child[1]->attr.name );
         dealWithArrays(tree);
break;
   
      default:
         printf("Error! in printing token %d\n", token);
         break;
   }
}

void checkInit(TreeNode *tree, int side){
   //if(err)printf("ERR %d \n", tree->lineno);
   TreeNode *tmp;
   //printf("nodekind %d static %d line %d\n", tree->nodekind, tree->isStatic, tree->lineno); 
    if(tree != NULL && tree->nodekind == ExprK && !tree->isErr  ){
       
         if( tree->kind.expr == IdK && !tree->isStatic){
            tmp = st.lookupNode(tree->attr.name);
            //printf("nodekind after search %d static %d line %d\n", tmp->nodekind, tmp->isStatic, tree->lineno); 
            if(!tree->isInit && !tree->isArray && side == 1 ){
               
               printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->lineno, tree->attr.name);
               numWarns++;    
               tree->isInit = true;
               tmp->isInit = true;
               err = true;
            }
            if(!tree->isInit && tree->isArray && side == 1){
               tmp = st.lookupNode(tree->attr.name);
               printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->lineno, tree->attr.name);
               numWarns++;    
               tree->isInit = true; 
               tmp->isInit = true;
               err = true;
            }
         }
         if(tree->kind.expr == OpK){
            if(bug) printf("Its an OPERATOR line %d ", tree->lineno);
            if(bug){TokenPrint(tree->attr.op, ""); printf(" \n");}

            if(tree->child[0] != NULL && tree->attr.op == LIndex && tree->child[0]->kind.expr == IdK){
               tmp = st.lookupNode(tree->child[0]->attr.name);
               if( tmp != NULL ){
                  tree->child[0]->isInit = tmp->isInit;
               }
            }



            if(side == 1 && (tree->attr.op == LIndex ) && tmp!= NULL && !tmp->isInit){
               printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->lineno, tree->child[0]->attr.name);
               numWarns++;    
               tree->isInit = true;
               tree->child[0]->isInit = true;
               tmp->isInit = true;
               err = true;     
            }
         }
   }   
}

void typeInts(TreeNode *tree){
   TreeNode *left, *right;
   left = tree->child[0];
   right = tree->child[1];

      if(left != NULL && left->type!= Integer && left->type != UndefinedType){
         printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of type int but lhs is of ");
            exprTypePrint(left->type);
            printf(".\n");
            numErrs++;
      }
      if(right != NULL && right->type!= Integer && right->type != UndefinedType){
         printf("ERROR(%d): '",tree->lineno );
            TokenPrint(tree->attr.op, "");
            printf("' requires operands of type int but rhs is of ");
            exprTypePrint(right->type);
            printf(".\n");
            numErrs++;
      }
}

void wasUsed(std::string sym, void *ptr){
   if(bug)printf("APPLIED TO ALL: %s\n", sym.c_str());

   TreeNode *tmp;
   tmp = st.lookupNode(sym);
   //st.print(pointerPrintStr);
   if(tmp != NULL){
      if(!tmp->isUsed ){
         printf("WARNING(%d): The ", tmp->lineno);
         if(tmp->kind.decl == ParamK) printf("parameter");
         if(tmp->kind.decl == VarK) printf("variable");
         if(tmp->kind.decl == FuncK) printf("function");
         printf(" '%s' seems not to be used.\n", sym.c_str());
         numWarns++;
      }
   }
}


void dealWithArrays(TreeNode *tree){
   // printf("ARRAY SPOTED AND BEING DELT WITH %d\n", tree->lineno);
   TreeNode *ch1 = NULL, *ch2 = NULL;

   ch1 = tree->child[0];
   ch2 = tree->child[1];

   if(tree->child[0]->kind.expr == IdK){
      //printf("L child is id: %s\n", tree->child[0]->attr.name);
      ch1 = st.lookupNode(tree->child[0]->attr.name);
      if( ch1 != NULL){    
         //printf("SETTING TYPES");
         tree->child[0]->type = ch1->type;
         tree->type = ch1->type;
      }

     if( ch1 != NULL && (!ch1->isArray && !ch1->isErr) ){
      
        printf("ERROR(%d): Cannot index nonarray '%s'.\n", tree->lineno, tree->child[0]->attr.name );
        numErrs++;
        err = true;
        tree->isErr = true;
     }
   }
   else
   {
      printf("ERROR(%d): Cannot index nonarray.\n", tree->lineno);
      numErrs++;
      err = true;
      tree->isErr = true;
   }
   if(tree->child[1] != NULL){
      if(tree->child[1]->type != Integer && tree->child[0]->kind.expr == IdK  && tree->child[1]->type != UndefinedType){
         printf("ERROR(%d): Array '%s' should be indexed by type int but got ", tree->lineno, tree->child[0]->attr.name);
         exprTypePrint(tree->child[1]->type);
         printf(".\n");
         tree->isErr = true;
         numErrs++;
      }
   }
   if(tree->child[1] != NULL && tree->child[1]->kind.expr == IdK){
      ch2 = st.lookupNode(tree->child[1]->attr.name);

      if(ch2 != NULL && ch2->isArray == true){
         printf("ERROR(%d): Array index is the unindexed array '%s'.\n", tree->lineno, ch2->TD->Token_Str);
         tree->isErr = true;
         numErrs++;
      } 
      if(ch2 != NULL ) {
         tree->type = ch2->type;
         tree->child[1]->type = ch2->type;
      }    
   }


   tree->isArray = true;
}

void onlyArrays(TreeNode* tree){
   TreeNode *tmp;

   if(tree->child[1] == NULL){
      tmp = tree->child[0];
      if(tmp->kind.expr == IdK || tmp->kind.expr == CallK){
         tmp = st.lookupNode(tmp->attr.name);
         if( tmp != NULL && !tmp->isArray){
            printf("ERROR(%d): The operation '",tree->lineno);
            TokenPrint(tree->attr.op, "");
            printf("' only works with arrays.\n");
            tree->isErr = true;
            numErrs++;
         }
      }
      else if(tree->child[0]->kind.expr != IdK)
      {
            printf("ERROR(%d): The operation '",tree->lineno);
            TokenPrint(tree->attr.op, "");
            printf("' only works with arrays.\n");
            tree->isErr = true;
            numErrs++;
      }
      
   }
}

void allreadyDeclared(TreeNode *tree, char* sym, int line){
        
   printf("ERROR(%d): Symbol '%s' is already declared at line %d.\n",tree->lineno, sym, line);
   numErrs++;
   err = true; 
   tree->isErr = true;
   REDECLARED = true;             
}

void unaryError(TreeNode *tree, char* expected){
   printf("ERROR(%d): Unary '", tree->lineno);
   TokenPrint(tree->attr.op, "");
   printf("' requires an operand of type %s but was given ", expected);
   exprTypePrint(tree->child[0]->type);
   printf(".\n");
   tree->isErr = true;
   numErrs++;
}

void notWithArrays(TreeNode * tree){
   TreeNode *tmp; 
   tmp = tree->child[0];
   if(tmp != NULL){   
      if(tmp->kind.expr == IdK)
      {
         tmp = st.lookupNode(tmp->attr.name);

         if(tmp != NULL && tmp->isArray){
            printf ("ERROR(%d): The operation '", tree->lineno);
            TokenPrint(tree->attr.op, "");
            printf("' does not work with arrays.\n");
            numErrs++;
            tree->isErr = true;
         }
         else
         {
            tmp = tree->child[1];
            if(tmp != NULL && tmp->kind.expr == IdK){
               tmp = st.lookupNode(tmp->attr.name);
               if(tmp != NULL && tmp->isArray){
                  printf ("ERROR(%d): The operation '", tree->lineno);
                  TokenPrint(tree->attr.op, "");
                  printf("' does not work with arrays.\n");
                  numErrs++;
                  tree->isErr = true;
               }
            }
         }   
      }
   }
   else if(tree->child[1] != NULL){
      tmp = tree->child[1];
      printf("CHEK right child %d\n", tree->lineno);
      if(tmp->kind.expr == IdK){
         tmp = st.lookupNode(tmp->attr.name);
         if(tmp != NULL && tmp->isArray && !tmp->isErr){
            printf ("ERROR(%d): The operation '", tree->lineno);
            TokenPrint(tree->attr.op, "");
            printf("' does not work with arrays.\n");
            numErrs++;
            tree->isErr = true;
         }         
      }
   }
}



