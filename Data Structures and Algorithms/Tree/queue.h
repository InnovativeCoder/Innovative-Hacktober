#include"tree.h"
typedef struct queue{
	node *data[100];
	int f,r,count;
}queue;

void qinit(queue *q);
void enq(queue *q, node *ptr);
node *deq(queue *q);
int qfull(queue *q);
int qempty(queue *q);
