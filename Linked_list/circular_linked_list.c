#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *head = NULL;

void read_list();
void print_list();
void add_at_last();
int main()
{
  read_list();
  print_list();
  add_at_last();
  print_list();
}

void read_list()
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
  }

  temp->right = head;
  head->left = p->right;

}

void print_list()
{
  struct node *temp;

   
  temp = head;

  while(temp != head->left)
  {
    printf("%d ",temp->data);
    temp = temp->right;
  }

  printf("%d",temp->data);
  printf("\n");
}

void add_at_last()
{
  struct node *temp, *p, *temp1;

  temp1 = (struct node *)malloc(sizeof(struct node *));
  printf("Enter the Element to be entered at the Last:::\n");
  scanf("%d",&temp1->data);

  p = head->left;
  temp1->left = p;
  p->right = temp1;
  temp1->right = head;
  head->left = temp1;
}
