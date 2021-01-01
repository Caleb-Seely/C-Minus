Bin  = c-
CC = g++
CFLAGS = -g 

SRCS = parser.y parser.l printtree.c symbolTable.cpp semantic.c
DEPS = lex.yy.c parser.tab.c parser.tab.h makefile
HDRS = printtree.h ScanType.h symbolTable.h semantic.h
OBJS = parser.tab.o lex.yy.o

c-: $(SRCS) $(DEPS)
	g++ parser.tab.c lex.yy.c printtree.c symbolTable.cpp semantic.c -g -o c- 

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

	./c- nano.c-
	echo -e '1 | 0\n'
	./c- small.c-
	echo -e '4 | 5\n'
	./c- whileif.c-
	echo -e '2 | 1\n'
	./c- tinyscope.c-
	echo -e '1 | 0\n'
	./c- callerr.c-
	echo -e '0 | 3\n'
	./c- elsif.c-
	echo -e '0 | 0\n'
	./c- precassoc.c-
	echo -e '0 | 0\n'
	./c- minus.c-
	echo -e '0 | 0\n'
	./c- exp.c-
	echo -e '8 | 10\n'
	./c- uninitialized.c-
	echo -e '5 | 0'
	./c- matchunmatch.c-
	echo -e '8 | 0'
	./c- types.c-
	echo -e '3 | 62\n'
	./c- defused.c-
	echo -e '6 | 11 \n'
	./c- decllists.c-
	echo -e '22 | 1\n'
	./c- tiny.c-
	echo -e '1 | 6\n'
	./c- notused.c-
	echo -e '4 | 4'
	./c- optype.c-
	echo -e '3 | 12'
	./c- redefined.c-
	echo -e '19 | 21\n'
	./c- scope.c-
	echo -e '4 | 25\n'
	./c- loops.c-
	echo -e '7 | 12\n'


alls:
	./c- array.c-
	./c- tiny.c-
	./c- arrays.c-
	./c- nano.c-
	./c- basicAll4.c-
	./c- small.c-
	./c- elsif.c-
	./c- callerr.c-
	./c- everythingS20.c-
	./c- elsif.c-
	./c- loops.c-
	./c- exp.c-
	./c- whileif.c-
	./c- defused.c-
	./c- types.c-
	./c- tinyType.c-
	./c- uninitialized.c-
	./c- matchunmatch.c-
	./c- notused.c-
	./c- optype.c-
	./c- precassoc.c-
	./c- redefined.c-
	./c- scope.c-
	./c- tinyscope.c-
	
