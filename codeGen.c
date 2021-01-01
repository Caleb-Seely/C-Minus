#include <string.h>
#include<time.h>
#include "codeGen.h"
#include "emitcode.h"
#include "parser.tab.h" 
extern SymbolTable st;
bool Globals = false;
extern int Goffset;
int endOfFrame;
bool cc = false;
int broke = 0;
void treeCode(TreeNode* tree){
   char* name;
   int dif, cur, dif2;
   int breakloc, skiploc;
   
   TreeNode *tmp = NULL;
   if(tree == NULL){
      if(cc) printf("TREE PRINTING IS NULL\n");
   } 

   while (tree != NULL)
   {
      if(cc) printf("Line %d\n", tree->lineno);
            
      if(tree->nodekind == StmtK){

          if(cc) printf("---Stmt---\n");
         switch (tree->kind.stmt)
         {
            case IfK :
               if(cc)printf("If \n");
               emitComment((char*)"If");
               treeCode(tree->child[0]);
               
               dif = emitSkip(1);

               treeCode(tree->child[1]);
               
               if(tree->child[2] != NULL){
                  dif2 = emitSkip(1);
                  backPatchAJumpToHere((char*)"JZR", 3, dif,(char*)"Jump to Loop"); 
                  

                  treeCode(tree->child[2]); 
                  backPatchAJumpToHere( dif2,(char*)"Then part");
               }
               else
               {
                  backPatchAJumpToHere((char*)"JZR", 3, dif,(char*)"Jump to Loop"); 
               }
               
               

               
               //emitRM((char *)"JZR", AC, 1, PC, (char *)"Jump Zero");

               //
               
               break;
            case NullK :
               printf("NULL \n");
               emitComment((char*)"NULL");
               break;

            case ElsifK :
               printf("Elsif \n");
               emitComment((char*)"Elseif");
               treeCode(tree->child[0]);
               
               dif = emitSkip(1);

               treeCode(tree->child[1]);
               
               if(tree->child[2] != NULL){
                  dif2 = emitSkip(1);
                  backPatchAJumpToHere((char*)"JZR", 3, dif,(char*)"Jump to Loop"); 
                  

                  treeCode(tree->child[2]); 
                  backPatchAJumpToHere( dif2,(char*)"Then part");
               }
               else
               {
                  backPatchAJumpToHere((char*)"JZR", 3, dif,(char*)"Jump to Loop"); 
               }

               
               break;

            case WhileK :
               if(cc) printf("While \n");
               emitComment((char*)"While");
               cur = emitSkip(0);
               
               treeCode(tree->child[0]);
               
               emitRM((char *)"JNZ", AC, 1, PC, (char *)"Jump to While body");
               dif = emitSkip(1);
               treeCode(tree->child[1]);
               emitGotoAbs(cur, (char *)"go to beginning of loop");
               backPatchAJumpToHere(dif,(char*)"Jump past Loop"); 
               //dif = cur-dif;          
               break;

            case LoopK :
               if(cc) printf("Loop \n");
               emitComment((char*)"Loop");
               endOfFrame = endOfFrame-3;
               tmp = tree->child[0];              // get pointer to Treenode for loop index variable

               {     //Process the reange node
                  TreeNode *rangenode;

                  rangenode = tree->child[1];
                  treeCode(rangenode->child[0]);
                  emitRM((char *)"ST", AC, tmp->offset, FP, (char *)"save starting value in index variable");
                  treeCode(rangenode->child[1]);
                  emitRM((char *)"ST", AC, tmp->offset-1, FP, (char *)"save ending value");
                  treeCode(rangenode->child[2]);
                  emitRM((char *)"ST", AC, tmp->offset-2, FP, (char *)"save increment values");
               }

               cur = emitSkip(0);                      // return to here to do the test
               
               // increment can be + or -
               emitRM((char *)"LD", AC1, tmp->offset, FP, (char *)"loop index");
               emitRM((char *)"LD", AC2, tmp->offset-1, FP, (char *)"ending value");
               emitRM((char *)"LD", AC, tmp->offset-2, FP, (char *)"increment value");
               emitRO((char *)"SLT", AC, AC1, AC2, (char *)"Op <");
               emitRM((char *)"JNZ", AC, 1, PC, (char *)"Jump to loop body");               

               skiploc = breakloc;                 // save the old break statement return point
               breakloc = emitSkip(1);             // addr of instr that jumps to end of loop
                                                   // this is also the backpatch point
              
              treeCode(tree->child[2]);         // do body of loop
              
                  // do increment stuff
               emitComment((char *)"LOOP INC AND JMP");
               emitRM((char *)"LD", AC, tmp->offset, FP, (char *)"Load index");
               emitRM((char *)"LD", AC2, tmp->offset-2, FP, (char *)"Load increment");
               emitRO((char *)"ADD", AC, AC, AC2, (char *)"increment");
               emitRM((char *)"ST", AC, tmp->offset, FP, (char *)"store into index");
               
               emitGotoAbs(cur, (char *)"go to beginning of loop");
               backPatchAJumpToHere(breakloc, (char *)"Jump past loop [backpatch]");   // backpatch jump to end of loop
               
               breakloc = skiploc;              // restore for break statement
               emitComment((char *)"END LOOP");

               

               break;

            case LoopForeverK :
               printf("LoopForever \n");
               emitComment((char*)"LoopForever");
               endOfFrame = endOfFrame-1;
               breakloc= emitSkip(1);
               broke = emitSkip(0);
               emitRM((char *)"LDA", 7, 1, 7, (char *)"Jump to start of loop");
               
               treeCode(tree->child[1]);
               backPatchAJumpToHere(breakloc, (char *)"Jump past loop forever [backpatch]");
               
               break;

            case CompoundK :
               if(cc) printf("Compound \n");

               emitComment((char*)"Compound");

               treeCode(tree->child[0]);
               treeCode(tree->child[1]);

               emitComment((char*)"End Compound ");
               
               break;

            case RangeK :
               printf("Range \n");
               emitComment((char*)"Range Error!");
               break;

            case ReturnK :
               if(cc) printf("Return \n");
               emitComment((char*)"Return");
               treeCode(tree->child[0]);
               emitRM((char *)"LDA", 2, 0 ,3, (char *)"Copy result into rt register " );      //Unsure of middle
               emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address " );      //Unsure of middle
               emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp" );
               emitRM((char *)"LDA", 7, 0, 3, (char *)"Return " );
               break;

            case BreakK :
               printf("Break \n");
               emitComment((char*)"Break");
               cur = emitSkip(0);
               breakloc = cur - broke;
              // emitRM((char *)"LDA", 7, -breakloc-1, 7, (char *)"Return " );
               backPatchAJumpToHere(cur, (char *)"Jump past loop forever [backpatch]");
               break;

            default:
               printf("Unkown Stmt LINE: %d\n", tree->lineno);
               emitComment((char*)"Unk Stmt--------");
               break;
         }
      }
      else if (tree->nodekind == ExprK)
      {
         // printf("---Expr---\n");  
         switch (tree->kind.expr)
         {
            case OpK:
               if(cc) printf("Op: \n");
               emitComment((char*)"Op");
               opCode(tree);
               break;
            
            case ConstantK:        
               if(tree->type == Bool ){
                  if(cc) printf("Const: \n");
                  emitComment((char*)"Bool Const");
                  emitRM((char *)"LDC", 3, tree->arraySize , 6, (char *)"Load bool const " );      //Unsure of middle

               }  
               else if(tree->type == Char){
                  if(cc) printf("Const: \n");
                  emitComment((char*)"Char Const");
                  emitRM((char *)"LDC", 3, tree->attr.cvalue , 6, (char *)"Load int const " );      //Unsure of middle

               }
               else 
               {
                  if(cc) printf("Const: %d \n",tree->attr.value);
                  emitComment((char*)"Int Const");
                  emitRM((char *)"LDC", 3, tree->attr.value , 6, (char *)"Load int const " );      //Unsure of middle

               } 

               
               break;

            case IdK:
               if(cc) printf("Id: %s \n",tree->attr.name);
               emitComment((char*)"ID");
               tmp = st.lookupNode(tree->attr.name);    // != NULL if its globals
               if( tmp != NULL || tree->isStatic){
                  emitRM((char *)"LD", 3, tree->offset , 0, (char *)"Load var ", tree->attr.name);
               }
               else
               {
               emitRM((char *)"LD", 3, tree->offset , 1, (char *)"Load var ", tree->attr.name);        
               }
               

               break;

            case AssignK:
               if(cc) printf("Assign: \n");
               emitComment((char*)"Assign");

               if(tree->attr.op == EQ){
                  treeCode(tree->child[1]);
                  tmp = st.lookupNode(tree->child[0]->attr.name);    // != NULL if its globals
                  if(tree->child[0]->isStatic || tmp != NULL){
                     //st in global space
                     emitRM((char *)"ST", 3, tree->child[0]->offset , 0, (char *)"Store ADar ", tree->child[0]->attr.name);        
                  }
                  else
                  {  //store local
                     emitRM((char *)"ST", 3, tree->child[0]->offset , 1, (char *)"Store var ", tree->child[0]->attr.name);        
                  }
               }
               else
               {
                  opCode(tree);
               }
               
               
               
               break;

            case InitK:
               if(cc) printf("Init: [line: %d]\n", tree->lineno);
               emitComment((char*)"InitK");
               break;

            case CallK:
               if(cc) printf("call %s line: %d\n ",tree->attr.name, tree->lineno);
               emitComment((char*)"Call", tree->attr.name);
               
               emitRM((char *)"ST", 1, endOfFrame , 1, (char *)"Store fp in ghost frame for ", tree->attr.name);      //Unsure of middle
               tmp = tree->child[0];      //param

               while(tmp != NULL){
                  emitComment((char*)"Param ", tree->attr.name);
                  
                  if(tmp->kind.expr == IdK ){
                     //emitRM((char *)"LD", 3, tmp->offset , 1, (char *)"Load var ", tree->attr.name );      //Unsure of middle
                     treeCode(tmp);
                  }
                  else if(tmp->kind.expr == ConstantK){
                     if(tmp->type == Char){
                        emitRM((char *)"LDC", 3, tmp->attr.value , 6, (char *)"Load Char const " );      //Unsure of middle
                        if(cc) printf("Const: %c\n", tmp->attr.cvalue);
                     }
                     else if(tmp->type == Bool){
                        emitRM((char *)"LDC", 3, tmp->arraySize , 6, (char *)"Load Bool const " );      //Unsure of middle
                        printf("Constb: %d\n", tmp->attr.value);
                     }
                     else
                     {
                        emitRM((char *)"LDC", 3, tmp->attr.value , 6, (char *)"Load int const " );      //Unsure of middle
                        if(cc) printf("Const: %d\n", tmp->attr.value);
                     }
                  }
                  else if( tmp->kind.expr == OpK){
                     
                     opCode(tmp);
                  }
                  else if(tmp->kind.expr == AssignK){
                     opCode(tmp);
                  }
                  else
                  {
                     emitComment((char*)"Not found ");
                  }
                  
                  
                  
                  emitRM((char *)"ST", 3, endOfFrame-2 , 1, (char *)"Store param ");      //Unsure of middle
                  tmp = tmp->sibling;
               }

               emitComment((char*)"End param ", tree->attr.name);
               emitRM((char *)"LDA", 1, endOfFrame , 1, (char *)"Load address of new frame ");      
               emitRM((char *)"LDA", 3, 1 , 7, (char *)"Return address in ac ");   
               cur = emitSkip(0);
               tmp = st.lookupNode(tree->attr.name);
               dif = cur - tmp->startLoc;    
               emitRM((char *)"LDA", 7, -dif-1 , 7, (char *)"Call: ", tree->attr.name);  //unsure of middle
               emitRM((char *)"LDA", 3, 0 , 2, (char *)"Save the result in ac");  
               
               emitComment((char*)"End Call", tree->attr.name);
               break;

            default:
               printf("Unknown ExpK LINE %d\n", tree->lineno);
               break;
         }
      }
      else if (tree->nodekind == DeclK)
      {
         //printf("---Declk---\n");
         switch (tree->kind.decl){
            case FuncK:
               
                  Globals = true;
                  endOfFrame = tree->offset;
                  tree->startLoc = emitSkip(0);
                  if(cc) printf("Function %s eof: %d\n", tree->attr.name, endOfFrame);
                  name = tree->attr.name;
                  emitComment((char*)"FUNCTION ", name);
                  emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
                  treeCode(tree->child[0]);  //params
                  treeCode(tree->child[1]);  //compound
                  emitComment((char*)"Add standard closing in case there is no return stmt");
                  emitRM((char *)"LDC", 2, 0, 6, (char *)"Set return value to zero");
                  emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address");
                  emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp");
                  emitRM((char *)"LDA", 7,0, 3, (char *)"Return");
                  
                  emitComment((char* )"End Function ", name);
               
               
               break;

            case VarK:

               if(tree->child[0] != NULL){
                  endOfFrame = endOfFrame-2;
                  treeCode(tree->child[0]);
               }
               if (tree->isArray == true){
                  if(cc) printf("Var %s is array of ", tree->TD->Token_Str ); //       
                  printf("\n");
                  emitComment((char*)"Var array");
               }
               else
               {
                  if(cc) printf("Var %s of \n" ,tree->attr.name ); //tree->attr.name  
                  emitComment((char*)"Var");  
                  
               }

               
               //endOfFrame = endOfFrame+2;
               break;

            case ParamK:
               if(tree->isArray){
                  printf("Param %s is array of\n ", tree->attr.name);
                  emitComment((char*)"Param Array");
                  
               }
               else{
                  printf("Param %s of \n", tree->attr.name);
                  emitComment((char*)"Param");
                  
               }
               break;

            default:
               printf("Unknown DecK LINE %d\n", tree->lineno);
               break;
         }
      }
      else
      {
         printf("Unknown node type: %d LINE %d\n", tree->nodekind, tree->lineno);
      }

     
      tree = tree->sibling;   
   }

   //init();
}

