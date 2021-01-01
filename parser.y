/* Caleb Seely 1/25/2020
 * CS 445 - Compiler Design
 * Hw2 Bison 
 */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "semantic.h"
#include "printtree.h"
#include "IO.h"
#include "codeGen.h"
#include "yyerror.h"

#define YYERROR_VERBOSE
int yylex();
extern int yylineno;
extern FILE *yyin;
static char *savedName;
static int savedLinenno;
static TreeNode *syntaxTree, *TreeTwo;
extern bool bug;
bool cdbug, PAST, STATIC_FLAG, PMEM;
int numErrs, numWarns, Loffset, Goffset, SYNTAXERR;
SymbolTable st;
FILE *code;


%}


%union {
    TokenData *Token_Data;
    TreeNode *Tree;
    ExpType type;
}

// type specifies the token classes used only in the parser
%token <Token_Data> CHAR_ERR KEY NUMCONST CHARCONST CHARCONST_ESC RANGE STRINGCONST  
%token <Token_Data> QMARK  MULTIPLY MINUS PERCENT DIV PLUS LESS GRET EQ SEMI LIndex RIndex LB RB LP RP COM COL EQEQ
%token <Token_Data>  IF ELSE ELSIF THEN WHILE DO LOOP FOREVER BREAK AND OR NOT RETURN TRUE FALSE
%token <Token_Data> ADDASS SUBASS MULASS DIVASS DEC INC NOTEQ LESSEQ GRETEQ ID INT BOOL CHAR STATIC  
%token <Token_Data> unary_MUL unary_MIN

%type <Tree> typeSpecifier   scopedTypeSpecifier  //for type checking
//Non terminals
%type <Tree> declarationList declaration varDeclaration scopedVarDeclaration
%type <Tree> varDeclList varDeclInitialize funDeclaration varDeclId
%type <Tree> expression program  constant argList factor
%type <Tree> call args immutable mutable unaryop
%type <Tree> unaryExpression 
%type <Tree> mulop mulExpression sumop sumExpression relop relExpression unaryRelExpression
%type <Tree> andExpression simpleExpression statement 
%type <Tree> breakStmt returnStmt iterationStmt compoundStmt expressionStmt
%type <Tree> iterationRange statementList  
%type <Tree> localDeclarations paramId paramIdList paramTypeList paramList params 
%type <Tree>  matchedElse unmatchedElse matchedIf unmatchedIf matched unmatched partialStmt unmatchedWhile matchedWhile //selectionStmt


//%define YYERROR_VERBOSE
//%define parser.error verbose

%%  
/*1*/
program : declarationList     
               {
                  $$=$1;
                  syntaxTree = $$;
                  if(cdbug) printf("<-program\n");
               }
/*2*/
declarationList : declarationList declaration   
                  {
                     if(cdbug) printf("<-declarationList declaration\n");
                     $$ = addSibling($1,$2);
                  }

                | declaration                   
                  {
                     if(cdbug) printf("<-declarationList declaration\n");
                     $$ = $1;
                  }
;
/*3*/
declaration : varDeclaration     
                  {
                     if(cdbug) printf("<-declaration varDeclaration\n");
                     $$ = $1;
                  }

            | funDeclaration     
                  {
                     if(cdbug) printf("<-declaration funDeclaration\n");
                     $$=$1;
                  }

            | error {$$ = NULL; if(cdbug) printf("declaration error\n");}
;
/*4*/
varDeclaration : typeSpecifier varDeclList SEMI
                     {
                        yyerrok;

                        if(cdbug) printf("<-varDeclaration typeSpecifier varDeclList SEMI\n");
                        $$ = $2;
                        typeToSibs($$, $1->type);
                     }

               | error varDeclList SEMI {$$ = NULL; if(cdbug) printf(" error varDeclaration\n");}
               | typeSpecifier error SEMI {$$ = NULL; yyerrok; if(cdbug) printf("typeSpecifier error SEMI\n");}
;
/*5*/
scopedVarDeclaration : scopedTypeSpecifier varDeclList SEMI
                     {
                        yyerrok;
                        if(cdbug) printf("<-scopedVarDeclaration scopedTypeSpecifier varDeclList\n");
                        $$ = $2;
                        if($2 != NULL){
                          $$->type = $1->type; 
                        }
                        
                        if(STATIC_FLAG) {
                           $$->isStatic = true;
                           STATIC_FLAG = false;
                        }
                        typeToSibs($$, $1->type);

                        
                     }

                     | scopedTypeSpecifier error SEMI {$$ = NULL; yyerrok; if(cdbug) printf("scopedTypeSpecifier error SEMI\n");}
                     | error varDeclList SEMI         {$$ = NULL; yyerrok; if(cdbug) printf("error vardeclist SEMI\n");}
                     

;
/*6*/
varDeclList :  varDeclList COM varDeclInitialize         
            {
               yyerrok;
               if(cdbug) printf("<-varDeclList varDeclList COM varDeclInitialize ADD SIBLINGS 6\n");
               $$ = addSibling($1,$3);

               
            }

            |  varDeclInitialize                         
            {
               if(cdbug) printf("<-varDeclList varDeclInitialize\n");
               $$ = $1;
            }

            | varDeclList COM error { $$ = NULL; if(cdbug) printf("varDeclList error\n");}
            | error COM varDeclInitialize {  $$ = NULL; if(cdbug) printf("error COM varDeclInitialize\n");}
            | error { $$ = NULL; if(cdbug) printf(" vardclist error\n");}
