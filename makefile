c-: lex.yy.c parser.tab.c parser.tab.h 
	gcc parser.tab.c lex.yy.c  -o c-

parser.tab.c parser.tab.h: parser.y
	bison -v -t -d parser.y

lex.yy.c: parser.l parser.tab.h
	flex parser.l