void opCode(TreeNode *tree){
   emitComment((char*)"OpK ");
   int fp;
   switch (tree->attr.op)
   {
   case AND:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");      //Unsure of middle (endOfFrame-2) 
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"AND", 3, 4 , 3, (char *)"Op and"); 
      break;
   case OR:
      printf("Or\n");
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");      //Unsure of middle (endOfFrame-2) 
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"OR", 3, 4 , 3, (char *)"Op or"); 
      break;
   case NOT:
      treeCode(tree->child[0]);
      emitRM((char *)"LDC", 4, 1 , 6, (char *)"Load 1"); 
      emitRO((char *)"XOR", 3, 3 , 4, (char *)"Op NOT"); 

      break;

   case QMARK:
      treeCode(tree->child[0]);
      emitRO((char *)"RND", 3, 3 , 6, (char *)"Op ?"); 
      break;

   case EQEQ:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"TEQ", 3, 4 , 3, (char *)"Op ==");
      
      break;

   case LESSEQ:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"TLE", 3, 4 , 3, (char *)"Op <=");
      break;

   case GRETEQ:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"TGE", 3, 4 , 3, (char *)"Op >=");
      break;

   case LESS:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, endOfFrame , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, endOfFrame , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"TLT", 3, 4 , 3, (char *)"Op <");
      break;

   case GRET:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"TGT", 3, 4 , 3, (char *)"Op >");
      break;

   case NOTEQ:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"TNE", 3, 4 , 3, (char *)"Op !=");
      break;

   case MULTIPLY:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, endOfFrame-2 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"MUL", 3, 4 , 3, (char *)"Op *");
      break;

   case PLUS:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, endOfFrame-2 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, endOfFrame-2 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"ADD", 3, 4 , 3, (char *)"Op +");
      break;

