#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int queue[CAPACITY], front = -1, rear= -1;

void add(int element);
void deletee();
void peek();
void traverse();
int empty();
int full();
int main()
{
  int choice, element;

  while(1)
  {
    printf("1. Add Element into Queue\n");
    printf("2. Delete Element From Queue\n");
    printf("3. Peek Element\n");
    printf("4. Traverse\n");
    printf("5. Empty\n");
    printf("6. Full\n");
    printf("7. Quit\n");

    printf("Enter the Choice:::\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
              printf("Enter the Element to be added:::\n");
              scanf("%d",&element);

              add(element);
              break;

      case 2:
              deletee();
              break;

      case 3:
              peek();
              break;

      case 4:
              traverse();
              break;

      case 5:
              empty();
              break;

      case 6:
              full();
              break;

      case 7:
              exit(0);

      default:
              printf("Invalid Choice::\n");

    }
  }
}

void add(int element)
{
    if(full())
    {
       printf("Element is Not Inserted::\n");
    }

    else
    {
      rear++;
      queue[rear] = element;
    }
}

void deletee()
{
  int i;
  if(empty())
  {
    printf("No Element is to Delete:::\n");
  }

  else
  {
    front++;
    printf("The Deleted Element is ::: %d\n",queue[front]);
    queue[front] = queue[front+1];

  }
}

void peek()
{
  if(empty())
  {
    printf("No Peak Element is Present:::\n");
  }

  else
  {
    printf("Peek Element of the Queue is :::: %d\n",queue[rear]);
  }
}

void traverse()
{
  int i;

  for(i=front+1; i<=rear; i++)
  {
    printf("%d ", queue[i]);
  }
  printf("\n");
}
int full()
{
  if(rear == CAPACITY)
  {
    printf("Queue is Full::\n");
    return 1;
  }

  return 0;
}

int empty()
{
  if(front == rear)
  {
    printf("Queue is Empty:::\n");
    return 1;
  }

  return 0;
}
