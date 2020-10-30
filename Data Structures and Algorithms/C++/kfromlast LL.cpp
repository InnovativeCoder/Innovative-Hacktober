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
	
	void insertattail(node *&head,int data){
		if(head==NULL){
			head=new node(data);
			return;
		}
		node *tail=head;
		while(tail->next!=NULL){
			tail=tail->next;
		}
		tail->next=new node(data);
		return;
	}
	
	void print(node *head){
		while(head!=NULL){
			cout<<head->data<<" ";
			head=head->next;
		}
	}
	
	void kfromlast(node *head,int k){
		node *temp1=head;
		node *temp2=head;
		int count=0;
		while(count<k){
			temp1=temp1->next;
			count++;
		}
		while(temp1!=NULL){
			temp1=temp1->next;
			temp2=temp2->next;
		}
		cout<<temp2->data;
	}
	
	int main(){
		node *head=NULL;
		int arr[200];
		int i=true;
		while(i==true){
			cin>>arr[i];
			insertattail(head,arr[i]);
			if(arr[i]==-1){
				break;
			}
		}
		//print(head);
		int k;
		cin>>k;
		kfromlast(head,k);
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
