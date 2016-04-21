#ifndef __QUEUE_H_
#define __QUEUE_H_

typedef struct node {
	int priority;
	char *data;
} node_t;

typedef struct heap {
	node_t *nodes;
	int len;
	int size;
} heap_t;

void insert(heap_t *h, int p, char *d);
void pop(heap_t *h);

#endif