#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
struct node *head = NULL;

int read_linklist();
void reverse_list(int size);
void print_list();
int main()
{
  int size;

  size = read_linklist();
  reverse_list(size);
  print_list();

}

int read_linklist()
{
    struct node *temp , *p;
    int k = 0;

    while(1)
    {
      printf("Enter the Data into the Node:::\n");

      if (head == NULL)
      {
        head = (struct node *)malloc(sizeof(struct node *));
        scanf("%d",&head->data);

        if(head->data == 0)
        {
          break;
        }

        head->link = NULL;
        p = head;
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
      }
      k++;
    }

    return k;
}

void reverse_list(int size)
{
    struct node *p , *q;
    int i , j , k , temp;

    i = 0;
    j = size - 1;
    p = q = head;

    while(i < j)
    {
      k = 0;
      while(k < j)
      {
        q = q->link;
        k++;
      }

      temp = q->data;
      q->data = p->data;
      p->data = temp;

      i++,j--;
      p = p->link;
      q = head;
    }
}

void print_list()
{
  struct node *temp;

  temp = head;

  printf("Reverse of the Linked List::\n");
  while(temp != NULL)
  {
    printf("%d ",temp->data);
    temp = temp->link;
  }

  printf("\n");
}