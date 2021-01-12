#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *link;
};
struct node *head  = NULL;

void push();
void pop();
void peak();
void traverse();
int empty();
int main()
{
  int choice, element;
  while(1)
  {
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Peak\n");
      printf("4. Traverse\n");
      printf("5. Empty\n");
      printf("6. Quit\n");

      printf("Enter the choice:::\n");
      scanf("%d",&choice);

      switch(choice)
      {
         case 1:
                push();
                break;
                
         case 2:
                pop();
                break;

          case 3:
                peak(); 
                break;

          case 4:
                traverse();
                break;

          case 5:
                empty();
                break;

          case 6:
                exit(0); 
          
          default:
                printf("Invalid Choice:::\n");
     }
  }

    return 0;
}
void push()
{
  struct node *temp;

  temp = (struct node *)malloc(sizeof(struct node *));

  printf("Enter the data into the Stack:::\n");
  scanf("%d",&temp->data);

  temp->link = NULL;

  if(head == NULL)
  {
    head = temp;
  }

  else
  {
    struct node *p;
    p = head;

    while(p->link != NULL)
    {
      p = p->link;
    }

    p->link= temp;
  }
}

void traverse()
{
    struct node *temp;
    temp = head;

    while(temp != NULL)
    {
      printf("%d  ",temp->data);
      temp = temp->link;
    }
    printf("\n\n");
}

void pop()
{
    struct node *temp,*p;

    p = temp  =  head;

    if (empty())
    {
      printf("Sorry Stack is Empty:::\n");
    }

    else
    {
      while(temp->link != NULL)
      {
       p = temp;
       temp = temp->link;
      }

      printf("Poped Value is ::::: %d\n",temp->data);
      p->link = NULL;
      free(temp);
    }
}
int empty()
{
   if(head == NULL)
   {
     return 1;
   }

   return 0;
}

void peak()
{
   struct node *temp;
   temp = head;

   while(temp->link != NULL)
   {
     temp = temp->link;
   }

   printf("The Peak Element is ::::: %d\n",temp->data);
}