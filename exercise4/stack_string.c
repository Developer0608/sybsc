#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CAPACITY 30
int top = -1;
char string[CAPACITY];

void push(char str);
int isfull();
int isempty();
void pop();
void peak();
void length();
void display();
int main()
{
      char stack[CAPACITY];
      int i, j, choice;

      printf("Enter the String:::\n");
      scanf("%s",stack);

      for(i=0; i<strlen(stack); i++)
      {
        push(stack[i]);
      }

      printf("Reverse of the String is::::\n");
      for(i=top,j=0; i>=0; i--,j++)
      {
         stack[j] = string[i];
      }

      printf("%s\n",stack);
      while(1)
      {
        printf("1. Pop\n");
        printf("2. Peak\n");
        printf("3. Length\n");
        printf("4. Display\n");
        printf("5. Quit\n");

        printf("Enter the choice ::::\n");
        scanf("%d",&choice);

        switch(choice)
        {
          case 1:
                  pop();
                  break;

          case 2:
                  peak();
                  break;

          case 3:
                  length();
                  break;

          case 4:
                  display();
                  break;
         
          case 5:
                  exit(0);

          default:
                  printf("Invalid Choice:::\n");
        }
      }



}

void push(char str)
{
  if(isfull())
  {
    printf("Stack is Full Now:::\n");
  }

  top++;
  string[top] = str;
}

int isfull()
{
  if(top == CAPACITY)
  {
    return 1;
  }

  return 0;
}

void pop()
{
  if(isempty())
  {
    printf("String is Empty:::\n");
  }

  printf("The Poped Element is:::: %c\n",string[top]);
  top--;

}

int isempty()
{
    if(top == -1)
    {
      return 1;
    }

    return 0;
}

void length()
{
  printf("Length of the String is ::::: %d\n",top);
}

void display()
{
  int i;

  printf("Displaying the String:::\n");
  for(i=0; i<=top; i++)
  {
    printf("%c",string[i]);
  }
}

void peak()
{
    if(isempty())
    {
      printf("Stack is Empty:::\n");
    
    }

    else
    {
      printf("Peak Element is ::::: %c\n",string[top]);
    }
}
