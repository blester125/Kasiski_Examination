/************************************
 * CS 1653 Homework Two at the      *
 * University of Pittsburgh         *
 * Taught by Bill Garrison          *
 * Spring 2016                      *
 * By:                              *
 *   Brian Lester                   *
 ************************************/

#ifndef __TREE_H_
#define __TREE_H_


/*
	Node for a Red Black BST
	0 - BlackNode
	1 - RedNode
 */
struct node {
	int key;
	struct node *left;
	struct node *right;
	int color;
};

struct node * newNode(int item);
void inorder(struct node *root);
struct node * insert(struct node *root, int);
struct node * insert_r(struct node * node, int);
struct node * rotateRight(struct node *root);
struct node * rotateLeft(struct node *root);
struct node * flipColors(struct node *root);
int getSize(struct node *root);
int isRed(struct node *root);

#endif
