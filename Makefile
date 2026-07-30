CC = gcc

CFLAGS = -Wall -g -Isrc -Isrc/ast -Isrc/symbol_table -Isrc/semantic -Isrc/visualization -Isrc/optimization

BISON = win_bison
FLEX = win_flex

OBJS = parser.tab.o \
       lex.yy.o \
       main.o \
       ast.o \
       symtab.o \
       tac.o \
       ast_graphviz.o \
       optimizer.o

all: compiler.exe

compiler.exe: $(OBJS)
	$(CC) $(CFLAGS) -o compiler.exe $(OBJS)

parser.tab.c parser.tab.h: src/parser/parser.y
	$(BISON) -d src/parser/parser.y

lex.yy.c: src/lexer/lexer.l parser.tab.h
	$(FLEX) src/lexer/lexer.l

parser.tab.o: parser.tab.c
	$(CC) $(CFLAGS) -c parser.tab.c -o parser.tab.o

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c -o lex.yy.o

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o main.o

ast.o: src/ast/ast.c
	$(CC) $(CFLAGS) -c src/ast/ast.c -o ast.o

symtab.o: src/symbol_table/symtab.c
	$(CC) $(CFLAGS) -c src/symbol_table/symtab.c -o symtab.o

tac.o: src/semantic/tac.c
	$(CC) $(CFLAGS) -c src/semantic/tac.c -o tac.o

ast_graphviz.o: src/visualization/ast_graphviz.c
	$(CC) $(CFLAGS) -c src/visualization/ast_graphviz.c -o ast_graphviz.o

optimizer.o: src/optimization/optimizer.c
	$(CC) $(CFLAGS) -c src/optimization/optimizer.c -o optimizer.o

clean:
	-rm -f compiler.exe *.exe *.o parser.tab.c parser.tab.h lex.yy.c