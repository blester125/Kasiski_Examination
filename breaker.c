/************************************
 * CS 1653 Homework Two at the      *
 * University of Pittsburgh         *
 * Taught by Bill Garrison          *
 * Spring 2016                      *
 * By:                              *
 *   Brian Lester                   *
 ************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "breaker.h"
#include "kasiski.h"
#include "tree.h"
#include "gcd.h"

#define LENGTH 10000
char cipherText[LENGTH];
int cipherTextLen;

int main(int argc, char **argv) {
	char c;
	int i, j, k;
	int *gaps;
	struct node *root;
	int sizeOfTree;
	int keyLength;
	int count, maxI, maxCount;
	char rawText[LENGTH];
	int rawTextLen;
	char key[20];
	if (argc != 2 && argc != 3) {
		printf("Use this program in one of the following ways\n");
		printf("\t./breaker kasiski < input.txt - To perform kasiski\n");
		printf("\t./breaker decode [key] < input.txt - To deconde\n");
		exit(0);
	}
	/* Read in file from std input */
	rawTextLen = readIn(rawText, LENGTH);
	cipherTextLen = stripInput(rawText, cipherText, rawTextLen);
	/* If the kasiski analysis option was selected */
	if (!strcmp(argv[1], "kasiski")) {
		/* Look for the repeats */
		/* gaps stored in BST */
		root = kasiski(cipherText, cipherTextLen);
		/* Save values into array */
		sizeOfTree = getSize(root);
		gaps = (int *)malloc(sizeof(int)*sizeOfTree);
		convertToArray(root, gaps, 0);
		/* Find the GCD of all the numbers */
		keyLength = findGCD(gaps, sizeOfTree);
		/* If there is no useful GCD */
		if (keyLength == 1) {
			printf("No greatest Common Denominator :(\n");
			/* Print key how many times gaps are a multiple if the key */
			maxCount = 0;
			for (i = 0; i < sizeOfTree; i++) {
				count = countCleanDivisions(gaps, sizeOfTree, gaps[i]);
				if (count > maxCount) {
					maxCount = count;
					maxI = gaps[i];
				}
			}
			printf(
				"The key with the most multiples is %d with %d divisions.\n\n", 
				maxI, 
				maxCount);
			keyLength = maxI;
			free(gaps);
			deleteTree(root);
		} else {
			printf("Greatest Common Denominator: %d\n\n", keyLength);
		}
	}
	else if (!strcmp(argv[1], "decode")) {
		if (argc == 3) {
			strncpy(key, argv[2], 20);
			key[19] = '\0';
			printf("-----------Key used: %s----------\n", key);
			decode(key, 7, cipherText, cipherTextLen);
			reinsert(cipherText, rawText, rawTextLen);
			printf("%s\n", rawText);
		}
	}
} 

int isChar(char c) {
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
		return 0;
	}
	return 1;
}

char toLower(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c + 32;
	}
	return c;
}

int readIn(char * text, int length) {
	char c;
	int i;	
	i = 0;
	while ( (c = getchar()) != EOF) {
		if (i >= LENGTH - 1) {
			printf("File Too Big!");
			break;
		}
		text[i] = c;
		i++;
	}
	text[i] = '\0';
	return i;
}

int stripInput(char * in, char * out, int length) {
	char c;
	int i, j;
	j = 0;
	for (i = 0; i < length; i++) {
		c = in[i];
		if (isChar(c) == 0) {
			c = toLower(c);
			out[j] = c;
			j++;
		}
	}
	return j;
}

/* 
 * This function decodes a cipher text of length length using a key 
 * of length keyLength. This is implemented as 'a' is a shift of zero.
 */
void decode(char *key, int keyLength, char *cipherText, int length) {
	char c;
	int i, j, offset, easyMath;
	j = 0; 
	for (i = 0; i < length; i++) {
		c = key[j];
		//offset = c - 96;
		offset = c - 97;
		//easyMath = cipherText[i] - 96;
		easyMath = cipherText[i] - 97;
		easyMath = (easyMath + 26 - offset) % 26;
		//cipherText[i] = easyMath + 96;
		cipherText[i] = easyMath + 97;
		j = (j + 1) % keyLength;
	}
}

void reinsert(char *in, char *out, int length) {
	char c;
	int i, j;
	j = 0;
	for (i = 0; i < length; i++) {
		c = out[i];
		if (isChar(c) == 0) {
			out[i] = in[j];
			j++;
		}
	}
}
