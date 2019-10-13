#define SIZE 100
#include"queue.h"
typedef struct stack{
	node *a[100];
	int i;
}stack;
void sinit(stack *s);
void push(stack *s,node *ptr);
node* pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);

