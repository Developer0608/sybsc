#include<stdio.h>
#include<stdlib.h>
void atbegin();
int length(); 
struct node
{
  int data;
  struct node *next;
};
struct node *head;
int main()   
{            
  atbegin(); 
  printf("Length of the list is: %d\n", length());
  return 0;
}
void atbegin( )
{
  struct node *temp, *temp1, *temp2, *p;
  int n;

  printf("Enter the elements in list: ");
  
  if(head == NULL)
  {
    temp = (struct node *) malloc (sizeof(struct node *));
    scanf("%d", &temp->data);
    temp->next = head;
    head = temp;
    p = temp;
  }
  while(1)
  {
    temp1 = (struct node *) malloc (sizeof(struct node* ));
    scanf("%d", &temp1->data);
    if(temp1->data == 0)  
    {
      break;
    }
    temp1->next = NULL;
    p->next = temp1;
    p = temp1;
  }

  printf("Enter new element to be added at the beginning :: ");
  scanf("%d", &n);
  
  temp2 = (struct node *) malloc (sizeof(struct node *));
  temp2->data = n;
  temp2->next = head; 
  head = temp2;

  printf("Displaying linked list adding new element at beginning: \n");
  temp = head;

  while(temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}
 
int length()
{
  int count = 0;
  struct node *temp = head; 

  while( temp != NULL) // this is not a good practice to use a lot of pointers 
  {
    temp = temp->next;
    count++;
  }
  return count;
}
