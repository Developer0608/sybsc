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
int main()
{
  read_list();
  print_list();
}

void read_list()
{
  struct node *temp, *p;

  while(1)
  {
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the node into the List::\n");
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

  printf("%d ",temp->data);
  printf("\n");
}
