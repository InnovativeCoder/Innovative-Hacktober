#include"queue.h"
#include<string.h>


void qinit(queue *q){
	q->r = -1;
	q->f = 0;
	q->count = 0;
}
void enq(queue *q, node *ptr){
	q->r = (q->r + 1) % 100;
	q->data[q->r] = ptr;
	q->count++;
}
node *deq(queue *q){
	node *tmp = q->data[q->f];
	q->f++;
	q->count--;
	return tmp;
}
int qfull(queue *q){
	return q->count == 100;
}
int qempty(queue *q){
	return q->count == 0;
}
