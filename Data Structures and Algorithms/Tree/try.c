#include"tree.h"
#include<stdio.h>
int main(){
	char str[50];
	tree t;
	init(&t);
	while(scanf("%s",str) != -1){
		insert(&t,str);
		printtree(t);
		printf("\n");
	}
	preorder(t);
	preorder_norecur(t);
	
	
	
	
	return 0;
}
