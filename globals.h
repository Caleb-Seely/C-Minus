#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum {NUMCONST, ID, CHARCONST, CHARCONST_ESC, RANGE, STRINGCONST,
BOOLCONST, STATIC, INT, BOOL, CHAR, IF, ELSE, ELSIF, THEN, WHILE, DO, LOOP,
FOREVER, BREAK, AND, OR, NOT, RETURN, TRUE, FALSE, ADDASS, SUBASS, MULASS,
DIVASS, DEC, INC, NOTEQ, EQ, LESSEQ, GRETEQ
} Token_Data;

