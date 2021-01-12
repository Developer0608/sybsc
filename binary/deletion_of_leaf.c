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
void deleete_tree();
int main()
{
  read_tree();
  print_tree(head);
  deleete_tree();
  print_tree(head);
  printf("\n");
}

void read_tree()
{
  struct node *temp, *parent, *current;

  while(1)
  {
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the data into the Binary Tree:::\n");
    scanf("%d",&temp->data);
    temp->left = NULL, temp->right = NULL;
    parent = head;

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

void deleete_tree()
{
  struct node *parent, *current;
  int temp;

  printf("\nEnter the node element to be delete:::\n");
  scanf("%d",&temp);

  current = head;
  while(current->right != NULL || current->left != NULL)
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

  if(temp > parent->data)
  {
    parent->right = NULL;
    free(current);
  }

  else
  {
    parent->left = NULL;
    free(current);
  }
}

