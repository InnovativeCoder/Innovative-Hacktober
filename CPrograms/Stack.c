#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 20
char stack[max];
char exp[20];
char postfix[20];
int top=-1;
int count=0;
void push(char ch);
char pop();
int priority(char ch);
void convert();
void evaluate();
int stack1[max];
void push1(int n);
int pop1();
void main()
{

  printf("Enter an expression: ");
  gets(exp);
  convert();
  printf("Postfix expression is: ");
  puts(postfix);
  evaluate();
  getch();
}
void convert()
{
  int i;
  char ch,c;
  for(i=0;exp[i]!='\0';i++)
  {
    ch=exp[i];
    if(ch=='(')
    {
      push(ch);
    }
    else if(ch==')')
    {
      while(top!=-1&&stack[top]!='(')
      {
	postfix[count]=pop();
	count++;
      }
      c=pop();
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
      while(top!=-1&&stack[top]!='('&&priority(stack[top])>=priority(ch))
      {
	postfix[count]=pop();
	count++;
      }
      push(ch);
    }
    else
    {
      postfix[count]=ch;
      count++;
    }
  }
  while(top!=-1)
  {
    postfix[count]=pop();
    count++;
  }
}
void push(char ch)
{
  if(top==max-1)
  {
    printf("Overflow");
  }
  else
  {
     top=top+1;
     stack[top]=ch;
  }
}
char pop()
{
  char ch1;
  if(top==-1)
  {
    printf("Underflow");
  }
  else
  {
     ch1=stack[top];
     top=top-1;
     return ch1;
  }
}
int priority(char ch)
{
  if(ch=='+'||ch=='-')
  {
    return 0;
  }
  else if(ch=='*'||ch=='/')
  {
    return 1;
  }
}
void evaluate()
{
  int i,n,a,b,c,r;
  char ch;
  for(i=0;i<strlen(postfix);i++)
  {
    ch=postfix[i];
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
      b=pop1();
      a=pop1();
      switch(ch)
      {
	case '+':c=a+b;
		 break;
	case '-':c=a-b;
		 break;
	case '*':c=a*b;
		 break;
	case '/':c=a/b;
		 break;
      }
      push1(c);
    }
    else
    {
      printf("Enter a value for %c: ",ch);
      scanf("%d",&n);
      push1(n);
    }
  }
  r=pop1();
  printf("Result of expression is %d",r);
}
void push1(int n)
{
  if(top==max-1)
  {
    printf("Overflow");
  }
  else
  {
     top=top+1;
     stack1[top]=n;
  }
}
int pop1()
{
  int n;
  if(top==-1)
  {
    printf("Underflow");
  }
  else
  {
     n=stack1[top];
     top=top-1;
     return n;
  }
}
