#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *head = NULL;

int read_list();
int main()
{
  int size;

  size = read_list();
}

int read_list()
{
  struct node *temp, *p;

  while(1)
  {
    printf("Enter the data into the Linked List::\n");
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

    }
  }
}