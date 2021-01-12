#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};

struct node *head = NULL;

int main()
{
  int i , j , k=0, temp1;

  struct node *temp, *p, *q;
  
  while(1)
  {
    printf("Enter the node into the Linked List::\n");
    if(head == NULL)
    {
      head = (struct node *)malloc(sizeof(struct node *));
      scanf("%d",&head->data);

      if(head->data == 0)
      {
        break;
      }

      head->link = NULL;
      p = head;
      k++;
    }

    else
    {
      temp = (struct node *)malloc(sizeof(struct node *));
      scanf("%d",&temp->data);

      if(temp->data == 0)
      {
        break;
      }
      temp->link = NULL;
      p->link = temp;
      p = temp;
      k++;
    }

    if(temp->data == 0 || head->data == 0)
    {
      break;
    }
  }

  printf("Length of the String is :::: %d\n",k);
  temp = head;

  if(head->link == NULL)
  {
    printf("No Elements are Present in the Linekd List:::\n");
    return 0;
  }

  printf("Dispalying the Contents of the Linked List:::\n");
  while(temp != NULL)
  {
    printf("%d ",temp->data);
    temp = temp->link;
  }

  printf("\n");

  i = 0;
  j = k-1;
  p = q = head;

  while(i < j)
  {
    k = 0;
    while(k < j)
    {
      q = q->link;
      k++;
    }

    temp1 = q->data;
    q->data = p->data;
    p->data = temp1;
    i++,j--;
    p = p->link;
    q = head;
  }
   
  temp = head;

  while(temp != NULL)
  {
    printf("%d ",temp->data);
    temp = temp->link;
  }

  printf("\n");
}
