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
void add_at_last(int size);
void print_list();
int main()
{
  int size;

  size = read_list();
  add_at_last(size);
  print_list();
}

int read_list()
{
  struct node *temp, *p;
  int i=0;

  while(1)
  {
    printf("Enter the element into the Linked List:::\n");
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
      p = head;
      while(p->right != NULL)
      {
        p = p->right;
      }

      p->right = temp;
      temp->left = p;
    }
    i++;
  }

  head->left = temp;
  temp->right = head;
  return i;

}

void add_at_last(int size)
{
  struct node *temp, *p;
  int i=0;

  temp = (struct node *)malloc(sizeof(struct node *));
  printf("Enter the element to be added at Last:::\n");
  scanf("%d",&temp->data);

  p = head;
  while(i < size-1)
  {
    p = p->right;
    i++;
  }

  temp->left = p;
  p->right = temp;
  temp->right = head;
  head->left = temp;

}

void print_list()
{
  struct node *temp;

  temp = head;
  while(temp->right != NULL)
  {
    printf("%d ",temp->data);
    temp = temp->right;
  }
  printf("\n");
}
