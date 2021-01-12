#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *left;  
  struct node *right;
};
struct node *head = NULL;
int flag = 0;

void insert_into_tree();
void print_tree(struct node *temp);
void deletion();
struct node *node_search(struct node *temp, int val);
struct node *parent_node(struct node *temp, struct node *child);
int main()
{
  insert_into_tree();
  print_tree(head);
  printf("\n");

  deletion();

  print_tree(head);
  printf("\n");

}

void insert_into_tree()
{
  struct node *temp, *parent, *current;

  while(1)
  {
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the Node to be inserted::\n");
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

void deletion()
{
  struct node *temp, *parent , *child, *present;
  int val;

  printf("Enter the value to be deleted::\n");
  scanf("%d",&val);

  child = node_search(head, val);

  if(flag == 1)
  {
    printf("Child is :::: %d\n",child->data);
  }

  else
  {
    printf("Specified Node is not present:::\n");
    return;
  }

  parent = parent_node(head, child);

  if(flag == 1)
  {
    printf("Parent Node is ::: %d\n",parent->data);
  }

  else
  {
    printf("Parent is Not Present::\n");
  }

  if(child->left == NULL && child->right == NULL)
  {
      if(parent->left == child)
      {
        parent->left = NULL;
      }

      else
      {
        if(parent->right == child)
        {
          parent->right = NULL;
        }
      }

      free(child);
      return;
  }

  if(child->left != NULL && child->right == NULL)
  {
      if(parent->left == child)
      {
        parent->left = child->left;
      }

      else
      {
        if(parent->right == child)
        {
          parent->right = child->left;
        }
      }

      free(child);
      return;
  }

  if(child->left == NULL && child->right != NULL)
  {
    if(parent->left == child)
    {
      parent->left = child->right;
    }

    else
    {
      if(parent->right == child)
      {
        parent->right = child->right;
      }
    }

    free(child);
    return;
  }

  if(child->left != NULL && child->right != NULL)
  {
    if(parent->left == child)
    {
      parent->left = child->right;
      present = child->right;
      present->left = child->left;
    }

    else
    {
      if(parent->right == child)
      {
        parent->right = child->right;
        present = child->right;
        present->left = child->left;
      }
    }

    free(child);
    return;
  }

}

struct node *node_search(struct node *temp, int val)
{

   if(temp == NULL)
   {
     flag = 0;
     return temp;
   }

   if(temp->data == val)
   {
     flag = 1;
     return temp;
   }

   else
   {
     if (val > temp->data)
     {
       return node_search(temp->right, val);
     }

     else
     {
       return node_search(temp->left, val);
     }
   }
}

struct node *parent_node(struct node *temp, struct node *child)
{
    struct node *ptr;
    if(temp == NULL)
    {
      flag = 0;
      return temp;
    }

    if(temp->left == child || temp->right == child)
    {
      flag = 1;
      return temp;
    }

    else
    {
      if(temp->data > child->data)
      {
        ptr = parent_node(temp->right,child);
      }      

      else
      {
        ptr = parent_node(temp->left,child);
      }
    }

    return ptr;
}