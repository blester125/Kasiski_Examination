all: gcd.c tree.c breaker.c
	gcc -o breaker breaker.c tree.c gcd.c