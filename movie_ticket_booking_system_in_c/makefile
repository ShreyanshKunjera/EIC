exe:book_ticket_code.o libfun.a
	gcc book_ticket_code.o -o exe -L. libfun.a -lm
book_ticket_code.o:book_ticket_code.c
	gcc -c book_ticket_code.c -o book_ticket_code.o
libfun.a:decleration.o
	ar rs libfun.a decleration.o
decleration.o:decleration.c
	gcc -c decleration.c -o decleration.o
clean:
	rm -rf exe book_ticket_code.o libfun.a decleration.o
