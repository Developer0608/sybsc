#include<stdio.h>
#include<stdlib.h>
struct node 
{
  int data;
  struct node *link;
};

struct node *head = NULL;
int front= -1, rear= -1;

void accept(int element);
void deletee();
void display();
void peek();
int main()
{
  int choice,element;

  while(1)
  {
    printf("1. Add a Element into the Queue::\n");
    printf("2. Delete the Element::\n");
    printf("3. Display the Element:::\n");
    printf("4. Peak Element:::\n");
    printf("5. Quit::\n");

    printf("Enter the choice:::\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
              printf("Enter the Element to be added::\n");
              scanf("%d",&element);
              
              accept(element);
              break;

      case 2:
              deletee();
              break;

      case 3:
              display();
              break;

      case 4:
              peek();
              break;

      case 5:
              exit(0);

      default:
              printf("Invalid Choice:::\n");

    }
  }
}

void accept(int element)
{
  struct node *temp, *p;

  while(1)
  {
      printf("Enter the element into the ");
  }
}