;
/*7*/
varDeclInitialize : varDeclId                            
                  {
                     if(cdbug) printf("<-varDeclInitialize varDeclId\n");
                     $$ = $1;
                  }

                  | varDeclId COL simpleExpression       
                  {
                     if(cdbug) printf("<-varDeclInitialize varDeclId COL simpleExpression \n");
                     $$=$1;
                     $$->child[0] = $3;
                  }
                  
                  | error COL simpleExpression { yyerrok; $$ = NULL; if(cdbug) printf("varDeclInitialize error\n");}
                  | varDeclId COL error { $$ = NULL; if(cdbug) ("varDeclInitialize error\n");}
                  | error  { $$ = NULL; if(cdbug) printf("varDeclInitialize error\n"); }
;
/*8*/
varDeclId : ID                                  
            {
               if(cdbug) printf("<-varDeclId ID\n");
               $$ = newDecNode(VarK, $1->Line_Num);
               $$->attr.name = strdup($1->Token_Str);
               yyerrok;
            }

            | ID LIndex NUMCONST RIndex          
            {
               yyerrok;
                  if(cdbug) printf("<-varDeclId ID LIndex NUMCONST RIndex \n");  //array define
                  $$ = newDecNode(VarK, $1->Line_Num);
                  $$->attr.name = strdup($1->Token_Str); 
                  $$->TD = $1;
                  $$->attr.value = $3->Num_Val;    //posibly not needed
                  $$->isArray = true;
                  $$->arraySize = $3->Num_Val;
                  $$->attr.op = $2->Token_Class;
                  $$->type = UndefinedType;
            }

            | ID LIndex error { $$ = NULL; }
            | error RIndex { yyerrok; $$ = NULL; }
 
;
/*9*/
scopedTypeSpecifier : STATIC typeSpecifier      
                     {
                        if(cdbug) printf("<-scopedTypeSpecifier STATIC typeSpecifier \n");
                        $$ = $2;
                        STATIC_FLAG = true;
                     }

                    | typeSpecifier             
                    {
                       if(cdbug) printf("<-scopedTypeSpecifier typeSpecifier\n");
                        $$ = $1;
                    }

                    | typeSpecifier error { $$ = NULL; if(cdbug) printf("typeSpecifier error\n"); }
;
/*10*/
typeSpecifier : INT     
               {
                  if(cdbug) printf("<-typeSpecifier INT \n");
                  $$->type =  Integer;             
               }

              | BOOL    
               {
                  if(cdbug) printf("<-typeSpecifier BOOL\n");
                  $$->type = Bool;
               }
              | CHAR    
               {
                  if(cdbug) printf("<-typeSpecifier CHAR\n");
                  $$->type = Char;
               }
; 
/*11*/
// Functions
funDeclaration : typeSpecifier ID LP params RP statement  
               {
                  if(cdbug) printf("<-funDeclaration typeSpecifier ID LP params RP statement  \n");
                  $$ = newDecNode(FuncK, $2->Line_Num); 
                  $$->attr.name = strdup($2->Token_Str);  
                  $$->type = $1->type;
                  $$->child[0] = $4;
                  $$->child[1] = $6;
               }

               | ID LP params RP statement                
               {
                  if(cdbug) printf("<-funDeclaration ID LP params RP statement  \n");
                  $$ = newDecNode(FuncK, $1->Line_Num); 
                  $$->attr.name = strdup($1->Token_Str);
                  $$->type = Void;
                  $$->TD = $1;
                  $$->child[0] = $3;
                  $$->child[1] = $5;
               }

               | typeSpecifier ID LP error            { $$ = NULL; }
               | typeSpecifier ID LP params RP error  { $$ = NULL; }
               | ID LP error                          { $$ = NULL; }
               | ID LP params RP error                { $$ = NULL; }
               | typeSpecifier error               { $$ = NULL; if(cdbug) printf("typeSpecifier error\n"); }
;
/*12*/
params : paramList   
         {
            if(cdbug) printf("<-params paramList\n");
            $$=$1;
         }

       | %empty      
         {
            if(cdbug) printf("<-params empty\n");
            $$ = NULL;
         }
;
/*13*/
paramList : paramList SEMI paramTypeList     
            {
               yyerrok;
               
               if(cdbug) printf("<-paramList paramList SEMI paramTypeList ADD SIBLINGS 13\n");
               $$ = addSibling($1,$3);
            }

            | paramTypeList               
               {
                  if(cdbug) printf("<-paramList paramTypeList\n");
                  $$=$1;
               }

            | paramList SEMI error  { $$ = NULL; if(cdbug) printf("paramList SEMI error\n"); }
            | error SEMI paramTypeList { yyerrok; $$ = NULL; if(cdbug) printf(" error SEMI paramTypeList\n");}
            | error                 { $$ = NULL; if(cdbug) printf("Paramlist error\n"); }
;
/*14*/
paramTypeList : typeSpecifier paramIdList    
               {
                  if(cdbug) printf("<-paramTypeList typeSpecifier paramIdList\n");
                  $$ = $2;
                  typeToSibs($$, $1->type);      
               }

               | typeSpecifier error { $$ = NULL; if(cdbug) printf("typeSpecifier error\n"); }
