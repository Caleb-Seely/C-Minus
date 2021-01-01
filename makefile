c-: lex.yy.c parser.tab.c parser.tab.h parser.y parser.l makefile tree.c
	gcc parser.tab.c lex.yy.c tree.c -g -o c-

parser.tab.c parser.tab.h: parser.y
	bison -v -t -d parser.y --debug --verbose 

lex.yy.c: parser.l parser.tab.h
	flex parser.l