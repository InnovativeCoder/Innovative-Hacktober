#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"stack.h"
#include<math.h>
void init(tree *t){
	*t = NULL;
}
void preorder(tree t){
	if(t == NULL)
		return;
	printf("%s\t", t->str);
	preorder(t->left);
	preorder(t->right);
}			
void inorder(tree t){
	if(t == NULL)
		return;
	inorder(t->left);
	printf("%s\t", t->str);
	inorder(t->right);
}	
void postorder(tree t){
	if(t == NULL)
		return;
	postorder(t->left);
	postorder(t->right);
	printf("%s\t", t->str);
}	
int count(tree t){
	if(t == NULL)	
		return 0;
	return 1 + count(t->left) + count(t->right);
}
#define MAX(a,b) ((a) > (b) ? a : b)
int depth(tree t){
	int x, y;
	if(t == NULL)
		return -1;
	x = depth(t->left);
	y = depth(t->right);
	return 1 + MAX(x, y);
}
void insert(tree *t, char *str){
	node *p, *q, *temp;
	int result;
	p = *t;
	temp = (node *)malloc(sizeof(node));
	temp->str = (char *)malloc(strlen(str) + 1);
	strcpy(temp->str, str);
	temp->left = temp->right = NULL;
	if(*t == NULL){
		*t = temp;
		return;
	}
	

	while(p){
		q = p;
		result = strcmp(p->str, str);
		if(result > 0)
			p = p->left;
		else if(result < 0)
			p = p->right;
		else
			return;
	}
	if(result > 0)
		q->left = temp;
	else
		q->right = temp;
}
#define LEFT 10
#define RIGHT 20		 

void del(tree *t, char *str){
	node *p, *q;
	int dir, result;
	p = *t;
	while(p){
		result = (strcmp(p->str, str));
		if(result < 0){
			q = p;
			p = p->right;
			dir = RIGHT;
		}
		else if(result > 0){
			q = p;
			p = p->left;
			dir = LEFT;
		}
		else
			break;
	}
	if(p == NULL){
		return;
	}
	if((*t)->left == (*t)->right){
		free(*t);
		*t = NULL;
		return;
	}
	
	if(p->left == p->right){
		if(dir == LEFT){
			q->left = NULL;
		}
		else{
			q->right = NULL;
		}
		free(p);
		return;
	}
	if(p->left == NULL && p->right != NULL){
		if(dir == LEFT){
			q->left = p->right;
		}
		else if(dir == RIGHT){
			q->right = p->right;
		}
		free(p);
		return;
	}				
	if(p->left != NULL && p->right == NULL){
		if(dir == LEFT){
			q->left = p->left;
		}
		else if(dir == RIGHT){
			q->right = p->left;
		}
		free(p);
		return;
	}
	node *temp, *temp_prev;
	temp = p->right;
	while(temp->left){
		temp_prev = temp;
		temp = temp->left;
	}
	free(p->str);
	p->str = temp->str;
	free(temp);
	if(temp == p->right){
		p->right = temp->right;
	}
	else{
		temp_prev->left = temp->right;
	}
}
void level(tree t){
	queue q;
	qinit(&q);
	node *temp;
	if(t == NULL)
		return;
	enq(&q, t);
	while(!qempty(&q)){
		temp = deq(&q);
		printf("%s ",temp->str);
		if(temp->left)
			enq(&q, temp->left);
		if(temp->right)
			enq(&q, temp->right);
	}
	printf("\n");
}
char *max(tree t){
	if(t == NULL)
		return NULL;
	char *str;
	int result;
	str = (char *)malloc(strlen(t->str) + 1);
	strcpy(str, t->str);
	queue q;
	qinit(&q);
	node *temp;
	enq(&q, t);
	while(!qempty(&q)){
		temp = deq(&q);
		result = strcmp(temp->str,str);
		if(result > 0){
			str = (char *)realloc(str,strlen(temp->str) + 1);
			strcpy(str, temp->str);
		}  
		if(temp->left)
			enq(&q, temp->left);
		if(temp->right)
			enq(&q, temp->right);
	}
	return str;
}
char *search(tree t, char *str){
	if(t == NULL)
		return NULL;
	node *p;
	int result;
	p = t;
	while(p){
		result = strcmp(p->str, str);
		if(result < 0){
			p = p->right;
		}
		else if(result > 0){
			p = p->left;
		}
		else{
			break;
		}
	}
	if(!p){
		return NULL;
	}
	return p->str;
}
void preorder_norecur(tree t){
	if(t == NULL)
		return;
	stack s;
	node *temp;
	sinit(&s);
	push(&s, t);
	while(!isempty(&s)){
		temp = pop(&s);
		printf("%s \t",temp->str);
		if(temp->right){
			push(&s, temp->right);
		}
		if(temp->left){
			push(&s, temp->left);
		}
	}
} 
	
 
			
			
			
				
	
	
