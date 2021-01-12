#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int queue[CAPACITY],front= -1, rear= -1;

void add(int element);
void deletee();
void display();
void peek();
int full();
int empty();
int main()
{
  int choice , element;

  while(1)
  {
    printf("1. Add Element into Queue::\n");
    printf("2. Delete a Element::\n");
    printf("3. Display the Queue\n");
    printf("4. Peek Element\n");
    printf("5. Quit\n");

    printf("Enter the choice:::\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
              printf("Enter the element to be add :::\n");
              scanf("%d",&element);
              add(element);
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

void add(int element)
{
  if(full())
  {
    printf("Queue is Full:::\n");

  }

  else if(rear == -1 && front == -1)
  {
    front = rear = 0;
    queue[rear] = element;
  }

  else if(rear == CAPACITY-1)
  {
      rear = 0;
      queue[rear] = element;
  }

  else
  {
    rear++;
    queue[rear] = element;
  }
}

void deletee()
{
  if(empty())
  {
    printf("Queue is Empty:::\n");
  }

  else if(front == CAPACITY-1)
  {
      printf("Deleted Element is :::: %d\n",queue[front]);
      front = 0;
  }

  else if(front == rear)
  {
      printf("Deleted Element is ::: %d\n",queue[front]);
      front = rear = -1;
  }

  else
  {
    printf("Deleted Element is ::: %d\n",queue[front]);
    front++;
  }
}

void peek()
{
  if(empty())
  {
    printf("Queue is Empty::\n");
  }

  else
  {
    printf("Peak Element is :::: %d\n",queue[front]);
  }
}

void display()
{
  int i;

  printf("Displying the Elements of the Queue:::\n");
  for(i=front; i<=rear; i++)
  {
    printf("%d ",queue[i]);
  }
  
}
int full()
{
  if((front == rear + 1) || (CAPACITY == rear+1))
  {
    return 1;
  }

  return 0;
}

int empty()
{
  if(rear == -1 && front == -1)
  {
    return 1;
  }

  return 0;
}