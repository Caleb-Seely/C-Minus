#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "globals.h"
// #include "ScanType.h"
#include "printtree.h"
#include "parser.tab.h" 

extern bool cdbug, SYNTAXERR;
int blanks = 0;

TreeNode *newStmtNode(StmtKind kind, int lineNo){
   if(cdbug)printf("NEW STM Node\n");
   TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
   int i = 0;
   t->memSize = 0;
   if(t == NULL){
      printf("Error with newStmtNode Malloc (line %d)\n", yylineno);
   }
   else
   {
      for(i = 0; i < MAXCHILDREN; i++){
         t->child[i] = NULL;
      }
      t->sibling = NULL;
      t->nodekind = StmtK;
      t->kind.stmt = kind;
      t->lineno = lineNo;
      t->type = Void;
   }
   return t;   
}

TreeNode *newExpNode(ExpKind kind, int lineNo){
   if(cdbug) printf("NEW EXP Node\n");
   TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
   int i = 0;
   t->memSize =0;
   
   if(t == NULL){
      printf("Error with newExpNode Malloc (line %d)\n", yylineno);
   }
   else
   {
      for(i = 0; i < MAXCHILDREN; i++){
         t->child[i] = NULL;
      }
      t->sibling = NULL;
      t->nodekind = ExprK;
      t->kind.expr = kind;
      t->lineno = lineNo;
      t->type = Void;
      

   }
   return t;   
}

TreeNode *newDecNode(DeclKind kind, int lineNo){
   if(cdbug) printf("NEW Dec Node\n");
   TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
   t->memSize =0;
  // t->attr.name = (char *) malloc();
   int i = 0;

   if(t == NULL){
      printf("Error with newDecNode Malloc (line %d)\n", yylineno);
   }
   else
   {
      for(i = 0; i < MAXCHILDREN; i++){
         t->child[i] = NULL;
      }
      t->sibling = NULL;
      t->nodekind = DeclK;

      t->kind.decl = kind;
      t->lineno = lineNo;
      t->type = Void;
      

   }
   return t;  
}

TreeNode *addSibling(TreeNode *t, TreeNode *s){
   if(t==NULL){
      return s;
   }
   if(s == NULL){
      return t;
   }
   if(s != NULL && t != NULL){
      TreeNode *temp = (TreeNode *) malloc(sizeof(TreeNode));
      temp = t;

      while (temp != NULL && temp->sibling != NULL){
         temp = temp->sibling;
      }
      temp->sibling = s;
   }
   return t;
   
}

void spaces(int n){
   int i = 0;
   //printf("N is: %d\n\n", n);
   for(i = 0; i < n; i++){
      printf("!   ");
   }
}

