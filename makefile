Bin  = c-
CC = g++
CFLAGS = -g 

SRCS = parser.y parser.l printtree.c symbolTable.cpp semantic.c IO.c errors.c yyerror.cpp
DEPS = lex.yy.c parser.tab.c parser.tab.h makefile
HDRS = printtree.h ScanType.h symbolTable.h semantic.h IO.h yyerror.h
OBJS = parser.tab.o lex.yy.o

c-: $(SRCS) $(DEPS) $(HDRS)
	g++ parser.tab.c lex.yy.c printtree.c symbolTable.cpp semantic.c IO.c errors.c yyerror.cpp -g -o c- 

parser.tab.c parser.tab.h: parser.y
	bison -v -t -d parser.y --debug --verbose 

lex.yy.c: parser.l parser.tab.h
	flex parser.l 

tar: 
	tar -cvf AAA_tarfile $(SRCS) $(HDRS) makefile
	ls -l AAA_tarfile

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c parser.tab.h parser.tab.c AAA_tarfile 

tests: 

	./c- small.c-
	echo -e '5 | 4\n'


alls:
	./c- small.c-
	./c- badcontrol.c-
	./c- basicAll5.c-
	./c- init.c-
	./c- callstatic.c-
	
