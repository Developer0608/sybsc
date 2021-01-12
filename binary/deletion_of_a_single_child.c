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
  
  print_tree(head);
  printf("\n");
}

void read_tree()
{
  struct node *temp, *parent, *current;

  while(1)
  {
    temp = (struct node *)malloc(sizeof(struct node *));

    printf("Enter the Data into the Tree:::\n");
    scanf("%d",&temp->data);
    temp->left = NULL, temp->right = NULL;

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

  printf("Enter the Element of the Node to delete::\n");
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

  if(temp > parent->data)
  {
     if(current->left != NULL)
     {
       parent->left = current->left;
       current->left = NULL;
       free(current);
     }

     else
     {
       parent->left = current->right;
       current->right = NULL;
       free(current);
     }

  }

  else
  {
    if(current->left != NULL)
     {
       parent->left = current->left;
       current->left = NULL;
       free(current);
     }

     else
     {
       parent->left = current->right;
       current->right = NULL;
       free(current);
     }
  }
}