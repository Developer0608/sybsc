#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL;
int main()
{
  struct node *temp, *p;
  int size, i, n;

  printf("Enter the size of linked list:: ");
  scanf("%d", &size);

  for(i = 0; i < size; i++)
  {
    printf("Enter the element into the linked list:: ");
    scanf("%d", &n);
    printf("\n");

    if(head == NULL)
    {
      head  = (struct node *) malloc (sizeof(struct node *));
      head->data = n;
      head->next = NULL;
      p->next = head;
      p = head;
    }
    else
    {
      temp = (struct node *) malloc (sizeof(struct node *));
      temp->data = n;
      temp->next = NULL;
      p->next = temp;
      p = temp;
    }
  }

  printf("Displaying the elements of the linked list:: \n");
  temp = head;
  while(temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  } 

  printf("Enter the element to be added at the end of the linked list:: ");
  scanf("%d", &n);
  temp = head; 
   
  i = 1;
  while(i < size)
  {
    temp = temp->next;
    i++;
  }

  printf("temp element : %d\n", temp->data);

  p = (struct node *) malloc (sizeof(struct node *));
  p->data = n;
  temp->next = p;
  p->next = NULL;

  temp = head;

  printf("Displaying linked list adding new element at last:: \n");
  while(temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
  
  return 0;
}
   