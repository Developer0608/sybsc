#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *head = NULL;

void insert_tree();
int main()
{
  insert_tree();
}

void insert_tree()
{
  struct node *temp, *parent, *current;

  while(1)
  {
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the data into the Node::\n");
    scanf("%d",&temp->data);

    if(temp->data == 0)
    {
      break;
    }

    if(head == NULL)
    {
      temp = head;
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