Bin  = c-
CC = g++
CFLAGS = -g 

SRCS = parser.y parser.l printtree.c symbolTable.cpp semantic.c IO.c errors.c
DEPS = lex.yy.c parser.tab.c parser.tab.h makefile
HDRS = printtree.h ScanType.h symbolTable.h semantic.h IO.h
OBJS = parser.tab.o lex.yy.o

c-: $(SRCS) $(DEPS) $(HDRS)
	g++ parser.tab.c lex.yy.c printtree.c symbolTable.cpp semantic.c IO.c errors.c -g -o c- 

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
	./c- tiny.c-
	echo -e '4 | 7\n'
	./c- call.c-
	echo -e '4 | 0\n'
	./c- loopscope.c-
	echo -e '0 | 2\n'
	./c- matchunmatch.c-
	echo -e '6 | 8\n'
	./c- nano.c-
	echo -e '1 | 1\n'
	./c- nano.c-
	echo -e '3 | 30\n'
	./c- nano.c-
	echo -e '7 | 24\n'
	./c- exp.c-
	echo -e '8 | 10\n'
	./c- io.c-
	echo -e '1 | 1\n'
	./c- callerr.c-
	echo -e '1 | 10\n'

alls:
	./c- small.c-
	./c- tiny.c-
	./c- nano.c-
	./c- call.c-
	./c- loops.c-
	./c- matchunmatch.c-
	./c- param.c-
	./c- undefined.c-
	./c- tinyType.c-
	./c- basicAll5.c-
	./c- badcontrol.c-
	./c- exp.c-
	./c- array.c-
	./c- io.c-
	./c- callerr.c-
	./c- optype.c-

	
