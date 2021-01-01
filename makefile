Bin  = c-
CC = g++
CFLAGS = -g 

SRCS = parser.y parser.l printtree.c symbolTable.cpp semantic.c IO.c errors.c yyerror.cpp emitcode.cpp codeGen.c
DEPS = lex.yy.c parser.tab.c parser.tab.h makefile
HDRS = printtree.h ScanType.h symbolTable.h semantic.h IO.h yyerror.h emitcode.h codeGen.h
OBJS = parser.tab.o lex.yy.o

c-: $(SRCS) $(DEPS) $(HDRS)
	g++ parser.tab.c lex.yy.c printtree.c symbolTable.cpp semantic.c IO.c errors.c yyerror.cpp emitcode.cpp codeGen.c -g -o c- 

parser.tab.c parser.tab.h: parser.y
	bison -v -t -d parser.y --debug --verbose 

lex.yy.c: parser.l parser.tab.h
	flex parser.l 

tar: 
	tar -cvf AAA_tarfile $(SRCS) $(HDRS) makefile
	ls -l AAA_tarfile

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c parser.tab.h parser.tab.c AAA_tarfile 
	rm tm

tiny: 
	g++ tm.c -o tm


alls:
	./c- a00.c-
	./c- a01.c-
	./c- a02.c-
	./c- a03.c-
	
	
