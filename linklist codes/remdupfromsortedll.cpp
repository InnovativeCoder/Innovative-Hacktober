
//Check if a linked list is a palindrome
#include <iostream>
#include<string>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

node* remove_dup(node *head){
    node *c=head;
    //node *n=head->next;
    while(c!=NULL && c->next!=NULL){
            node *n=c->next;
        if(c->data == n->data){
            node* a=n->next;
            n->next=NULL;
            c->next=a;
            free(n);
        }
        else{
        c=c->next;
        }
    }



return head;
}
int main()
{
    node*head=takeinput();

    print(head);
    node* newhead=remove_dup(head);
    print(newhead);
}