;
/*15*/
paramIdList : paramIdList COM paramId        
            {
               yyerrok;

               if(cdbug) printf("<-declarationList paramIdList COM paramId ADD SIBLINGS 15\n");
               $$ = addSibling($1,$3);
            }

            | paramId                    
            {  
               if(cdbug) printf("<-paramIdList paramId\n");
               $$=$1;
            }

            | paramIdList COM error { $$ = NULL; if(cdbug) printf("paramIdList COM error\n"); }
            | error COM paramId {yyerrok; $$ = NULL; if(cdbug) printf(" error COM paramId\n");}
;
/*16*/
paramId : ID                   
         {
            yyerrok;
            if(cdbug) printf("<-paramId ID\n");
            $$ = newDecNode(ParamK, $1->Line_Num); 
            $$->attr.name = strdup($1->Token_Str); 
            $$->isInit = true;
         }

        | ID LIndex RIndex     
         {
            yyerrok;

            if(cdbug) printf("<-paramId ID LIndex RIndex\n");
            $$ = newDecNode(ParamK, $1->Line_Num);
            $$->attr.name = strdup($1->Token_Str);  
            $$->isArray = true;
            $$->isInit = true;
            $$->type = UndefinedType;
         }

         | error RIndex {yyerrok; $$ = NULL; }
         | error { $$ = NULL; }
;
/*17*/
//Statements
statement :  expressionStmt   {$$=$1; if(cdbug) printf("<-statementexpressionStmt\n");}
            | compoundStmt {$$=$1; if(cdbug) printf("<-statement compoundStmt\n");}
            | matchedIf {$$ = $1; if(cdbug) printf("<-statement matchedIf : %d\n", $1->attr.value);}
            | unmatchedIf  {$$ = $1; if(cdbug) printf("<-statement unmatchedIf\n");}
            | iterationStmt   {$$=$1; if(cdbug) printf("<-statement iterationStmt\n");}
            | returnStmt   {$$=$1; if(cdbug) printf("<-statement returnStmt\n");}
            | breakStmt {$$=$1; if(cdbug) printf("<-statement breakStmt\n");} 
;


/*18*/
expressionStmt : expression SEMI 
               {
                  yyerrok;

                  if(cdbug) printf("<-expressionStmt expression SEMI\n");
                  $$=$1;
               }

               | SEMI     
                  {
                     yyerrok; 

                     if(cdbug) printf("<-expressionStmt SEMI\n");
                     $$=NULL;                     
                  }

               | error SEMI { yyerrok; $$ = NULL; }
;

/*19*/
compoundStmt : LB localDeclarations statementList RB      
               {
                  yyerrok; 

                  if(cdbug) printf("<-compoundStmt LB localDeclarations statementList RB\n");
                  $$ = newStmtNode(CompoundK, $1->Line_Num);
                  //$$->attr.op = $1->Token_Class;
                  $$->child[0] = $2;
                  $$->child[1] = $3;
               }

               | LB error statementList RB      { $$ = NULL; }
               | LB localDeclarations error RB  {yyerrok; $$ = NULL; }
;
/*20*/
localDeclarations : localDeclarations scopedVarDeclaration 
                  {
                     if(cdbug) printf("<-localDeclarations localDeclarations scopedVarDeclaration\n");
                     $$ = addSibling($1,$2);
                  }
                 | %empty    
                  {
                     if(cdbug) printf("<-localDeclarations empty\n");
                     $$=NULL;
                  }
;
/*21*/
statementList :  statementList statement  
              {
                 if(cdbug) printf("<-statementList statementList statement ADD SIBLINGS 21\n");
                 $$ = addSibling($1,$2);
              }
              | %empty     
               {
                  if(cdbug) printf("<-statementList empty\n");
                  $$=NULL;
               }
;
/*22*/
partialStmt : expressionStmt   {$$=$1; if(cdbug) printf("<-partialStmt expressionStmt\n");}
            | compoundStmt {$$=$1; if(cdbug) printf("<-partialStmt compoundStmt\n");}
            | returnStmt   {$$=$1; if(cdbug) printf("<-partialStmt returnStmt\n");}
            | breakStmt {$$=$1; if(cdbug) printf("<-partialStmt breakStmt\n");} 
;

matched : matchedIf  
         {
            if(cdbug) printf("<-matched matchedIf \n");
            $$=$1;
         }
         | matchedWhile 
         {
            if(cdbug) printf("<-matched matchedWhile \n");
            $$=$1;
         }
         | partialStmt  
         {
            if(cdbug) printf("<-matched partialStmt \n");
            $$=$1;
         }
         | error { $$ = NULL; }
;

unmatched : unmatchedIf 
            {
               if(cdbug) printf("<-unmatched unmatchedIf \n");
               $$=$1;
            }
            | unmatchedWhile 
            {
               if(cdbug) printf("<-unmatched unmatchedWhile \n");
               $$=$1;
            }
;

matchedIf : IF simpleExpression THEN matched matchedElse 
            {
               if(cdbug) printf("<-matchedIf IF simpleExpression THEN matched matchedElse : %d\n", $5->attr.value);
               $$ = newStmtNode(IfK, $1->Line_Num); 
               $$->child[0] = $2;
               $$->child[1] = $4;
               $$->child[2] = $5;
               
            }

            | IF error { $$ = NULL; }
            | IF error THEN matched matchedElse { $$ = NULL; yyerrok;}
