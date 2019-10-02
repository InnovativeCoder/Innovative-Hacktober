//Check if a linked list is a palindrome
#include <iostream>
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
node *rev(node *head){
    node *c=head;
    node* n=NULL;
    node* p=NULL;
    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}
node *mid(node* head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
    }
    return slow;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool check_palindrome(node *head){
    node* middle=mid(head);
    node *temp=rev(middle);
    print(head);
    print(temp);
    while(head!=NULL && temp!=NULL){
        if(head->data!=temp->data){
            return false;
        }
        head=head->next;
        temp=temp->next;
    }


    return true;
}

int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else
        cout << "false";
    return 0;
}

