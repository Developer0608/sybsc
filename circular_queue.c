#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int queue[CAPACITY],front=-1,rear=-1;

void accept(int element);
void deletee();
void display();
void peek();
int main()
{
  int choice, element;

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
  if(rear == -1 && front == -1)
  {
    front = rear = 0;
    queue[rear] = element;
  }

  else if((rear+1)%CAPACITY == front)
  {
    printf("Queue is Full:::\n");
  }

  else
  {
    rear = (rear + 1)%CAPACITY;
    queue[rear] = element;
  }
}

void deletee()
{
  if(front == -1 && rear == -1)
  {
    printf("Queue is Empty::\n");
  }

  else if(front == rear)
  {
    printf("Deleted Element is :::: %d\n",queue[front]);
    rear = front = -1;
  }

  else
  {
    printf("Deleted Element is :::: %d\n",queue[front]);
    front = (front + 1)%CAPACITY;
  }
}

void display()
{
  int i=front;

  printf("Queue Elements are:::\n");
  while(i <= rear)
  {
    printf("%d ",queue[i]);
    i = (i + 1)%CAPACITY;
  }
  printf("\n");
}

void peek()
{
  if(front == -1 && rear == -1)
  {
    printf("Queue is Empty::\n");
  }

  else
  {
    printf("Peek Element is :::: %d\n",queue[front]);
  }
}
