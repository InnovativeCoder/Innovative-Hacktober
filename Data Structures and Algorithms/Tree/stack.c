#include "stack.h"
void sinit(stack *s){
	s->i = 0;
}
void push(stack *s,node *ptr){
	s->a[s->i++] = ptr;
}
node* pop(stack *s){
	node *temp;
	temp = s->a[s->i-1];
	s->i--;
	return temp;
}
int isempty(stack *s){
	return s->i == 0;
}
int isfull(stack *s){
	return s->i == SIZE;
}
