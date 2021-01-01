/* Caleb Seely 1/25/2020
 * CS 445 - Compiler Design
 * Hw1 Bison 
 */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ScanType.h"
#define YYERROR_VERBOSE
int yylex();
extern int yylineno;
extern FILE *yyin;
void yyerror(const char *msg)
{
      printf("ERROR(PARSER): %s\n LINE %d\nToken ", msg, yylineno );
}
%}

%union {
    TokenData *Token_Data;
    double value;
}

%token <Token_Data> CHAR_ERR KEY NUMCONST ID CHARCONST CHARCONST_ESC RANGE STRINGCONST BOOLCONST OP INVALID ADDASS SUBASS MULASS DIVASS DEC INC NOTEQ EQ LESSEQ GRETEQ
%type <value> decleration MULOP 
// type specifies the token classes used only in the parser



%%  
program : %empty
        | decleration program 

;

decleration : NUMCONST        {printf("Line %d Token: NUMCONST Value: %d  Input: %s\n", $1->Line_Num, $1->Num_Val, $1->Token_Str );}
            | KEY             {printf("Line %d Token: %s\n", $1->Line_Num, $1->Token_Str );}
            | ID              {printf("Line %d Token: ID Value: %s\n", $1->Line_Num, $1->Token_Str );}
            | STRINGCONST     {printf("Line %d Token: STRINGCONST Value: '%s'  Input: %s \n", $1->Line_Num, $1->Raw_Str, $1->Token_Str ); }
            | OP              {printf("Line %d Token: %s\n", $1->Line_Num, $1->Token_Str );}
            | CHARCONST       {printf("Line %d Token: CHARCONST Value: '%c'  Input: %s\n", $1->Line_Num, $1->Token_Str[1], $1->Token_Str );}
            | CHARCONST_ESC   {printf("Line %d Token: CHARCONST Value: '%s'  Input: %s\n", $1->Line_Num, $1->Raw_Str, $1->Token_Str );}
            | CHAR_ERR        {printf("Line %d Token: CHARCONST Value: '%s'  Input: \'%s\n", $1->Line_Num, $1->Token_Str,$1->Raw_Str+1 );}
            | BOOLCONST       {printf("Line %d Token: BOOLCONST Value: %d  Input: %s\n", $1->Line_Num, $1->Num_Val, $1->Token_Str);}
            | INVALID         {printf("ERROR(%d): Invalid or misplaced input character: \"%s\"\n", $1->Line_Num, $1->Token_Str );} 
            | MULOP

;
MULOP : ADDASS                {printf("Line %d Token: ADDASS\n", $1->Line_Num );}     
      | SUBASS                {printf("Line %d Token: SUBASS\n", $1->Line_Num );}
      | MULASS                {printf("Line %d Token: MULASS\n", $1->Line_Num );}
      | DIVASS                {printf("Line %d Token: DIVASS\n", $1->Line_Num );}
      | DEC                   {printf("Line %d Token: DEC\n", $1->Line_Num );}
      | INC                   {printf("Line %d Token: INC\n", $1->Line_Num );}
      | NOTEQ                 {printf("Line %d Token: NOTEQ\n", $1->Line_Num );}
      | EQ                    {printf("Line %d Token: EQ\n", $1->Line_Num );}
      | LESSEQ                {printf("Line %d Token: LESSEQ\n", $1->Line_Num );}
      | GRETEQ                {printf("Line %d Token: GRTEQ\n", $1->Line_Num );}
      | RANGE                 {printf("Line %d Token: RANGE\n", $1->Line_Num );}
;


//expression : ID   {printf("ID = %s\nLine = %d\n", $1->Token_Str, $1->Line_Num);}
%%

int main(int argc, char *argv[]){
   if(argc > 1){
      if((yyin = fopen(argv[1], "r"))){
         //redirects input
      }
      else{
         printf("File failed to open\n");
         exit(1);
      }
   }
   
   yyparse();
   
}