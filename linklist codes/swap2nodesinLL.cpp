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
node * swap2nodes(node *head,int m,int n){



    node *temp=head;
    int i,j;
    i=0;
    j=0;
    while(temp!=NULL && i<m-1){
        temp=temp->next;
        i++;

    }

    node *temp1=head;
    while(temp1!=NULL && j<n-1){
        temp1=temp1->next;
        j++;

    }
     if((m-n==1 || n-m==1) && (m==0 || n==0)){
            node *c1,*c2;

            c1=head;
            c2=head->next;
            node *a=c2->next;
            c2->next=c1;
            c1->next=a;
            //head=c2;
            return c2;


    }

    else if(m==0 || n==0){

        node *c1,*p2,*c2;
        c1=head;
        p2=temp1;
        c2=temp1->next;
        node *a=c1->next;
        c1->next=c2->next;
        c2->next=a;
        p2->next=c1;
        head=c2;
        return head;



    }
    else if(m-n==1 || n-m==1){
        node *p1,*c1,*c2;

        p1=temp;
        c1=temp->next;
        c2=temp1->next;
        node *a=c2->next;
        p1->next=c2;
        c2->next=c1;
        c1->next=a;
        return head;


    }


    else{
    node *t1,*t2,*t3,*t4,*t5,*t6;
    t1=temp;
    t2=temp->next;
    t3=t2->next;
    t4=temp1;
    t5=temp1->next;
    t6=t5->next;

    t1->next=NULL;
    t2->next=NULL;
    t4->next=NULL;
    t5->next=NULL;

    t1->next=t5;
   // t5->next=NULL;
  //  t2->next=NULL;

    t5->next=t3;
   // t2->next=NULL;
    t4->next=t2;

    t2->next=t6;
    return head;
    }






}

int main()
{
    node*head=takeinput();
    int m,n;
    cin>>m>>n;
    node* head1=swap2nodes(head,m,n);
    print(head1);



}

