
exe:main.o libmath.a
	gcc main.o -o exe -L. libmath.a -lm
main.o:main.c
	gcc -c main.c -o main.o
libmath.a:math.o
	ar rs libmath.a math.o
math.o:math.c
	gcc -c math.c -o math.o

clean:
	rm -f exe main.o libmath.a math.o