case DIV:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"DIV", 3, 4 , 3, (char *)"Op /");
      break;

case ADDASS:
      fp = frame(tree);
      treeCode(tree->child[1]);
      emitRM((char*)"LD", 4,tree->child[0]->offset, fp,(char*) "Load LHS");
      emitRO((char *)"ADD", 3, 4 , 3, (char *)"Op +=");
      emitRM((char *)"ST", 3, tree->child[0]->offset , fp, (char *)"Store left ");
      break;

case SUBASS:
      fp = frame(tree);
      treeCode(tree->child[1]);
      //treeCode(tree->child[0]);
      emitRM((char*)"LD", 4,tree->child[0]->offset, fp,(char*) "Load LHS");
      emitRO((char *)"SUB", 3, 4 , 3, (char *)"Op -=");
      emitRM((char *)"ST", 3, tree->child[0]->offset , fp, (char *)"Store left ");
      break;

case MULASS:
      fp = frame(tree);
      treeCode(tree->child[1]);
      //treeCode(tree->child[0]);
      emitRM((char*)"LD", 4,tree->child[0]->offset, fp,(char*) "Load LHS");
      emitRO((char *)"MUL", 3, 4 , 3, (char *)"Op *=");
      emitRM((char *)"ST", 3, tree->child[0]->offset , fp, (char *)"Store left ");
      break;

