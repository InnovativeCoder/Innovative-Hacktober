#include <stdio.h>

struct node 
{
    int val;
    struct node *next;
}*front = NULL,*rear = NULL,*new1,*temp;

void insert()
{
    new1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new1->val);
    new1->next = NULL;
    if(rear == NULL)
        {
            rear = new1;
            front = new1;
        }
    else
        {
            rear->next = new1;
            rear = new1;
        }
}

void delete()
{
    if(front == NULL)
        printf("underflow\n");
    else
        {
            if(front == rear)
            {
                temp = front;
                front = NULL;
                rear = NULL;
                printf("%d is deleted\n",temp->val);
                free(temp);
            }
            else
            {
            temp = front;
            printf("%d is deleted\n",temp->val);
            front = front->next;
            free(temp);
            }
        }
}

void display()
{
    if(front == NULL)
        printf("Empty\n");
    
    for(temp=front;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->val);
    }
    printf("\n");
}

int main()
{
      int ch;
      do
      {
      printf("QUEUE OPERATIONS\n");
      printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&ch);
      
      switch(ch)
      {
          case 1: insert(); break;
          case 2: delete(); break;
          case 3: display(); break;
          case 4: exit(0);
      }
      }while(ch<4);

    return 0;
}
