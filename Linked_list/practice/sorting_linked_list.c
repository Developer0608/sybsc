#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *link;
};

struct node *head = NULL;

int read_list();
void print_unsorted_list();
void sorting_list(int size);
int main()
{
  int size;

  size = read_list();
  print_unsorted_list();
  sorting_list(size);
  print_unsorted_list();
}

int read_list()
{
  struct node *temp, *p;
  int i=0;

  while(1)
  {
    printf("Enter the data into the Linked List:::\n");

    temp = (struct node *)malloc(sizeof(struct node *));
    scanf("%d",&temp->data);
    
    if(temp->data == 0)
    {
      break;
    }
    if(head == NULL)
    {
      head = temp;
      p = head;
    }

    else
    {
      p->link = temp;
      p = temp;
    }
    i++;
  }

  return i;
}

void print_unsorted_list()
{
  struct node *temp;

  temp = head;
  while(temp != NULL)
  {
    printf("%d ",temp->data);
    temp = temp->link;
  }

  printf("\n");
}

void sorting_list(int size)
{
  struct node *temp, *p;
  int i, j, data, element;

  temp = p = head;

  p = temp = head;
  for(i=0; i<size; i++)
  {
    for(j=0; j<size-2; j++)
    {
      if(p->data > p->link->data)
      {
        element = p->data;
        p->data = p->link->data;
        p->link->data = element;
      }
      p = p->link;
    }

    p = temp->link;
  }
}