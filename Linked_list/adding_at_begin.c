#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};

struct node *head;

int main()
{
	struct node *temp , *p , *temp1;
	int element , size , i;

	printf("Enter the size of the linked list::\n");
	scanf("%d",&size);

	for(i=0; i<size; i++)
	{
		printf("Enter the element:::\n");
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
			p ->link = temp;
			p = temp;
		}
	}

	printf("Adding one more element at the beginning of the linked list:::\n");
	scanf("%d",&element);

	temp1 = (struct node *)malloc(sizeof(struct node *));
	temp1->data = element;
	temp1->link = head;
	head = temp1;


	printf("Now Entering the elements into the linked list:::\n");	
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->link;

	}
	return 0;
}
//  