;

matchedElse : ELSIF simpleExpression THEN matched matchedElse 
            {
               if(cdbug) printf("<-matchedElse ELSIF simpleExpression THEN matched matchedElse\n");
               $$ = newStmtNode(ElsifK, $1->Line_Num); 
               $$->child[0] = $2;
               $$->child[1] = $4;
               $$->child[2] = $5;
            }
            | ELSE matched 
            {
               if(cdbug) printf("<-matchedElse ELSE matched : %d\n", $2->attr.value);
               $$=$2;
            }

            | ELSIF error { $$ = NULL; }
;
unmatchedIf : IF simpleExpression THEN matched 
            {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN matched \n");
                  $$ = newStmtNode(IfK, $1->Line_Num); 
                  $$->child[0] = $2;
                  $$->child[1] = $4;
            }
            | IF simpleExpression THEN unmatched 
            {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN unmatched \n");
                  $$ = newStmtNode(IfK, $1->Line_Num); 
                  $$->child[0] = $2;
                  $$->child[1] = $4;
            }
            | IF simpleExpression THEN matched unmatchedElse 
            {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN matched unmatchedElse \n");
                  $$ = newStmtNode(IfK, $1->Line_Num); 
                  $$->child[0] = $2;
                  $$->child[1] = $4;
                  $$->child[2] = $5;
                 // $$ = addSibling($2,$5);
            }

            | IF error THEN matched { $$ = NULL; yyerrok;}
            | IF error THEN matched unmatchedElse { $$ = NULL; yyerrok;}
;
unmatchedElse : ELSIF simpleExpression THEN matched 
               {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN matched \n");
                  $$ = newStmtNode(ElsifK, $1->Line_Num); 
                  $$->child[0] = $2;
                  $$->child[1] = $4;
               }
               | ELSIF simpleExpression THEN matched unmatchedElse 
               {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN matched unmatchedElse \n");
                  $$ = newStmtNode(ElsifK, $1->Line_Num); 
                  $$->child[0] = $2;
                  $$->child[1] = $4;
                  $$->child[2] = $5;
               }
               | ELSIF simpleExpression THEN unmatched 
               {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN unmatched \n");
                  $$ = newStmtNode(ElsifK, $1->Line_Num); 
                  $$->child[0] = $2;
                  $$->child[1] = $4;
               }
               | ELSE unmatched 
               {
                  if(cdbug) printf("<-unmatchedElse ELSE unmatched \n");
                  $$ = $2;
               }

               | ELSIF error { $$ = NULL; }
;

/*24*/
iterationRange : EQ simpleExpression RANGE simpleExpression 
               {
                  if(cdbug) printf("<-iterationRange ID EQ simpleExpression RANGE simpleExpression \n");
                  $$ = newStmtNode(RangeK, $1->Line_Num);      
                  $$->child[0] = $2;
                  $$->child[1] = $4;
                  $$->child[2] = newExpNode(ConstantK, $1->Line_Num);
                  $$->child[2]-> attr.value = 1;
                  $$->child[2]->type = Integer;

               }

               | EQ simpleExpression RANGE simpleExpression COL simpleExpression
               {  
                  if(cdbug) printf("<-iterationRange ID EQ simpleExpression RANGE simpleExpression COL simpleExpression\n");
                  $$ = newStmtNode(RangeK, $1->Line_Num); 
                  
                  $$->child[0] = $2;
                  $$->child[1] = $4;
                  $$->child[2] = $6;
               }

               | EQ simpleExpression RANGE error                        { $$ = NULL; }
               | EQ simpleExpression RANGE simpleExpression COL error   { $$ = NULL; }
;

matchedWhile : WHILE simpleExpression DO matched   
               {
                  if(cdbug) printf("<-matchedWhile WHILE simpleExpression DO unmatched\n");
                  $$ = newStmtNode(WhileK, $1->Line_Num);
                  $$->attr.op = $1->Token_Class; 
                  $$->child[0]=$2;
                  $$->child[1] = $4;
               }

               | LOOP FOREVER matched 
               {
                  if(cdbug) printf("<-matchedWhile LOOP FOREVER matched\n");
                  $$ = newStmtNode(LoopForeverK, $1->Line_Num); 
                  $$->attr.op = $1->Token_Class;
                  $$->child[1]=$3; 
               }
               | LOOP ID iterationRange DO matched 
               {
                  if(cdbug) printf("<-matchedWhile ID iterationRange DO matched\n");
                  $$ = newStmtNode(LoopK, $1->Line_Num);
                  $$->attr.op = $1->Token_Class;  $$->type = Void;
                  $$->child[0] = newDecNode(VarK, $2->Line_Num);
                  $$->child[0]->type = Integer;
                  $$->child[0]-> attr.name = strdup($2->Token_Str);
                  $$->child[0]->isInit = true;
                  $$->child[1] = $3;
                  $$->child[2] = $5; 
               }

               | WHILE error DO matched   { yyerrok; $$ = NULL;if(cdbug) printf("matchedWhile WHILE error DO matched\n");}
               | WHILE error              { $$ = NULL; if(cdbug) printf("matchedWhile WHILE error\n");}
               | LOOP ID error DO matched { yyerrok; $$ = NULL; if(cdbug) printf("matchedWhile LOOP ID error DO matched\n");}
               | LOOP ID error            { $$ = NULL; if(cdbug) printf("matchedWhile LOOP ID error\n");}
               | LOOP error               { $$ = NULL; if(cdbug) printf("matchedWhile LOOP error\n");}
