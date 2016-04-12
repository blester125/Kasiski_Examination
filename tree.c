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
#include "tree.h"

/*
 * A Red Black Binary Search Tree
 *   This is used as the data structure to implement the
 *   set of distances between repeated words.
 */

struct node *newNode(int item) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	temp->color = 1;
	return temp;
}

void inorder(struct node *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}

void deleteTree(struct node *root) {
	if (root != NULL) {
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
}

struct node * insert(struct node * root, int key) {
	root = insert_r(root, key);
	root->color = 0;
}

struct node * insert_r(struct node* node, int key) {
	if (node == NULL) {
		return newNode(key);
	}
	if (key < node->key) {
		node->left  = insert_r(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert_r(node->right, key);
	}
	// Rotation checks
	if (isRed(node->right) == 1 && isRed(node->left) == 0) {
		node = rotateLeft(node);
	}
	if (isRed(node->left) == 1 && isRed(node->left->left) == 1) {
		node = rotateRight(node);
	}
	if (isRed(node->left) == 1 && isRed(node->right) == 1) {
		node = flipColors(node);
	}
	return node;
}

struct node * rotateLeft(struct node* n) {
	struct node * x;
	x = n->right;
	n->right = x->left;
	x->left = n;
	x->color = n->color;
	n->color = 0;
	return x;
}

struct node * rotateRight(struct node* n) {
	struct node * x;
	x = n->left;
	n->left = x->right;
	x->right = n;
	x->color = n->color;
	n->color = 0;
	return x;
}

struct node * flipColors(struct node* n) {
	n->left->color = 0;
	n->right->color = 0;
	n->color = 1;
	return n;
}

int getSize(struct node *root) {
	int l, r;
	if (root == NULL) {
		return 0;
	}
	l = getSize(root->left);
	r = getSize(root->right);
	return l + r + 1;
}

int isRed(struct node *root) {
	if (root == NULL) {
		return 0;
	}
	return root->color;
}

// Copy the data in the tree into an array.
int convertToArray(struct node *root, int ints[], int index) {
	if (root != NULL) {
		index = convertToArray(root->left, ints, index);
		ints[index] = root->key;
		index++;
		index = convertToArray(root->right, ints, index);
		return index;
	}
	return index;
}
