#include<iostream>
using namespace std;
template<typename v>
class node{
public:
    v data;
    //node<t>* next;
    node<v>* next;
    node(v d){
        data=d;
        next=NULL;
    }
};
template<typename t>
class stackLL{
    public:
    node<t>* head;
    int size1;

    stackLL(){
        size1=0;
        head=NULL;

    }
    int getSize(){
        return size1;
    }
    bool isEmpty(){
        return size1==0;
    }
    void push(t elem){
        node<t>* n=new node<t>(elem);
        if(head==NULL){
            head=n;
        }
        else{
            n->next=head;
            head=n;

        }
        size1++;


    }
    t pop(){
        if(size1==0){
                return -1;

        }
        t ans=head->data;
        head=head->next;




        size1--;
        return ans;

    }
    t top(){
        if(size1==0){
                return -1;

        }
        return head->data;


    }



















};

int main(){
    stackLL<int> s;
    s.push(20);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;






}

