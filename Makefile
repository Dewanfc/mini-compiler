CC = gcc
CFLAGS = -Wall -g
INCLUDES = -Isrc -Isrc/ast -Isrc/semantic -Isrc/optimization -Isrc/visualization -Isrc/parser

OBJS = parser.tab.o lex.yy.o ast.o symtab.o tac.o optimizer.o ast_graphviz.o main.o

all: compiler.exe

compiler.exe: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o compiler.exe $(OBJS)

parser.tab.c parser.tab.h: src/parser/parser.y
	win_bison -d src/parser/parser.y

lex.yy.c: src/lexer/lexer.l parser.tab.h
	win_flex src/lexer/lexer.l

parser.tab.o: parser.tab.c
	$(CC) $(CFLAGS) $(INCLUDES) -c parser.tab.c -o parser.tab.o

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) $(INCLUDES) -c lex.yy.c -o lex.yy.o

ast.o: src/ast/ast.c
	$(CC) $(CFLAGS) $(INCLUDES) -c src/ast/ast.c -o ast.o

symtab.o: src/semantic/symtab.c
	$(CC) $(CFLAGS) $(INCLUDES) -c src/semantic/symtab.c -o symtab.o

tac.o: src/semantic/tac.c
	$(CC) $(CFLAGS) $(INCLUDES) -c src/semantic/tac.c -o tac.o

optimizer.o: src/optimization/optimizer.c
	$(CC) $(CFLAGS) $(INCLUDES) -c src/optimization/optimizer.c -o optimizer.o

ast_graphviz.o: src/visualization/ast_graphviz.c
	$(CC) $(CFLAGS) $(INCLUDES) -c src/visualization/ast_graphviz.c -o ast_graphviz.o

main.o: src/main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c src/main.c -o main.o

clean:
	rm -f compiler.exe *.o parser.tab.c parser.tab.h lex.yy.c ast.dot ast.png