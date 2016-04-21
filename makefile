all: gcd.c tree.c breaker.c kasiski.c
	gcc -o breaker breaker.c kasiski.c tree.c gcd.c