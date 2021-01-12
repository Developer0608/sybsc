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
	struct node *temp , *p , *temp1;
	int element , size , i , location;

	printf("Enter the size of the linked list::\n");
	scanf("%d",&size);

	for(i=0; i<size; i++)
	{
		printf("Enter the element in the linked list::\n");
		scanf("%d",&element);

		if (head == NULL)
		{
			head = (struct node *)malloc(sizeof(struct node *));
			head->data = element;
			head->link = NULL;
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
  
	printf("Now Entering the element into the middle:::\n");
	scanf("%d",&location);

	printf("Location is :::: %d\n",location);
	if (location >= size)
	{
		printf("Invalid Location ::\n");
	}


	else
	{
		temp = head;
		i = 1;
		while (i <= location)
		{
			printf("Temp Data ::: %d\n",i);
			temp = temp->link;
			i++;
		}

		p = (struct node *)malloc(sizeof(struct node *));
		p = temp->link;

		printf("Enter the element to be added in the middle:::\n");
		scanf("%d",&element);

		temp1 = (struct node *)malloc(sizeof(struct node *));
		temp1->data = element;
		p->link = temp1->link;
		temp->link = temp1;
	}

	printf("Elements of the linked list::\n");
	temp = head;

	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->link;

	}

	return 0;
}






