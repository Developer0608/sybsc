#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *link;
};
struct node *head = NULL;

int read_list();
void print_list(int size);
int middle_element(int size);
int main()
{
   int size, element;

   size = read_list();
   print_list(size);
   element = middle_element(size);

   printf("The Middle Element is :::: %d\n",element);

   return 0;
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

void print_list(int size)
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

int middle_element(int size)
{
  struct node *temp;
  int i=0, element, mid;

  mid = size/2;

  temp = head;
  while(i < mid)
  {
    temp = temp->link;
    i++;
  }

  element = temp->data;

  return element;
}