void TreePrint(TreeNode *tree, int sib){
   int i = 0, siblingCount = sib;
   //if(cdbug) printf("TreePrint Called\n");

   if(tree == NULL) printf("TREE PRINTING IS NULL\n");

   while (tree != NULL)
   {  
      
      if(tree->memSize == 0) {
         tree->memSize = 1;    //for undeclared / errors
         tree->offset = 0;
         //tree->memType = Local;
      }
      if(SYNTAXERR){
         tree->memSize = 1;    //for undeclared / errors
         tree->offset = 0;
         
      }
      if(cdbug) printf("Tree->nodekind: %d\n", tree->nodekind);

      if(tree->nodekind == StmtK){
        if(cdbug) printf("---Stmt---\n");
         switch (tree->kind.stmt)
         {
         case IfK :
            printf("If ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;
         case NullK :
            printf("NULL ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         case ElsifK :
            printf("Elsif ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         case WhileK :
            printf("While ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         case LoopK :
            printf("Loop ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         case LoopForeverK :
            printf("LoopForever ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         case CompoundK :
            printf("Compound ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         case RangeK :
            printf("Range ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         case ReturnK :
            printf("Return ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         case BreakK :
            printf("Break ");
            if(PAST) {printf("[line: %d]", tree->lineno);}
            printf("\n");
            break;

         default:
            printf("Unkown Stmt LINE: %d\n", tree->lineno);
            break;
         }
      }
      else if (tree->nodekind == ExprK)
      {
       if(cdbug) printf("---Expr---\n");  
         switch (tree->kind.expr)
         {
         case OpK:
            printf("Op: ");
            TokenPrint(tree->attr.op, "\0");
            if(PAST) {printf(" ["); exprTypePrint(tree->type); printf("] [line: %d]", tree->lineno);}
            printf("\n");
            break;
         
         case ConstantK:        
            if(tree->type == Bool ){
               printf("Const: ");
               TokenPrint(tree->attr.op, "\0");
               if(PAST) {printf(" [type bool] [line: %d]", tree->lineno);}
               printf("\n");
            }  
            else if(tree->type == Char){
               printf("Const: ");
               if(strcmp(tree->TD->Token_Str, "'\0'") == 0){ printf("'%c'", '\0'); }
               else printf("%s", tree->TD->Token_Str);
               if(PAST) {printf(" [type char] [line: %d]", tree->lineno);}
               printf("\n");
            }
            else 
            {
               printf("Const: %d ",tree->attr.value);
               if(PAST) {printf(" [type int] [line: %d]", tree->lineno);}
               printf("\n");
               //TokenPrint(tree->attr.op, "\0");
            } 
            break;

         case IdK:
            printf("Id: %s ",tree->attr.name);
            if(PMEM) {printf(" [mem: "); memTypePrint(tree->memType); printf(" size: %d loc: %d] ", tree->memSize, tree->offset); }
            if(PAST) {printf("["); exprTypePrint(tree->type); printf("] [line: %d]", tree->lineno);}
            printf("\n");
            
            break;

         case AssignK:
            printf("Assign: ");
            TokenPrint(tree->attr.op, "\0");
            if(PAST) {printf(" ["); exprTypePrint(tree->type); printf("] [line: %d]", tree->lineno);}
            printf("\n");
            
            break;

         case InitK:
            printf("Init: [line: %d]\n", tree->lineno);
            break;

         case CallK:
            printf("Call: %s ",tree->attr.name);
            if(PAST) {printf("["); exprTypePrint(tree->type); printf("] [line: %d]", tree->lineno); }
            printf("\n");
            break;

         default:
            printf("Unknown ExpK LINE %d\n", tree->lineno);
            break;
         }
      }
      else if (tree->nodekind == DeclK){
         if(cdbug) printf("---Declk---\n");
         switch (tree->kind.decl){
            case FuncK:
               printf("Func %s returns ", tree->attr.name );
               exprTypePrint(tree->type);
               if(PMEM) {printf(" [mem: "); memTypePrint(tree->memType); printf(" loc: %d] ", tree->offset);}
               if(PAST) {printf(" [line: %d]", tree->lineno);}
               
               printf("\n");
               break;

            case VarK:
               if (tree->isArray == true){
                  printf("Var %s is array of ", tree->TD->Token_Str ); //   
                  exprTypePrint(tree->type);      
                  if(PMEM) {printf(" [mem: "); memTypePrint(tree->memType); printf(" size: %d loc: %d] ", tree->memSize, tree->offset);}      
                  if(PAST) {printf(" [line: %d]",  tree->lineno);}
                  printf("\n");
               }
               else
               {
                  printf("Var %s of " ,tree->attr.name ); //tree->attr.name    
                  exprTypePrint(tree->type);            
                  if(PMEM) {printf(" [mem: "); memTypePrint(tree->memType); printf(" size: %d loc: %d] ", tree->memSize, tree->offset);}  
                  if(PAST) {printf(" [line: %d]",  tree->lineno);}
                  printf("\n");
               }
               break;

            case ParamK:
               if(tree->isArray){
                  printf("Param %s is array of ", tree->attr.name);
                  exprTypePrint(tree->type);
                  if(PMEM) {printf(" [mem: "); memTypePrint(tree->memType); printf(" size: %d loc: %d] ", tree->memSize, tree->offset);}  
                  if(PAST) {printf(" [line: %d]", tree->lineno);}
                  printf("\n");
               }
               else{
                  printf("Param %s of ", tree->attr.name);
                  exprTypePrint(tree->type);
                  if(PMEM) {printf(" [mem: "); memTypePrint(tree->memType); printf(" size: %d loc: %d] ", tree->memSize, tree->offset);}  
                  if(PAST) {printf(" [line: %d]", tree->lineno);}
                  printf("\n");
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

      for(i = 0; i < MAXCHILDREN; i++){
         
         if( tree->child[i] != NULL){
            blanks++;
            spaces(blanks);
            printf("Child: %d ", i);
            //siblingCount = 0;
            TreePrint(tree->child[i], 0);
            blanks--;
         }
      }

      
      if(tree->sibling != NULL){
         spaces(blanks);
         //blanks++;
         
         printf("Sibling: %d ", siblingCount);
         //blanks--;
         siblingCount++;
         
      }  
      tree = tree->sibling;   
   }
}

void TokenPrint(OpKind token, const char *tokenString){
   //printf("Switch case values: %d\n", token);
   switch (token){
      case STATIC: 
      printf("static");
         break;
      case INT:
      printf("int");
         break;
      case BOOL:
      printf("bool");
         break;
      case CHAR :
      printf("char");
         break;
      case IF :
      printf("if");
         break;
      case ELSE :
      printf("else");
         break;
      case ELSIF:
      printf("elsif");
         break;
      case THEN :
      printf("then");
         break;
      case WHILE:
      printf("while");
         break;
      case DO:
      printf("do");
         break;
      case LOOP:
      printf("loop");
         break;
      case FOREVER:
      printf("forever");
         break;
      case BREAK:
      printf("break");
         break;
      case AND:
      printf("and");
         break;
      case OR :
      printf("or");
         break;
      case NOT:
      printf("not");
         break;
      case RETURN:
      printf("return");
         break;
      case TRUE :
      printf("true");
         break; 
      case FALSE:
         printf("false");
         break;
      case EQ:
         printf("=");
         break;
      case ADDASS :
         printf("+=");
         break;
      case SUBASS :
         printf("-=");
         break;   
      case MULASS :
         printf("*=");
         break;
      case DIVASS :
         printf("/=");
         break;
      case DEC :
         printf("--");
         break;
      case INC :
         printf("++");
         break;
      case NOTEQ :
         printf("!=");
         break;
      case LESSEQ :
         printf("<=");
         break;
      case GRETEQ :
         printf(">=");
         break;
      case MINUS :
         printf("-");
         break;
      case MULTIPLY :
         printf("*");
         break;
      case QMARK :
         printf("?");
         break;
      case DIV :
         printf("/");
         break;
      case PERCENT :
         printf("%%");
         break;
      case PLUS :
         printf("+");
         break;
      case LIndex :
         printf("[");
         break;
      case LESS :
         printf("<");
         break;
      case GRET :
         printf(">");
         break;
      case EQEQ :
         printf("==");
         break;
      case RIndex :
         printf("]");
         break;
      case LP :
         printf("(");
         break;
      case RP :
         printf(")");
         break;
      case ID :
         printf("ID: %s\n", tokenString);
         break;
      case NUMCONST :
         printf("Number: %s\n", tokenString);
         break;
      
      default:
         printf("Error! in printing token %d\n", token);
         break;
   }
}

void exprTypePrint(ExpType t){
   switch (t)
   {
      case Void:
         printf("type void");
         break;
      case Integer:
         printf("type int");
         break;
      case Bool:
         printf("type bool");
         break;
      case Char:
         printf("type char");
         break;
      case CharInt:
         printf("type char");
         break;
      case Equal:
         printf("Equal");
         break;
      case UndefinedType:
         printf("undefined type");
         break;
      default:
         printf("exprType not found: %d\n", t);
         break;
   }
}

void memTypePrint(VarKind v){
   switch (v)
   {
      case Global:
         printf("Global");
         break;
      case LocalStatic:
         printf("LocalStatic");
         break;
      case Local:
         printf("Local");
         break;
      case Parameter:
         printf("Parameter");
         break;
   default:
      printf("None");
      break;
   }
}
void typeToSibs(TreeNode *t, ExpType typ){
   
   TreeNode *tmp = t;
   while(tmp != NULL){
      //printf("TMP node: \n");
      tmp->type = typ;   
      tmp=tmp->sibling;
   }
}



