#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *prev;
   struct node *next;
};
void insert_head(struct node**, int);
void insert_tail(struct node **, int);
void delete_node(struct node**, int);
void insert_pos(struct node **,int ,int);
void delete_pos(struct node**, int); 
void display(struct node*);
void delete_last(struct node **);
void delete_first(struct node **);
int main()
{
  struct node *first;
  first=NULL;
  int x,ch,pos;
  while(1)
  {
    display(first);
    printf("\n1..Insert Head..\n");
    printf("2..Insert Tail..\n");
    printf("3..Delete First..\n");
    printf("4..Delete Last..\n");
    printf("5..Delete node..\n");
    printf("6..Delete at position\n");
    printf("7..Insert at position\n");
    scanf("%d",&ch);

    switch(ch)
    {
       case 1: printf("Enter the value..\n");
               scanf("%d",&x);
               insert_head(&first,x);
               break;
        case 2: printf("Enter the value..\n");
               scanf("%d",&x);
               insert_tail(&first,x);
               break;
        case 3:delete_first(&first);
                break;
         case 4:delete_last(&first);
                break;
         case 5: printf("Enter the value..\n");
               scanf("%d",&x);
               delete_node(&first,x);
               break;
        case 6: printf("Enter the position..\n");
               scanf("%d",&x);
               delete_pos(&first,x);
               break;
        case 7: printf("Enter the value and position..\n");
               scanf("%d %d",&x,&pos);
               insert_pos(&first,x,pos);
               break;
    }

  }
}
  void insert_pos(struct node **p ,int x,int pos)
  {
    struct node *temp,*q;
    int i;
     temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp->prev=NULL;
    i=1;
    q=*p;
    while((q->next!=NULL)&&(i<pos))
    {
       q=q->next;
      i++;
     }
    if(q->next!=NULL)//position found
    {
      if(q->prev==NULL)//insert before th first node
      {
        temp->next=q;
        q->prev=temp;  
       *p=temp;
      }
    else
     {
       //position somewhere in between
       //not the last but one position
       q->prev->next=temp;
       temp->prev=q->prev;
       temp->next=q;
       q->prev=temp;
     }
   }
   else//q->next==NULL
   {
     if(i==pos)//insert at last but one position
      {
       q->prev->next=temp;
       temp->prev=q->prev;
       temp->next=q;
       q->prev=temp;
      }
     else if(i==pos-1)//insert after the last node
      {
        q->next=temp;
        temp->prev=q;
      }
     else
      printf("Invlid position");
   }
 }  

 
  void delete_first(struct node **p)
  {
     struct node *q;
     //check if only one node is in the list
     q=*p;
    if((q->prev==NULL)&&(q->next==NULL)) 
       *p=NULL;
    else
      {
         *p=q->next;
         (*p)->prev=NULL;
     }
    free(q);
  }      

  void delete_last(struct node **p)
  {
     struct node *q;
     //check if only one node is in the list
     q=*p;
    if((q->prev==NULL)&&(q->next==NULL)) 
       *p=NULL;
    else
    {
       while(q->next!=NULL)
          q=q->next;
       q->prev->next=NULL;
        free(q);
     }
   }

  void delete_pos(struct node**p, int pos)
  {
    struct node *q;
    int i;
    q=*p;
    
   //move forward until the position is found
   i=1;
   while((q!=NULL)&&(i<pos))
    {
      q=q->next;
      i++;
    }


   if(q!=NULL)//position found
   {
    //if the list has only one node and that is being deleted 
     if((q->next==NULL)&&(q->prev==NULL))
       *p=NULL;
    else if(q->prev==NULL)//first position
    {
      *p=q->next;
       (*p)->prev=NULL;
    }
   else if(q->next==NULL)// last position   
      q->prev->next=NULL;
   else//deleting somewhere in middle
    {
     q->prev->next=q->next;
     q->next->prev=q->prev;
    }
  }
 else //q==NULL
   printf("Invalid Position..\n");
 }










  void delete_node(struct node**p, int x)
  {
    struct node *q;
    q=*p;

   //move forward until the node is found
    while((q!=NULL)&&(q->data!=x))
      q=q->next;
   if(q!=NULL)//node found
   {
    //if the list has only one node and that is being deleted 
     if((q->next==NULL)&&(q->prev==NULL))
       *p=NULL;
    else if(q->prev==NULL)//first node being deleted
    {
      *p=q->next;
       (*p)->prev=NULL;
    }
   else if(q->next==NULL)// last node being deleted    
      q->prev->next=NULL;
   else//deleting somewhere in middle
    {
     q->prev->next=q->next;
     q->next->prev=q->prev;
    }
  }
 else //q==NULL
   printf("Node not found..\n");
 }

  
 


  void insert_tail(struct node **p, int x)
  {
    struct node *temp,*q;
    //create a node
    temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp->prev=NULL;

    //if empty list
     if(*p==NULL)
      *p=temp;
     else
      {
        //go to the last node
        q=*p;
        while(q->next!=NULL)
           q=q->next;
        q->next=temp;//insert at the end
        temp->prev=q;
     }
  }


 void insert_head(struct node**p, int x)
  {
    struct node *temp;
    //create a node
    temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp->prev=NULL;

     //if list empty
    if(*p==NULL)
     *p=temp;
    else
     {
       temp->next=*p;
       (*p)->prev=temp;
       *p=temp;
      }
   }
   
  void display(struct node *p)
  {
    if(p==NULL)
     printf("Empty list..\n");
    else
     while(p!=NULL)
     {
       printf("%d <->",p->data);
       p=p->next;
     }
  }






   












