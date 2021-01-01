/* 
 * Caleb Seely 
 * Flex Scanner
 * 1/26/2020
 * Compilers CS 445
 */

%{
   #include <stdlib.h>
   #include <ctype.h> 
   #include <stdio.h> 
   #include <string.h>
   #include "printtree.h"
  // #include "ScanType.h"
   #include "parser.tab.h" 
   //#include "yyerror.h"
   bool pdbug = false;
   extern int numErrs, numWarns; 

   static int Char_Error(int LINE_NUMBER, int Token_Class, char* String_Value){
      if(strlen(String_Value)-2 == 0){
         printf("ERROR(%d): Empty character ''\n", LINE_NUMBER);
      }
      else if(strlen(String_Value)- 2 == 1 || String_Value[1] == 92){
         
         if( String_Value[1] == 92){
            
            if(String_Value[2] ==110 ){
               printf("MADE it %s\n", String_Value);
               String_Value[1] = 10 ;
               
            }
            else if(String_Value[2] ==48 ){
               printf("MADE it %s\n", String_Value);
               String_Value[1] = 0 ;
               
            }
            else{
               String_Value[1] = String_Value[2];
               String_Value[2] = String_Value[0];
               String_Value[2] = 0;               
            }

         }
      }
      else{
         printf("WARNING(%d): character is %zu characters long and not a single character: '%s'.  First char used.\n", LINE_NUMBER, strlen(String_Value)-2, String_Value);
      }
      //printf("Length %zu\n", strlen(String_Value)-2);

      yylval.Token_Data = new TokenData;
      yylval.Token_Data->Token_Class = Token_Class;
      String_Value[2] = 39;
      String_Value[3] = 0;
      //printf("Returning %s\n", String_Value);
      yylval.Token_Data->Token_Str = strdup(String_Value);

      numWarns++;
      
      return Token_Class;
   }

   static int Set_Value(int LINE_NUMBER, int Token_Class, char *String_Value){

      yylval.Token_Data =  new TokenData;
      yylval.Token_Data -> Token_Class = Token_Class;

      yylval.Token_Data -> Token_Str = strdup(String_Value);
      //printf("Token STRING: %s\n",  yylval.Token_Data -> Token_Str);

      yylval.Token_Data -> Line_Num = LINE_NUMBER;

      switch (Token_Class) {
         case NUMCONST:
         yylval.Token_Data->Num_Val = atoi(String_Value); 
         break;

         case STRINGCONST:{
            char *tmp = strdup(String_Value);
            char *fin = tmp;
            tmp[strlen(tmp)] = '\0';
            fin[strlen(tmp)] = '\0';
            //printf("THE STRING IS %s\n", tmp);
            int len = strlen(tmp);
            int j = 0;
            for(int i  = 1; i < len ; i++){
               
               //printf("%d %c|\n", tmp[i], tmp[i]);
               fin[j] = tmp[i];

               if(tmp[i] == 92 && tmp[i+1] == 110){
                  //printf("NEWLINE\n");
                  fin[j] = 10;        //new line char   
                  i++;                      
               }
               else if(tmp[i] == 92 && tmp[i+1] == 48){
                  fin[j] = 0;
                  i++;
               }
               else if(tmp[i] == 92 ){
                  fin[j] = tmp[i+1];
                  i++;
               }
               j++;               
            }
            fin[j-1] = '\0';
            yylval.Token_Data -> Raw_Str = strdup(fin);
            //yylval.Token_Data -> Token_Str = strdup(tmp);
            //printf("Token STRING PT2: %s\n",  yylval.Token_Data -> Token_Str);
            //printf("NEW STRING IS|%s|\n", fin);
            break;
         }

         case CHARCONST:{

            //char *tmp = '\0';
            //printf("Token_Str  |%d|\n", String_Value[0]);
            if(String_Value[0] == 34){ // "STRING"
              // printf("ONE = 34\n");
               
               break;
            }
            else if(String_Value[1] == 39){ //''
            //printf("ONE = 39\n");
               String_Value[2] = 39;
               String_Value[1] = String_Value[0];
               String_Value[0] = 39;
               String_Value[3] = 0;
               yylval.Token_Data -> Token_Str = strdup(&String_Value[0]);
               break;
               //printf("Token_Str NEW |%s|\n", yylval.Token_Data->Token_Str);
            }

            
            //printf("STILL MISING |%s|\n", yylval.Token_Data->Token_Str);
               yylval.Token_Data -> Token_Str = strdup(&String_Value[0]);
               
            break;
         }
         
         case INT:{
            char ch ; 
            int j =0;
            while (String_Value[j]) { 
            String_Value[j] =String_Value[j]-32 ;     //Capitol letters
            j++; 
            yylval.Token_Data -> Token_Str = strdup(String_Value);
            }     
            break;    
         }
      }
      return Token_Class;
   }
	; int LINE_NUMBER = 1;
%}

%option noyywrap
%option yylineno
DIGIT [0-9]

LETTER [A-Za-z\_]
SINGLE_CHAR [\;\,\:\=\+\-\<\>\*\?/\%\[\]\{\}\(\)]

%%

