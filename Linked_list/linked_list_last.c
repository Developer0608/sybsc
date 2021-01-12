#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};

struct node *head = NULL;
int main()
{
	struct node *temp , *p;
	int element , size , i;

	printf("Enter the size of the linekd list::\n");
	scanf("%d",&size);

	for(i=0; i<size; i++)
	{
		printf("Enter the element into the linked list::\n");
		scanf("%d",&element);

		if (head == NULL)
		{
			head = (struct node *)malloc(sizeof(struct node *));
			head->data = element;
			head->link = NULL;
			//p->link = head;
			p = head;
		}

		else
		{
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->data = element;
			temp->link = NULL;
			p->link = temp;
			p = temp;
		}
	}

	printf("Displaying the elements of the linked list::\n");
	temp = head;

	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->link;
	}

	printf("Now entering the data at the last of the linked list::\n");
	scanf("%d",&element);

	temp = head;

	i = 1;

	while(i < size)
	{
		temp = temp->link;
		i++;
	}
	printf("Temp data ::: %d\n",temp->data);

	p = (struct node *)malloc(sizeof(struct node *));
	p->data = element;
	temp->link = p;
	p->link = NULL;

	temp = head;

	printf("Now Again Printitng list after adding the new element at the last::\n");
	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->link;
	}


	return 0;
}


