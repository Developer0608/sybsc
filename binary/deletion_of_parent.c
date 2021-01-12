#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *head = NULL;

void read_tree();
void print_tree(struct node *temp);
void delete_node();
int main()
{
  read_tree();
  print_tree(head);
  printf("\n");

  delete_node();
}

void read_tree()
{
  struct node *temp, *parent, *current;

  while(1)
  {
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the node into the Tree::\n");
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
      current = head;
      while(current)
      {
        parent = current;

        if(temp->data > current->data)
        {
          current = current->right;
        }

        else
        {
          current = current->left;
        }
      }

      if(temp->data > parent->data)
      {
        parent->right = temp;
      }

      else
      {
        parent->left = temp;
      }
    }
  }
}

void print_tree(struct node *temp)
{
  if(temp == NULL)
  {
    return;
  }

  printf("%d ",temp->data);
  print_tree(temp->left);
  print_tree(temp->right);
}

void delete_node()
{
  struct node *parent, *current;
  int temp;

  printf("Enter the node to be Deleted:::\n");
  scanf("%d",&temp);

  current = head;                                       
  while(current->left != NULL && current->right != NULL)
  {
    parent = current;
    if(temp > current->data)
    {
      current = current->right;
    }

    else
    {
      current = current->left;
    }
  }

  printf("Current Data::: %d\n",current->data);
  printf("Parent Data::: %d\n",parent->data);
}