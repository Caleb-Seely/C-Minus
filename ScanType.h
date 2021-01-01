#ifndef SCAN_TYPE
#define SCAN_TYPE
typedef struct{

   int Token_Class;
   int Line_Num;
   char *Token_Str;
   int Num_Val;
   char *Raw_Str;
   bool n;
}TokenData;
#endif
