#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *head = NULL;

int insertion_tree();
void print_tree(struct node *temp);
int main()
{
  int height;

  height = insertion_tree();
  print_tree(head);
  printf("\n");
  printf("Total Nodes in the Tree are:::: %d\n",height);
}

int insertion_tree()
{
    struct node *temp, *parent, *current;
    int height=1;  

    while(1)
    {
      temp = (struct node *)malloc(sizeof(struct node *));
      printf("Enter the node into the Tree::\n");
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
          height++;
        }

        else
        {
          parent->left = temp;
          height++;
        }
      }
    }

    return height;
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