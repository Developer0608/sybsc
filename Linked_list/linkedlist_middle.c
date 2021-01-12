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
  struct node *p, *temp, *temp1;
  int i, size, location;

  printf("Enter the size of linked list: ");
  scanf("%d", &size);
   
  for(i = 0; i < size; i++)
  {
    
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the element into the linked list:: ");
    scanf("%d", &temp->data);
    printf("\n");
    
    if(head == NULL)
    {
      head = temp;
      head->next = NULL; 
      p = head;
    } 
    
    else 
    {
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

  printf(" Enter the location: ");
	scanf("%d",&location);

	if (location > size)
	{
		printf("Invalid Location \n");
	}
  else 
  {
    i = 1;
    temp = head;
    while(i < location-1) 
    {
      temp = temp->next;
      i++;
    }
     
    p = temp->next;
    temp1 = (struct node *) malloc (sizeof(struct node* ));
       
    printf("Enter the element to be added in middle of list : ");
    scanf("%d", &temp1->data);
    printf("\n");
    
    temp1->next = p;  
    temp->next = temp1;  
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
 