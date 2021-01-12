#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int main()
{
  struct node *temp,*temp1, *p;
  int n, i, size, loc;
  printf ("Enter the size of linked list: ");
  scanf("%d",&size);
    
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

  printf("Enter the location to delete:  ");
  scanf("%d", &loc);
  
  printf("\n");

  if(size < loc)  
  { 
    printf("Invalid location... \n");
  }
  else
  {
    i = 1;
    p = head;
    while( i < loc-1)
    {
      p = p->next;
      i++;  
    }
    
    temp1 = p->next; 
    p->next = temp1->next;
    temp1->next = NULL;      
    free(temp1);
  }
  
  printf("Displaying the all the elements of the linked list:: \n"); 
  
  temp = head;
  while(temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }

  return 0;   
} 
 //  
 //  