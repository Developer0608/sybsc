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
void traversal(struct node *temp);
void pre_order(struct node *temp);
void post_order(struct node *temp);
int main()
{
  struct node *temp;
  int size;

  read_tree();
  
  traversal(head);
  printf("\n");
  
  pre_order(head);
  printf("\n");

  post_order(head);
  printf("\n");

}

void read_tree()
{
  struct node *temp, *parent, *current;

  while(1)
  {
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the Data into the Binary Tree::\n");
    scanf("%d",&temp->data);
    temp->right = NULL;
    temp->left = NULL;
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

void traversal(struct node *temp)
{
    if(temp == NULL)
    {
       return;
    }

    traversal(temp->left);
    printf("%d ",temp->data);
    traversal(temp->right);
}

void pre_order(struct node *temp)
{
  if(temp == NULL)
  {
      return;
  }

  printf("%d ",temp->data);
  pre_order(temp->left);
  pre_order(temp->right);
}

void post_order(struct node *temp)
{
  if(temp == NULL)
  {
    return;
  }

  post_order(temp->left);
  post_order(temp->right);
  printf("%d ",temp->data);
}
 