;

unmatchedWhile : WHILE simpleExpression DO unmatched  
               {
                  if(cdbug) printf("<-unmatchedWhile WHILE simpleExpression DO unmatched\n");
                  $$ = newStmtNode(WhileK, $1->Line_Num);
                  $$->attr.op = $1->Token_Class;  
                  $$->child[0]=$2;
                  $$->child[1] = $4;
               }
               | LOOP FOREVER unmatched 
               {
                  if(cdbug) printf("<-unmatchedWhile LOOP FOREVER unmatched\n");
                  $$ = newStmtNode(LoopForeverK, $1->Line_Num); 
                  $$->attr.op = $1->Token_Class;
                  $$->child[1]=$3; 
               }
               | LOOP ID iterationRange DO unmatched 
               {
                  if(cdbug) printf("<-unmatchedWhile LOOP iterationRange DO unmatched\n");
                  $$ = newStmtNode(LoopK, $1->Line_Num);
                  $$->attr.op = $1->Token_Class;  
                  $$->child[0] = newDecNode(VarK, $2->Line_Num);
                  $$->child[0]->type = Integer;
                  $$->child[0]->attr.name = strdup($2->Token_Str);
                  $$->child[0]->isInit = true;
                  $$->child[1] = $3;
                  $$->child[2] = $5;   
               }

               | WHILE error DO unmatched                   { $$ = NULL; yyerrok;}
               | LOOP ID iterationRange error DO unmatched  { $$ = NULL; yyerrok;}
;

/*25*/
iterationStmt : WHILE simpleExpression DO statement           
               {
                  if(cdbug) printf("<-iterationStmt declaration\n");
                  $$ = newStmtNode(WhileK, $1->Line_Num);
                  $$->attr.op = $1->Token_Class;  
                  $$->type = Void;
                  $$->child[0] = $2;
                  $$->child[1] = $4;  
               }

               | LOOP FOREVER statement               
               {
                     if(cdbug) printf("<-iterationStmt declaration\n");
                     $$ = newStmtNode(LoopForeverK, $1->Line_Num); 
                     $$->attr.op = $1->Token_Class;
                     $$->child[1] = $3; 
                  }

               | LOOP ID iterationRange DO statement     
               {
                  if(cdbug) printf("<-iterationStmt declaration\n");
                  $$ = newStmtNode(LoopK, $1->Line_Num);
                  $$->attr.op = $1->Token_Class;  $$->type = Void;
                  $$->child[0] = newDecNode(VarK, $2->Line_Num);
                  $$->child[0]->attr.name = strdup($2->Token_Str);
                  $$->child[0]->type = Integer;
                  $$->child[0]->isInit = true;
                  $$->child[1] = $3;
                  $$->child[2] = $5;
               }

               | WHILE error DO statement    { $$ = NULL; yyerrok;}
               | LOOP ID error DO statement  { $$ = NULL; yyerrok;}        


;

/*26*/
returnStmt : RETURN SEMI    
            {
               yyerrok;
               if(cdbug) printf("<-returnStmt declaration\n");
               $$ = newStmtNode(ReturnK, $1->Line_Num);
               $$->attr.op = $1->Token_Class;
            }

           | RETURN expression SEMI  
            {
               yyerrok;
               if(cdbug) printf("<-returnStmt declaration\n");
               $$ = newStmtNode(ReturnK, $1->Line_Num); 
               $$->attr.op = $1->Token_Class;  
               $$->type = $2->type;
               $$->child[0] = $2;
            }

;
/*27*/
breakStmt : BREAK SEMI       
            {
               yyerrok;
               if(cdbug) printf("<-breakStmt declaration\n");
               $$ = newStmtNode(BreakK, $1->Line_Num);
               $$->attr.op = $1->Token_Class;
            }
