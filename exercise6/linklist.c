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
void print_list();
int main()
{
  int size;

  size = read_list();
  print_list();

}
int read_list()
{
    struct node *temp, *p;
    int i=0, value;

    while(1)
    {
       printf("Enter the element in the Linked List::\n");
       temp = (struct node *)malloc(sizeof(struct node *));
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
    value = temp->right->data;
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
