#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define CAPACITY 20

int top = -1;
char stack[CAPACITY];

void push(char str);
void pop();
void display();
void length();
void peak();
int full();
int empty();
void palindrome();
int main()
{
  char string[CAPACITY];
  int choice , i;


  printf("Enter the String to be Pushed:::\n");
  scanf("%s",string);


  while(1)
  {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Length\n");
    printf("5. Peak\n");
    printf("6. Full\n");
    printf("7. Empty\n");
    printf("8.Palindrome\n");
    printf("9. Quit\n");

    printf("Enter the Choice:::\n");
    scanf("%d",&choice);

    switch(choice)
    {
      	case 1:
                      for(i=0; i<strlen(string); i++)
              	      {
                   	push(string[i]);
                      }
		      break;
      	
      	case 2:
		      pop();
		      break;

      	case 3:
		      display();
		      break;

      	case 4:
		      length();
		      break;
	
	case 5:
		      peak();
		      break;

     	case 6:
		      full();
		      break;

      	case 7:
		      empty();
		      break;

      	case 8:
	   	      palindrome();
		      break;

        case 9:
		      exit(0);

    	default:
		      printf("Invalid Choice:::\n");
    }
  }

  return 0;
}

void push(char str)
{
  if(full())
  {
	  printf("Stack is Fulll:::\n");
  }

  else
  {
  	++top;
  	stack[top] = str;
  }
}

void pop()
{
	if(empty())
	{
		printf("Stack is Empty::::\n");
	}

	else
	{
		printf("Poped Element From ths String is :::: %c\n",stack[top]);
		top--;
	}
}

void display()
{
	int i;

	printf("Displying the Array:::\n");
	for(i=0; i<=top; i++)
	{
		printf("%c",stack[i]);
	}
	printf("\n");
}

void length()
{
	if(empty())
	{
		printf("Stack is Empty:::\n");
	}

	else
	{
		printf("Length of the Stack is :::: %d\n",top);
	}

}

void peak()
{
	if(empty())
	{
		printf("Stack is Empty:::\n");
	}

	else
	{
		printf("Peak Element is :::: %c\n",stack[top]);
	}
}

int full()
{
	if(top == CAPACITY)
	{
		printf("Stack is Full:::\n");
		return 1;
	}

	return 0;
}

int empty()
{
	if(top == -1)
	{
		printf("Stack is Empty:::\n");
		return 1;
	}

	return 0;
}

void palindrome()
{
	char temp[20];
	int i , j;


	for(i=top,j=0; i>=0; i--,j++)
	{
		temp[j] = stack[i];
	}
	printf("\n");

	if(strcmp(temp, stack) == 0)
	{
		printf("String is Palindrome:::\n");
	}

	else
	{
		printf("String in Non-Palindorme:::\n");
	}
}