;
/*28*/
//Expressions
expression : mutable EQ expression       
            {
               if(cdbug) printf("<-expression mutable EQ          expression\n");
               $$ = newExpNode(AssignK, $2->Line_Num); 
               $$->type = UndefinedType;
               $$->attr.op = $2->Token_Class; 
               $$->child[0]= $1;
               $$->child[1] = $3; 
            }

           | mutable ADDASS expression    
           {
              if(cdbug) printf("<-expression mutable ADDASS expression\n");
              $$ = newExpNode(AssignK, $2->Line_Num); 
              $$->attr.op = $2->Token_Class;  
              $$->type = Integer;
              $$->child[0]= $1;
              $$->child[1] = $3; 
            }

           | mutable SUBASS expression    
           {
              if(cdbug) printf("<-expression mutable SUBASS expression\n");
              $$ = newExpNode(AssignK, $2->Line_Num); 
              $$->attr.op = $2->Token_Class;  
              $$->type = Integer;
              $$->child[0]= $1;
              $$->child[1] = $3; 
            }

           | mutable MULASS expression    
           {
              if(cdbug) printf("<-expression mutable MULASS expression\n");
              $$ = newExpNode(AssignK, $2->Line_Num); 
              $$->attr.op = $2->Token_Class;  
              $$->type = Integer;
              $$->child[0]= $1;
              $$->child[1] = $3; 
            }

           | mutable DIVASS expression    
           {
               if(cdbug) printf("<-expression mutable DIVASS expression\n");
               $$ = newExpNode(AssignK, $2->Line_Num); 
               $$->attr.op = $2->Token_Class;  
               $$->type = Integer;
               $$->child[0]= $1;
               $$->child[1] = $3; 
            }

           | mutable INC      
           {
              if(cdbug) printf("<-expression mutable INC\n");
              $$ = newExpNode(AssignK, $2->Line_Num); 
              $$->attr.op = $2->Token_Class;  
              $$->type = Integer;
              $$->child[0]= $1;
              yyerrok;
            }

           | mutable DEC      
           {
               if(cdbug) printf("<-expression mutable DEC\n");
               $$ = newExpNode(AssignK, $2->Line_Num);
               $$->attr.op = $2->Token_Class;  
               $$->type = Integer;
               $$->child[0]= $1;
               yyerrok;
            }

           | simpleExpression 
           {
              if(cdbug) printf("<-expression simpleExpression\n");
              $$=$1;
            }

            | error INC             { $$ = NULL; yyerrok;}
            | error DEC             { $$ = NULL; yyerrok;}
            
            | error ADDASS error    { $$ = NULL;}
            | error SUBASS error    { $$ = NULL;}
            | error MULASS error    { $$ = NULL;}
            | error DIVASS error    { $$ = NULL;}
            | error EQ error        { $$ = NULL;}

            | error ADDASS expression    { yyerrok; $$ = NULL;}
            | error SUBASS expression    { yyerrok; $$ = NULL;}
            | error MULASS expression    { yyerrok; $$ = NULL;}
            | error DIVASS expression    { yyerrok; $$ = NULL;}
            | error EQ expression        { yyerrok; $$ = NULL;}

            | mutable ADDASS error    { $$ = NULL;}
            | mutable SUBASS error    { $$ = NULL;}
            | mutable MULASS error    { $$ = NULL;}
            | mutable DIVASS error    { $$ = NULL;}
            | mutable EQ error        { $$ = NULL;}
            
;
/*29*/
simpleExpression : simpleExpression OR andExpression 
                  {
                     if(cdbug) printf("<-simpleExpression simpleExpression OR andExpression \n");
                     $$ = newExpNode(OpK, $2->Line_Num); 
                     $$->attr.op = $2->Token_Class;  
                     $$->type = Bool;
                     $$->child[0]= $1;
                     $$->child[1] = $3; 
                  }

                  | andExpression
                  {
                     if(cdbug) printf("<-simpleExpression andExpression\n");
                     $$=$1;
                  }

                  | simpleExpression OR error { $$ = NULL; }
                  | error OR andExpression { yyerrok; $$ = NULL; }
                  | error OR error { $$ = NULL; }
;
/*30*/
andExpression : andExpression AND unaryRelExpression 
               {
                  if(cdbug) printf("<-andExpression andExpression AND unaryRelExpression\n");
                  $$ = newExpNode(OpK, $2->Line_Num); 
                  $$->attr.op = $2->Token_Class;  
                  $$->type = Bool;
                  $$->child[0]= $1;
                  $$->child[1] = $3; 
               }

              | unaryRelExpression
              {
                 if(cdbug) printf("<-andExpression unaryRelExpression\n");
                 $$=$1;         
              }

              | simpleExpression AND error { $$ = NULL; }
              | error AND unaryRelExpression { yyerrok; $$ = NULL;}
              | error AND error              { $$ = NULL; }
;
/*31*/
unaryRelExpression : NOT unaryRelExpression 
                     {
                        if(cdbug) printf("<-unaryRelExpression NOT unaryRelExpression\n");
                        $$ = newExpNode(OpK, $1->Line_Num); 
                        $$->attr.op =$1->Token_Class;  
                        $$->type = Bool;
                        $$->child[0] = $2; 
                     }

                     | relExpression
                     {
                        if(cdbug) printf("<-unaryRelExpression relExpression\n");
                        $$ = $1;
                     }

                     | NOT error { $$ = NULL; }
;
/*32*/
relExpression : sumExpression relop sumExpression 
               {
                  if(cdbug) printf("<-relExpression sumExpression relop sumExpression\n");
                  $$ = $2;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
               }

               | sumExpression                   
               {
                  if(cdbug) printf("<-relExpression sumExpression\n");
                  $$=$1;
               }

               | sumExpression relop error { $$ = NULL; }
               | error relop sumExpression { yyerrok; $$ = NULL; }
               | error relop error         { $$ = NULL;}
