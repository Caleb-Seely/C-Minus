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
   #include "ScanType.h"
   #include "parser.tab.h" 

   static int Set_Value(int LINE_NUMBER, int Token_Class, char *String_Value){

      yylval.Token_Data =  malloc(sizeof(yylval.Token_Data));
      yylval.Token_Data -> Token_Class = Token_Class;

      yylval.Token_Data -> Token_Str = strdup(String_Value);
      //printf("Token STRING: %s\n",  yylval.Token_Data -> Token_Str);

      yylval.Token_Data -> Line_Num = LINE_NUMBER;

      switch (Token_Class) {
         case NUMCONST:
         yylval.Token_Data->Num_Val = atof(String_Value); 
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

         case CHARCONST_ESC:{
            char *tmp = "\0";
            if(String_Value[2] == 48){ //Null
               
               yylval.Token_Data -> Raw_Str = tmp;
            }
            else if (String_Value[2] == 110){   //Newline
               tmp = "\n";
               yylval.Token_Data -> Raw_Str = tmp;
            }
            else{    //Non special 
               String_Value[3] = '\0';
               yylval.Token_Data -> Raw_Str = strdup(&String_Value[2]); 
            }
            break;
         }
         
         case KEY:{
            char ch ; 
            int j =0;
            while (String_Value[j]) { 
            String_Value[j] =String_Value[j]-32 ;     //Capitol letters
            j++; 
            yylval.Token_Data -> Token_Str = strdup(String_Value);
            }     
            break;    
         }

         case BOOLCONST:{
            if(strcmp("true",String_Value)){
               yylval.Token_Data ->Num_Val = 0;      
               //printf("SET TO ZERO\n\n");  
               break;
            }
            else{
               yylval.Token_Data ->Num_Val = 1;
               break;
            }     
         } 
         case CHAR_ERR:{
            int x = strlen(String_Value)-2;
            printf("Error(%d): character is %d characters and not a single character: %s.  First char used.\n", LINE_NUMBER, x, String_Value);
            yylval.Token_Data -> Raw_Str = strdup(String_Value);
            String_Value[2] = '\0';
            yylval.Token_Data -> Token_Str = strdup(&String_Value[1]);
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

static |
int |
bool |
char |
if |
else |
elsif |
then |
while |
do |
loop | 
forever |
break |
and |
or |
not |
return                     return Set_Value(LINE_NUMBER,KEY,yytext); // printf("\nKEY: %s\n", yytext);

true |
false                      return Set_Value(LINE_NUMBER, BOOLCONST, yytext);

\".*\"                      return Set_Value(LINE_NUMBER, STRINGCONST, yytext);//printf("\nSTRING: %s\n", yytext);

\/\/.*[\n]                 ++LINE_NUMBER; //printf("\nCOMMENT %s\n", yytext);
{DIGIT}+                   return Set_Value(LINE_NUMBER, NUMCONST, yytext);//printf("\nDIGIT: %s\n", yytext);
{LETTER}+[0-9A-Za-z]*     return Set_Value(LINE_NUMBER, ID, yytext);//printf("\nID: %s\n", yytext);

"+="           return Set_Value(LINE_NUMBER, ADDASS, yytext); // printf("ADDASS %s|\n", yytext); 
"-="           return Set_Value(LINE_NUMBER, SUBASS, yytext); //printf("SUBASS %s|\n", yytext);   
"*="           return Set_Value(LINE_NUMBER, MULASS, yytext); //printf("MULASS %s|\n", yytext);     
"/="           return Set_Value(LINE_NUMBER, DIVASS, yytext);//printf("DIVASS %s|\n", yytext);    
"--"           return Set_Value(LINE_NUMBER, DEC, yytext);//printf("DEC %s|\n", yytext);     
"++"           return Set_Value(LINE_NUMBER, INC, yytext);//printf("INC %s|\n", yytext);  
"!="           return Set_Value(LINE_NUMBER, NOTEQ, yytext);//printf("NOTEQ %s|\n", yytext);     
"=="           return Set_Value(LINE_NUMBER, EQ, yytext);//printf("EQ %s|\n", yytext);  
"<="           return Set_Value(LINE_NUMBER, LESSEQ, yytext); //printf("LESSEQ %s|\n", yytext);     
">="           return Set_Value(LINE_NUMBER, GRETEQ, yytext);//printf("GRETEQ %s|\n", yytext); 

{SINGLE_CHAR}  return Set_Value(LINE_NUMBER, OP, yytext);//printf("SINGLE CHAR %s\n", yytext);

\'.\'          return Set_Value(LINE_NUMBER, CHARCONST, yytext);
\.\.           return Set_Value(LINE_NUMBER, RANGE, yytext);

\'.{2,}[^\n]\' return Set_Value(LINE_NUMBER, CHAR_ERR ,yytext); 
[\'][\\].[\']  return Set_Value(LINE_NUMBER, CHARCONST_ESC, yytext);      // printf("_______________________CHAR CONST WAS FOUND IT WAS %s|\n", yytext);

" "  ; //White space
\t  ; //Tabs
\n	         ++LINE_NUMBER;          //printf("Line: %d\n", LINE_NUMBER);
.           return Set_Value(LINE_NUMBER, INVALID, yytext);   //printf("ERR NOT MATCHED %s\n", yytext);//                      // printf("NOT FOUND: %s\n", yytext);
              
%%
//	
// int main()
// {
//   yylex();
//   printf("# of lines = %d, # of chars = %d\n", LINE_NUMBER, num_chars);
// }

          