case DIVASS:
      fp = frame(tree);
      treeCode(tree->child[1]);
      //treeCode(tree->child[0]);
      emitRM((char*)"LD", 4,tree->child[0]->offset, fp,(char*) "Load LHS");
      emitRO((char *)"DIV", 3, 4 , 3, (char *)"Op /=");
      emitRM((char *)"ST", 3, tree->child[0]->offset , fp, (char *)"Store left ");
      break;

case MINUS:
      if(!tree->unary){
         treeCode(tree->child[0]);
         emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");
         treeCode(tree->child[1]);
         emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
         emitRO((char *)"SUB", 3, 4 , 3, (char *)"Op -");
      }
      else{
         treeCode(tree->child[0]);
         emitRM((char *)"LDC", 4, 0 , 6, (char *)"Load 0"); 
         emitRO((char *)"SUB", 3, 4 , 3, (char *)"Op unary -");
      }
      
      break;
case INC:
      treeCode(tree->child[0]);
      emitRM((char *)"LDA", 3, 1 , 3, (char *)"Inc"); 
      emitRM((char *)"ST", 3, tree->child[0]->offset , fp, (char *)"Store var ");
      break;
case DEC:
      treeCode(tree->child[0]);
      emitRM((char *)"LDA", 3, -1 , 3, (char *)"Dec"); 
      emitRM((char *)"ST", 3, tree->child[0]->offset , fp, (char *)"Store var ");
      break;