;
/*33*/
relop : EQEQ     
      {
         if(cdbug) printf("<-relop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Bool; 
      }

      | LESS    
      {
         if(cdbug) printf("<-relop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Bool; 
      }

      | GRET    
      {
         if(cdbug) printf("<-relop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Bool; 
      }

      | GRETEQ 
      {
         if(cdbug) printf("<-relop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Bool; 
      }

      | LESSEQ 
      {
         if(cdbug) printf("<-relop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Bool; 
      }

      | NOTEQ  
      {
         if(cdbug) printf("<-relop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Bool; 
      }
;
/*34*/
sumExpression : sumExpression sumop mulExpression 
               {
                  if(cdbug) printf("<-sumExpression sumExpression sumop mulExpression \n");
                  $$ = $2;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
               }

               | mulExpression                   
               {
                  if(cdbug) printf("<-sumExpression mulExpression\n");
                  $$=$1;
               }

               | sumExpression sumop error  { $$ = NULL;}   //yyerrok taken out
               | error sumop mulExpression  {yyerrok; $$ = NULL;}
               | error sumop error           {$$ = NULL;}
;
/*35*/
sumop : PLUS 
      {
         if(cdbug) printf("<-sumop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class; 
         $$->type = Integer; 
      }

      | MINUS 
      {
         if(cdbug) printf("<-sumop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Integer; 
      }
;
/*36*/
mulExpression : mulExpression mulop unaryExpression 
               {
                  if(cdbug) printf("<-mulExpression mulExpression mulop unaryExpression \n");
                  $$ = $2; 
                  $$->child[0] = $1;
                  $$->child[1] = $3;
               }

               | unaryExpression     
               {
                  if(cdbug) printf("<-mulExpression unaryExpression\n");
                  $$=$1;
               }

               | mulExpression mulop error   { $$ = NULL; }
               | error mulop unaryExpression { yyerrok; $$ = NULL;}
               | error mulop error           { $$ = NULL;}
;
/*37*/
mulop : MULTIPLY 
      {
         if(cdbug) printf("<-mulop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Integer;
      }

      | DIV 
      {
         if(cdbug) printf("<-mulop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Integer;
      }

      | PERCENT 
      {
         if(cdbug) printf("<-mulop declaration\n");
         $$ = newExpNode(OpK, $1->Line_Num); 
         $$->attr.op = $1->Token_Class;  
         $$->type = Integer;
      }
;
/*38*/
unaryExpression : unaryop unaryExpression 
                  {
                     if(cdbug) printf("<-unaryExpression unaryop unaryExpression \n");
                     $$ = $1;
                     $$->child[0] = $2;
                  }
 
                  | factor            
                  {
                     if(cdbug) printf("<-unaryExpression factor\n");
                     $$=$1;
                  }

                  | unaryop error { $$ = NULL; }
;
/*39*/
unaryop : MINUS 
         {
            if(cdbug) printf("<-unaryop declaration\n");
            $$ = newExpNode(OpK, $1->Line_Num); 
            $$->attr.op = $1->Token_Class;  
            $$->type = Integer; 
            $$->unary = true;
         }

        | MULTIPLY 
        {
           if(cdbug) printf("<-unaryop declaration\n");
           $$ = newExpNode(OpK, $1->Line_Num); 
           $$->attr.op = $1->Token_Class; 
           $$->type = Integer; 
           $$->unary = true;
         }

        | QMARK 
        {
           if(cdbug) printf("<-unaryop declaration\n");
           $$ = newExpNode(OpK, $1->Line_Num); 
           $$->attr.op = $1->Token_Class;  
           $$->type = Integer;
           //$$->unary = true;
         }
;
/*40*/
factor : immutable 
         {
            if(cdbug) printf("<-factor immutable\n");
            $$=$1;
         }

       | mutable  
         {
            if(cdbug) printf("<-factor mutable\n");
            $$=$1;
         }
;
/*41*/
mutable : ID                        
         {
            yyerrok;

            if(cdbug) printf("<-mutable ID %s\n", $1->Token_Str);
            $$ = newExpNode(IdK, $1->Line_Num); 
            $$->attr.name = strdup($1->Token_Str); 
            $$->type = UndefinedType;
         }

        | mutable LIndex expression RIndex 
         {
            yyerrok;

            if(cdbug) printf("<-mutable mutable LIndex expression RIndex\n");
            $$ = newExpNode(OpK, $2->Line_Num);
            $$->attr.op = $2->Token_Class;
            $$->child[0] = $1;
            $$->child[0]->isArray = true;
            $$->child[1] = $3;
            $$->type = UndefinedType;
         }

         | ID LB error  {$$ = NULL;}
         | error RB     {yyerrok; $$ = NULL;}
;
/*42*/
immutable : LP expression RP 
            {
               yyerrok;
               if(cdbug) printf("<-immutable LP expression RP \n");
               $$ = $2;

              
            }

            | call              
            {
               if(cdbug) printf("<-immutable call\n");
               $$=$1;
            }
            | constant          
            {
               if(cdbug) printf("<-immutable constant\n");
               $$=$1;
            }

            | LP error  { $$ = NULL; }
            
;
/*43*/
call : ID LP args RP
      {
         yyerrok;
         if(cdbug) printf("<-call declaration\n");
         $$ = newExpNode(CallK, $1->Line_Num); 
         //$$->type = $3->type;
         $$->attr.name = strdup($1->Token_Str);
         $$->child[0] = $3 ;
      }

      | error RP { $$ = NULL; yyerrok;}
      | ID LP error {$$ = NULL;}
;
/*44*/
args : argList 
      {
         if(cdbug) printf("<-args declaration\n");
         $$=$1;
      }
      |
       %empty 
      {
         if(cdbug) printf("<-args empty\n");
         $$=NULL;
      }
;
/*45*/
argList : argList COM expression 
         {
            yyerrok;
            if(cdbug) printf("<-argList declaration\n");
            $$ = addSibling($1,$3);

            
         }

         | expression
         {
            if(cdbug) printf("<-argList declaration\n");
            $$=$1;
         }

         | argList COM error { $$ = NULL; }
         | error COM expression { yyerrok; $$ = NULL;}
;
/*46*/
constant : NUMCONST     
         {
            yyerrok;
            if(cdbug) printf("<-constant NUMCONST : %d\n", $1->Num_Val);
            $$ = newExpNode(ConstantK, $1->Line_Num); 
            $$-> attr.value = $1->Num_Val;
            $$->type = Integer;
            $$->isInit = true;
         }

         | CHARCONST    
         {      
            yyerrok;      
            if(cdbug) printf("<-constant CHARCONST\n");
            $$ = newExpNode(ConstantK, $1->Line_Num); 
            $$->TD=$1;
            //printf("FOUND |%s|\n", $1->Token_Str);
            $$->attr.op = $1->Token_Class;
            $$->type = Char;
            $$->isInit = true;
            $$->attr.cvalue = $1->Token_Str[1];
         }

         | STRINGCONST  
         {
            yyerrok;
            if(cdbug) printf("<-constant STRINGCONST\n");
            $$ = newExpNode(ConstantK, $1->Line_Num); 
            $$-> attr.string = strdup($1->Raw_Str);
            $$->type = Char;  
         }

         | FALSE        
         {
            yyerrok;
            if(cdbug) printf("<-constant FALSE\n");
            $$ = newExpNode(ConstantK, $1->Line_Num);
            $$->attr.value = 0;
            $$->type = Bool;
            $$->attr.op = $1->Token_Class; 
            $$->isInit = true;
         }

         | TRUE         
         {
            yyerrok;
            if(cdbug) printf("<-constant TRUE\n");
            $$ = newExpNode(ConstantK, $1->Line_Num);
            $$->attr.value = 1;
            $$->type = Bool; 
            $$->attr.op = $1->Token_Class; 
            $$->isInit = true;
         }
;

//$$ = newExpNode(IdK); $$->attr.name = copyString($1->Token_Str);
//expression : ID   {printf("ID = %s\nLine = %d\n", $1->Token_Str, $1->Line_Num);}
%%

int main(int argc, char **argv){
   int c = 0;
   numErrs = 0, numWarns = 0, Loffset = 0, Goffset = 0, SYNTAXERR = false;
   bool printSyntaxTree = 0;
   TreeNode *mainNode;
   char *filename ;
   TreeTwo = syntaxTree;
   
   



      // hunt for a string of options
      while ((c = getopt(argc, argv, "bcdpP")) != -1) {
            switch (c) {
            case 'b':
               bug = true;
               break;
            case 'c':
               cdbug = true;
               break;
            case 'd': 
               yydebug=1;
              if(cdbug) printf("DEBUGGING\n");
               break;
            case 'p': //lowercase p
               if(cdbug)printf("PRINTING SYNTAX TREE\n");
               printSyntaxTree=true;
               break;
            case 'P':   //Capitol P
            if(cdbug) printf("PRINTING THE ANNOTATED SYNTAX TREE\n");
            printSyntaxTree = true;
            //PAST = true;
            PMEM = true;
            break;
            case '?':
            default: 
               exit(1);
            }
      }


   if(argc > 1){
      filename = strdup(argv[1]);
      //printf("Changing name\n");
      filename[strlen(filename)-2] = 116; //t
      filename[strlen(filename)-1] = 109; //m

      if((yyin = fopen(argv[argc-1], "r"))){    //not sure if this actually works argc -1 is wack 
         //redirects input
      }
      else{
         if(cdbug) printf("File failed to open %s\n", argv[argc-1]);
         
      }
   }

   code = fopen(filename, "w");     //open tm file

   if(code == NULL){
      printf("Error opening %s\n",filename);
   }
   else{
      //printf("%s sucesfully opened \n", filename);
   }
      
   
   //fprintf(code, )
   initErrorProcessing();
   yyparse();     //tokenize the entire file

   // If there are syntax errors, we can now look for semantic ones
   
   if(numErrs == 0){          
      prototype();         //IO prototypes
      analyze(syntaxTree);   //syntax anlysis  
      st.applyToAll(wasUsed); //check globals

      mainNode = st.lookupNode((char *)"main");
      if(mainNode != NULL && mainNode->nodekind == DeclK && mainNode->kind.decl != FuncK || mainNode == NULL){      //if its not a function or not found at all
         printf("ERROR(LINKER): Procedure main is not declared.\n");
         numErrs++;      
      }
      else{
            //main found
      }
   }
   else{
      SYNTAXERR = true;
   }

   //printf("Print FINAL table.\n");              
   //st.print(pointerPrintStr);
   if(printSyntaxTree) TreePrint(syntaxTree, 0);   //print the tree
   //Goffset = Goffset +1;                           //bc i use post decrement (x--)
   printf("Offset for end of global space: %d\n", Goffset);
   printf("Number of warnings: %d\n",numWarns );
   printf("Number of errors: %d\n",numErrs);
   //st.print(pointerPrintStr);
   
   IOSetup(syntaxTree);
   //treeCode(syntaxTree);
   init();
   
   fclose(code);     //close tm file

}