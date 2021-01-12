#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};
struct node *head = NULL;

void create();
void addatlast();
void beginning();
void middle();
void display();
int length();
void delete();
int main()
{	
	int choice;


	head = (struct node *)malloc(sizeof(struct node *));
	
	while(1)
	{

    printf("1. Create the Linked list:::\n");
		printf("2. Add at Last:\n");
		printf("3. Add at Begin:\n");
    printf("4. Add at middle:\n");
		printf("5. Display:\n");
		printf("6. Length:\n");
		printf("7. Delete a node:\n");
		printf("8. Quit From The Program:\n");
		printf("\n");
		printf("Enter your choice::\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				create();
				printf("\n");
				break;

			case 2:
				addatlast();
				printf("\n");		
				break;

			case 3:
				beginning();
				printf("\n");
				break;

			case 4:
				middle();
				printf("\n");
				break;

			case 5:
				display();
				printf("\n");
				break;

			case 6:
				printf("\nLength of the linked list is ::: %d\n\n",length());
				break;

			case 7:
				delete();
				break;
				
			case 8:
				exit(0);

			default:
				printf("Invalid Argument::\n");
		}
	}

	return 0;
}
void create()
{
	int element , size , i;
	struct node *temp = NULL , *newnode = NULL;

	printf("Enter how many elements you wanna enter into the linked list::\n");
	scanf("%d",&size);

	head = NULL;

	newnode = (struct node *)malloc(sizeof(struct node *));
	for(i=0; i<size; i++)
	{
		printf("Enter the element into the linked list::\n");
		scanf("%d",&element);

		if (head == NULL)
		{
			head = (struct node *)malloc(sizeof(struct node *));
			head->data = element;
			head->link = NULL;
			newnode->link = head;
			newnode = head;
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->data = element;
			temp->link = NULL;
			newnode->link = temp;
			newnode = temp;
		}
	}

}
void display()
{
	struct node *temp;

	printf("Displaying the elements of the linked list::\n");
	temp = head;

	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp ->link;
	}
}
void addatlast()
{
	struct node *temp , *p;
	int element,i=1;

	printf("Element you wanna enter in the last:::\n");
	scanf("%d",&element);

	temp = head;

	while (i < length())
	{
		temp = temp->link;
		i++;
	}

	p = (struct node *)malloc(sizeof(struct node *));
	p->data = element;
	temp->link = p;
	p->link = NULL;
}


int length()
{
	struct node *temp;
	int count=1;
	
	temp = head;

	while(temp->link != NULL)
	{
		count++;
		temp = temp->link;
	}

	return count;
}
void beginning()
{
	struct node *temp;
	int element,i;

	printf("Enter the element at the beginning of the linked list::\n");
	scanf("%d",&element);

	temp->data = element;
	temp->link = head;
	head = temp;

}
void middle()
{
	struct node *temp , *p;
	int element , i , location;

	printf("Enter the location where you want to insert the node ::\n");
	scanf("%d",&location);

	if(location > length())
	{
		printf("Invalid Location :::\n");
		printf("Size of the Linked List is :::: %d\n",length());
	}

	else
	{
		p = head;
		i = 1;
		while (i < location-1)
		{
			p = p->link;
			i++;
		}

		temp = (struct node *)malloc(sizeof(struct node *));
		printf("Enter the element :::\n");
		scanf("%d",&element);

		temp->data = element;
		temp->link = p->link;
		p->link = temp;
	}
}
void delete()
{
	struct node *temp , *p;
	int element , i , location;

	printf("Enter the location from where you wanna delete the node ::\n");
	scanf("%d",&location);

	if (location > length())
	{
		printf("Invalid Location::\n");
	}

	else if (location == 1)
	{
		head = head->link;
	}
	
	else
	{
		temp = head;
		i = 1;
		while (i < location-1)
		{
			temp = temp->link;
			i++;
		}

		p = temp->link;
		temp->link = p->link;
		p->link = NULL;
		free(p);
	}
}


