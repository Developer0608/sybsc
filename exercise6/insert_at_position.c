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
void add_at_position(int size);
void print_list();
int main()
{
  int size;

  size = read_list();
  add_at_position(size);
  print_list();

}

int read_list()
{
  struct node *temp, *p;
  int i=0;

  while(1)
  {
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the Element into the Linekd List:::\n");
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

void add_at_position(int size)
{
  struct node *temp, *p, *temp1;
  int location, i=1;

  printf("Enter the Location at which you wanna insert the Element:::\n");
  scanf("%d",&location);

  if(location > size)
  {
      printf("Invalid Location:::\n");
      exit(0);
  }
  p = head;
  while(i < location-1)
  {
    p = p->right;
    i++;
  }

  temp1 = (struct node *)malloc(sizeof(struct node *));
  printf("Enter the element to be inserted at that Position::\n");
  scanf("%d",&temp1->data);

  p->right = temp1;
  temp->left = temp1;
  temp1->left = p;
  temp1->right = temp;
}
