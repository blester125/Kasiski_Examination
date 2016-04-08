#ifndef __TREE_H_
#define __TREE_H_

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

/* 0 - BlackNode
   1 - RedNode
 */

#endif