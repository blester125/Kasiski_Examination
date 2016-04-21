#include <stdlib.h>

#include "tree.h"
#include "kasiski.h"

/* 
 * This function do a naive Kasiski examination that takes O(n^2) time
 * Distances between repeater are saved into a set that is back by a 
 * Red-Black Binary Search Tree. A better impelmentation could probably
 * be used but this is OK with shorter text
 */ 
struct node * kasiski(char * text, int length) {
	struct node * root = NULL;
	int i, j, k;
	for (i = 0; i < length; i++) {
		j = i + 1;
		while (j < length) {
			k = 0;
			while (text[i+k] == text[j+k]) {
				k++;
			}
			if (k >= lenThreshold) {
				root = insert(root, j - i);
			}
			j++;
		}
	}
	return root;
}