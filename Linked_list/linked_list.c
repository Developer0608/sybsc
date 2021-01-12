#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};
int main()
{
	struct node *head , *newnode , *temp;
	int i,element,size;

	head = NULL;

	printf("Enter the size of the linked list::\n");
	scanf("%d",&size);

	for(i=0; i<size; i++)
	{
		printf("Enter the element into the linked list:\n");
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

	printf("Displaying the contents of the linked list::\n");
	for(temp= head; temp != NULL;)
	{
		printf("%d\n",temp->data);
		temp = temp->link;
	}

	return 0;
}