case EQ:
      treeCode(tree);
      break;
   
   case PERCENT:
      treeCode(tree->child[0]);
      emitRM((char *)"ST", 3, -4 , 1, (char *)"Save left side ");
      treeCode(tree->child[1]);
      emitRM((char *)"LD", 4, -4 , 1, (char *)"Load left into ac1"); 
      emitRO((char *)"DIV", 5, 4 , 3, (char *)"Op %");
      emitRO((char *)"MUL", 5, 5 , 3, (char *)"");
      emitRO((char *)"SUB", 3, 4 , 5, (char *)"");
      break;
   default:
   printf("Opk not found!! %d\n" , tree->attr.op);
      break;
   }
}
//Process the global vars and functs
void init(){
   int cur = 0;
   int dif = 0;
   emitComment((char*)"INIT");
   emitRM((char *)"LD", 0,0,0, (char *)"Set the global pointer");
   emitRM((char *)"LDA", 1, Goffset, 0, (char *)"Set first fram at the end of globals");  //Not sure what the middle num comes from 
   emitRM((char *)"ST", 1, 0, 1, (char *)"Store old fp (point to self)");

   emitComment((char*)"INIT Globals and Statics");
   //treeCode(tree);                                     //need to just process global var declerations 
   emitComment((char*)"End INIT Globals and Statics");

   emitRM((char *)"LDA", 3, 1, 7, (char *)"Return address in AC");
   TreeNode *tmp = st.lookupNode("main");
   cur = emitSkip(0);
   dif = cur - tmp->startLoc; 
   emitRM((char *)"LDA", 7, -dif-1, 7, (char *)"Jump to main");     //not sure where the middle num comes from. maybe from main to halt cmd? ------
   emitRM((char *)"HALT", 0, 0, 0, (char *)"Done");
   emitComment((char*)"End INIT");
}

