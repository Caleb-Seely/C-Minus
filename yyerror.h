#ifndef _YYERROR_H_
#define _YYERROR_H_

extern int LINE_NUMBER;               // line number
extern int numErrs;          // number of errors

void initErrorProcessing();    // WARNING: must be called before any errors occur (near top of main)!
void yyerror(const char *msg);

#endif