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
void add_at_begin();
void print_list();
int main()
{
  int size;
  size = read_list();
  add_at_begin();
  print_list();
}

int read_list()
{
  int i = 0;
  struct node *temp, *p;

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

  temp->right = head;
  head->left = temp;
  return i;
}

void add_at_begin()
{
  struct node *temp, *p;

  printf("Enter the element to be added at Begin:::\n");
  scanf("%d",&temp->data);

  temp->right = head;
  head->left = temp;
  head = temp;
}
void print_list()
{
  struct node *temp;

  temp = head;

  while(temp != NULL)
  {
    printf("%d ",temp->data);
    temp = temp->right;
  }

  printf("\n");
}