static                     return Set_Value(LINE_NUMBER,STATIC,yytext);
int                        return Set_Value(LINE_NUMBER,INT,yytext);      
bool                       return Set_Value(LINE_NUMBER,BOOL,yytext);
char                       return Set_Value(LINE_NUMBER,CHAR,yytext);
if                         return Set_Value(LINE_NUMBER,IF,yytext);
else                       return Set_Value(LINE_NUMBER,ELSE,yytext);
elsif                      return Set_Value(LINE_NUMBER,ELSIF,yytext);
then                       return Set_Value(LINE_NUMBER,THEN,yytext);
while                      return Set_Value(LINE_NUMBER,WHILE,yytext);
do                         return Set_Value(LINE_NUMBER,DO,yytext);
loop                       return Set_Value(LINE_NUMBER,LOOP,yytext);
forever                    return Set_Value(LINE_NUMBER,FOREVER,yytext);
break                      return Set_Value(LINE_NUMBER,BREAK,yytext);
and                        return Set_Value(LINE_NUMBER,AND,yytext);
or                         return Set_Value(LINE_NUMBER,OR,yytext);
not                        return Set_Value(LINE_NUMBER,NOT,yytext);
return                     return Set_Value(LINE_NUMBER, RETURN,yytext);

true                       return Set_Value(LINE_NUMBER, TRUE, yytext);
false                      return Set_Value(LINE_NUMBER, FALSE, yytext);

\".*\"                      return Set_Value(LINE_NUMBER, CHARCONST, yytext);//printf("\nSTRING: %s\n", yytext);

\/\/.*[\n]                 ++LINE_NUMBER; //printf("\nCOMMENT %s\n", yytext);
{DIGIT}+                   return Set_Value(LINE_NUMBER, NUMCONST, yytext);//printf("\nDIGIT: %s\n", yytext);
{LETTER}+[0-9A-Za-z]*     return Set_Value(LINE_NUMBER, ID, yytext);//printf("\nID: %s\n", yytext);

"?"            return Set_Value(LINE_NUMBER, QMARK, yytext); 
"*"             return Set_Value(LINE_NUMBER, MULTIPLY, yytext); //if(pdbug)printf("Multiply found: %s\n", yytext);
"-"            return Set_Value(LINE_NUMBER, MINUS, yytext); 
"%"            return Set_Value(LINE_NUMBER, PERCENT, yytext);
"/"            return Set_Value(LINE_NUMBER, DIV, yytext); 
"+"            return Set_Value(LINE_NUMBER, PLUS, yytext); 
"<"            return Set_Value(LINE_NUMBER, LESS, yytext);
">"            return Set_Value(LINE_NUMBER, GRET, yytext);
"="            return Set_Value(LINE_NUMBER, EQ, yytext);
";"            return Set_Value(LINE_NUMBER, SEMI, yytext);
"["            return Set_Value(LINE_NUMBER, LIndex, yytext);
"]"            return Set_Value(LINE_NUMBER, RIndex, yytext);
"{"            return Set_Value(LINE_NUMBER, LB, yytext);
"}"            return Set_Value(LINE_NUMBER, RB, yytext);
"("            return Set_Value(LINE_NUMBER, LP, yytext);
")"            return Set_Value(LINE_NUMBER, RP, yytext);
","             return Set_Value(LINE_NUMBER, COM, yytext);printf("COM\n");
":"            return Set_Value(LINE_NUMBER, COL, yytext);

"+="           return Set_Value(LINE_NUMBER, ADDASS, yytext); // printf("ADDASS %s|\n", yytext); 
"-="           return Set_Value(LINE_NUMBER, SUBASS, yytext); //printf("SUBASS %s|\n", yytext);   
"*="           return Set_Value(LINE_NUMBER, MULASS, yytext); //printf("MULASS %s|\n", yytext);     
"/="           return Set_Value(LINE_NUMBER, DIVASS, yytext);//printf("DIVASS %s|\n", yytext);    
"--"           return Set_Value(LINE_NUMBER, DEC, yytext);//printf("DEC %s|\n", yytext);     
"++"           return Set_Value(LINE_NUMBER, INC, yytext);//printf("INC %s|\n", yytext);  
"!="           return Set_Value(LINE_NUMBER, NOTEQ, yytext);//printf("NOTEQ %s|\n", yytext);     
"=="           return Set_Value(LINE_NUMBER, EQEQ, yytext);//printf("EQ %s|\n", yytext);  
"<="           return Set_Value(LINE_NUMBER, LESSEQ, yytext); //printf("LESSEQ %s|\n", yytext);     
">="           return Set_Value(LINE_NUMBER, GRETEQ, yytext);//printf("GRETEQ %s|\n", yytext); 

              
\n	            ++LINE_NUMBER;  
''            printf("ERROR(%d): Empty character %s \n", LINE_NUMBER, &yytext[0]); numErrs++;

'(\\.|[^\n'\\])'          return Char_Error(LINE_NUMBER, CHARCONST, yytext);
\.\.              return Set_Value(LINE_NUMBER, RANGE, yytext);



" "  ; //White space
\t  ; //Tabs



.               printf("WARNING(%d): Invalid or misplaced input character: '%c'. Character Ignored.\n", LINE_NUMBER, yytext[0]);  numWarns++;   //printf(" ERR NOT MATCHED |%s|\n", yytext);// return Set_Value(LINE_NUMBER, INVALID, yytext);   ////                      // printf("NOT FOUND: %s\n", yytext);
              
%%
//	
// int main()
// {
//   yylex();
//   printf("# of lines = %d, # of chars = %d\n", LINE_NUMBER, num_chars);
// }

          