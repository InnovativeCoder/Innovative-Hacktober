#include<iostream>
#include<conio.h>
using namespace std;

class node{
	public:
		int data;
		node *next;
	node(int d){
		data=d;
		next=NULL;
	}
};
	
	void insertatbeg(node *&head,int data){
		node *n=new node(data);
		n->next=head;
		head=n;
	}
	
	void print(node *head){
		while(head!=NULL){
			cout<<head->data<<" ";
			head=head->next;
		}
	}
	
	node *kreverse(node *&head,int k){
		node *c=head;
		node *p=NULL;
		node *n=NULL;
		int count=0;
		while(c!=NULL&&count<k){
			n=c->next;
			c->next=p;
			p=c;
			c=n;
			count++;
		}
		if (n != NULL){
			head->next = kreverse(n, k);
		}
		return p;  
}


int main(){
	node *head=NULL;
	int n,k;
	cin>>n;
	cin>>k;
	int arr[200];
	int i=0;
	while(i<n){
		cin>>arr[i];
		i++;
	}
	int j=n-1;
	while(j>=0){
		insertatbeg(head,arr[j]);
		j--;
	}
	head=kreverse(head,k);
	print(head);
	
	
	return 0;
}
