
#include<iostream>
using namespace std;
class stackarray{
    int *data;
    int nextindex;
    int capacity;
    public:
    stackarray(){
        data=new int[4];
        capacity=4;
        nextindex=0;

    }
    int size1(){
        return nextindex;

    }
    bool isEmpty(){
        return (nextindex==0);
    }
    void push(int x){
        if(nextindex==capacity){
                int *newdata=new int[2*capacity];
                for(int i=0;i<capacity;i++){
                    newdata[i]=data[i];
                }
                capacity*=2;
                delete[] data;
                data=newdata;

        }
        data[nextindex]=x;
        nextindex++;


    }
    int pop(){
        if(nextindex==0){
            cout<<"underflow";
            return -1;
        }
        nextindex--;
        return data[nextindex];


    }
    int top(){
        if(nextindex>0){
                return data[nextindex-1];

        }
    }

};


int main(){
    stackarray s;
    //stackarray s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(9);
    s.push(23);
    cout<<s.top()<<endl;
    cout<<s.size1()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;






}