void IOSetup(TreeNode* tree){
   time_t rawtime;
   struct tm * timeinfo;
   time (&rawtime);
   timeinfo = localtime (&rawtime);
   emitComment((char*)"Time:", asctime(timeinfo));

   TreeNode *tmp;

   //INPUT INT
   tmp = st.lookupNode("input");
   tmp->startLoc = emitSkip(0);

   emitComment((char*)"FUNCTION input");
   emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
   emitRO((char *)"IN", 2, 2, 2, (char *)"Grab int input");
   emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address");
   emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp");
   emitRM((char *)"LDA", 7, 0, 3, (char *)"Return");
   emitComment((char*)"End FUNCTION input");
   emitComment((char*)"");

   //Output INT
   tmp = st.lookupNode("output");
   tmp->startLoc = emitSkip(0);

   emitComment((char*)"FUNCTION output");
   emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
   emitRM((char *)"LD", 3, -2, 1, (char *)"Load Parameter");
   emitRO((char *)"OUT", 3, 3, 3, (char *)"Output integer");
   emitRM((char *)"LDC", 2, 0, 6, (char *)"Set return to 0");
   emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address");
   emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp");
   emitRM((char *)"LDA", 7, 0, 3, (char *)"Return");
   emitComment((char*)"End FUNCTION input");
   emitComment((char*)"");

   
   //Input BOOL
   tmp = st.lookupNode("inputb");
   tmp->startLoc = emitSkip(0);

   emitComment((char*)"FUNCTION inputB");
   emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
   emitRO((char *)"INB", 2, 2, 2, (char *)"Grab bool input");
   emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address");
   emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp");
   emitRM((char *)"LDA", 7, 0, 3, (char *)"Return");
   emitComment((char*)"End FUNCTION inputB");
   emitComment((char*)"");

   //Output BOOL
   tmp = st.lookupNode("outputb");
   tmp->startLoc = emitSkip(0);

   emitComment((char*)"FUNCTION outputB");
   emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
   emitRM((char *)"LD", 3, -2, 1, (char *)"Load Parameter");
   emitRO((char *)"OUTB", 3, 3, 3, (char *)"Output Bool");
   emitRM((char *)"LDC", 2, 0, 6, (char *)"Set return to 0");
   emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address");
   emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp");
   emitRM((char *)"LDA", 7, 0, 3, (char *)"Return");
   emitComment((char*)"End FUNCTION outputB");
   emitComment((char*)"");

   //Input CHAR
   tmp = st.lookupNode("inputc");
   tmp->startLoc = emitSkip(0);

   emitComment((char*)"FUNCTION inputC");
   emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
   emitRO((char *)"INC", 2, 2, 2, (char *)"Grab char input");
   emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address");
   emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp");
   emitRM((char *)"LDA", 7, 0, 3, (char *)"Return");
   emitComment((char*)"End FUNCTION inputC");
   emitComment((char*)"");

   //Output 
   tmp = st.lookupNode("outputc");
   tmp->startLoc = emitSkip(0);

   emitComment((char*)"FUNCTION outputC");
   emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
   emitRM((char *)"LD", 3, -2, 1, (char *)"Load Parameter");
   emitRO((char *)"OUTC", 3, 3, 3, (char *)"Output Char");
   emitRM((char *)"LDC", 2, 0, 6, (char *)"Set return to 0");
   emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address");
   emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp");
   emitRM((char *)"LDA", 7, 0, 3, (char *)"Return");
   emitComment((char*)"End FUNCTION outputC");
   emitComment((char*)"");

   //Output Newline 
   tmp = st.lookupNode("outnl");
   tmp->startLoc = emitSkip(0);

   emitComment((char*)"FUNCTION outNewLine");
   emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
   emitRO((char *)"OUTNL", 3, 3, 3, (char *)"Output newline");
   emitRM((char *)"LD", 3, -1, 1, (char *)"Load return address");
   emitRM((char *)"LD", 1, 0, 1, (char *)"Adjust fp");
   emitRM((char *)"LDA", 7, 0, 3, (char *)"Return");
   emitComment((char*)"End FUNCTION outNewLine");
   emitComment((char*)"");

   
   treeCode(tree);     //process the tree 
   

   

   
    backPatchAJumpToHere(0,(char*) "Jump to init (backPatch)");
   //emitRMAbs("LDA", 7, emitLoc-1,(char *)"Jump to init [backpatch]" );
   emitComment((char*)"Now backpatch");
   //emitRM((char *)"LDA", 7, emitLoc-1, 7, (char *)"Jump to init [backpatch]");


}

int frame(TreeNode* tree){
   TreeNode* tmp = tree->child[0];
   tmp = st.lookupNode(tmp->attr.name);
   if(tree->child[0]->isStatic || tmp != NULL){
      return 0;      //its globals
   }

   return 1; //local
}