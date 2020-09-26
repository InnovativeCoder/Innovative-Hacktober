#include<iostream>
using namespace std;
class stackarr
{
        public:
                int stack[6],top;
        stackarr()
        {
         top=-1;
        }
int isempty()
        {
                if(top==-1)
                {
                return 1;
                }
        else
                {
                return 0;
                }
        }
void push(int x)
                {
                top++;
                stack[top]=x;
               }
void pop()
                {
                int y=stack[top];
                top--;
                }
void display()
        {
                for(int i=0;i<=top;i++)
                {
                cout<<stack[i]<<"\t";
                }
   }
};
int main()
        {
        stackarr s;
        s.push(111);
        int epy=s.isempty();
                if(epy==1)
                cout<<"!!!!!Empty Stack!!!!!"<<endl;
                else
                cout<<"!!!! Stack has values!!!!"<<endl;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        s.pop();
        s.pop();
        s.push(60);
        s.display();
        }
