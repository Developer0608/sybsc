#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head = NULL;

int main()
{
	struct node *temp=NULL , *p=NULL , *temp1=NULL;
	int size , i , location;

	printf("Enter the size of the Linked List::\n");
	scanf("%d",&size);

	for(i=0; i<size; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node *));
		printf("Enter the element into the Linekd List::\n");
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

	printf("Displaying the contents of the Linked List::\n");
	temp = head;

	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->right;
	}

	printf("Enter the Location of Node which to be deleted form Linked List::\n");
	scanf("%d",&location);

	if (location > size)
	{
		printf("Invalid Location:::\n");
		printf("Size of the Linked List is ::: %d\n",size);
	}

	else
	{
		p = head;
		i = 1;
		while (i < location)
		{
			p = p->right;
			printf("I value is ::: %d\n",i);
			i++;
		}

		temp1 = (struct node *)malloc(sizeof(struct node *));
		temp1 = p->right;
		temp = temp1->right;

		p->right = temp;
		temp->left = p;
		free(temp1);
	}

	printf("Displaying after Deleting the Specified Node :::\n");

	temp = (struct node *)malloc(sizeof(struct node *));	
	p = head;
	while (p != NULL)
	{
		printf("%d\n",p->data);
		p = p->right;
	}


	return 0;

}

