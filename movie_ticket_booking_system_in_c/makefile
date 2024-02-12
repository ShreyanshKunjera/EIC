CC=gcc 
CFLAGS=-I./include
LDFLAGS= -L./lib -lfun
COMPILER_CALL= $(CC) $(CFLAGS)


C_SOURCE=src
C_OBJECT=build/object
C_LIBRARY=lib
C_EXEC=build/bin

SOURCE=$(wildcard $(C_SOURCE)/*.c)
OBJECT=$(patsubst $(C_SOURCE)/%.c,$(C_OBJECT)/%.o,$(SOURCE))

$(C_LIBRARY)/libfun.a:$(C_OBJECT)/decleration.o
	ar rs $(C_LIBRARY)/libfun.a $(C_OBJECT)/decleration.o

build_1: $(OBJECT) $(C_LIBRARY)/libfun.a
	$(COMPILER_CALL) $(OBJECT) -o $(C_EXEC)/exec $(LDFLAGS)

execute:
	./$(C_EXEC)/exec


$(C_OBJECT)/%.o:$(C_SOURCE)/%.c
	$(COMPILER_CALL) -c $< -o $@

clean:
	rm -rf $(C_OBJECT)/*.o $(C_EXEC)/exec $(C_LIBRARY)/libfun.a





#exe:book_ticket_code.o libfun.a
#	gcc book_ticket_code.o -o exe -L. libfun.a -lm
#book_ticket_code.o:book_ticket_code.c
#	gcc -c book_ticket_code.c -o book_ticket_code.o
#libfun.a:decleration.o
#	ar rs libfun.a decleration.o
#decleration.o:decleration.c
#	gcc -c decleration.c -o decleration.o
#clean:
#	rm -rf exe book_ticket_code.o libfun.a decleration.o
