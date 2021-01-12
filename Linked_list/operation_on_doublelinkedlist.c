#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *head = NULL;

void add();
int length();
void add_at_begin();
void add_at_middle();
void add_at_last();
void display();
int main()
{
	int choice , len;

	while(1)
	{
		
		printf("1. Add Elements in Linked list::\n");
		printf("2. Length of Linked list::\n");
		printf("3. Add at Beginning of the Linked list::\n");
		printf("4. Add at Middle of the Linked list::\n");
		printf("5. Add at Last of the Linked list::\n");
		printf("6. Delete a Node from the Linked list::\n");
		printf("7. Displaying The Elements of the Linked list::\n");
		printf("8. Exit::\n");

		printf("Enter your Choice::\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				add();
				printf("\n");
				break;

			case 2:
				 len = length();
				 printf("Length of the Linekd list is :: %d\n\n",len);
				 break;

			case 3:
				 add_at_begin();
				 printf("\n");
				 break;

			case 4:
				 add_at_middle();
				 break;

			case 5:
				 add_at_last();
				 break;

			case 6:
				 //delete();
				 break;

			case 7:
				display();
				printf("\n");
		       		break;			
			
			case 8:
				 exit(0);

			default:
				 printf("Invalid Selection::\n");
		}
	}

	return 0;
}
void add()
{
	struct node *temp , *p;
	int size , i;

	printf("Enter the size of the Linked list::\n");
	scanf("%d",&size);

	for(i=0; i<size; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node *));
		printf("Enter the element::\n");
		scanf("%d",&temp->data);

		if (head == NULL)
		{
			head = temp;
		}

		else
		{
			p = head;
			while (p->right != NULL)
			{
				p = p->right;
			}
			p->right = temp;
			temp->left = p;
		}
	}
	printf("\n");
}

int length()
{
	struct node *temp;
	int i=0;

	temp = head;

	while (temp != NULL)
	{
		i++;
		temp = temp->right;
	}

	return(i);
}

void add_at_begin()
{
	struct node *temp;

	printf("Enter the element of the Linked list::\n");
	scanf("%d",&temp->data);

	temp->right = head;
	head->left = temp;
	head = temp;
	printf("\n");

}

void add_at_middle()
{
  struct node *p , *temp , *temp1;
  int location , i;

  printf("Enter the location where you wanna insert new node::\n");
  scanf("%d",&location);

  if (location > length())
  {
    printf("Invalid Location:::\n");
  }

  else
  {
    p = head;
    i = 1;
    while (i < location-1)
    {
      p = p->right;
      i++;
    }

    temp = p->right;

    temp1 = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the element into the Linked list::\n");
    scanf("%d",&temp1->data);

    temp1->right = temp;
    p->right = temp1;
    temp1->left = p;
    temp->left = temp1;
  }

}
  

void add_at_last()
{
	struct node *temp , *p;

	temp = (struct node *)malloc(sizeof(struct node *));	
	printf("Enter the element to be added at the Last of the Linked list::\n");
	scanf("%d",&temp->data);

	p = head;

	while (p->right != NULL)
	{
		
    p = p->right;
    
	}

	p->right = temp;
	temp->left = p;
	printf("\n");
}


void display()
{
	struct node *temp;

	temp = head;

	printf("Displaying the Contents of the Linked List::\n");
	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->right;
	}
	printf("\n");
}

	
