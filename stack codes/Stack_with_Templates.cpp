#include<iostream>
using namespace std;
template<typename t>
class stacktemp{
   t *data;
   int nextindex;
   int capacity;
   public:
       stacktemp(){
          data=new t[4];
          nextindex=0;
          capacity=4;
       }
       int size(){
       return nextindex;
       }
       bool isEmpty(){
          return nextindex==0;
       }
       void push(t element){
          if(nextindex==capacity){
            t *newdata=new t[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            data=newdata;
          }
          data[nextindex]=element;
          nextindex++;

       }
       t pop(){
           if(size()>=0){
            nextindex--;
            return data[nextindex];
           }
           else{
            cout<<"stack is empty"<<endl;
            return 0;
           }
       }
       t top(){
           if(size()>=0){

            return data[nextindex-1];
           }
           else{
            cout<<"stack is empty"<<endl;
            return 0;
           }
       }
};
int main(){
stacktemp<char> s;
  s.push(100);
  s.push(101);
  s.push(102);
  s.push(103);
  s.push(104);
  s.push(105);
  cout<<s.top()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.isEmpty()<<endl;
  cout<<s.size()<<endl;

}
