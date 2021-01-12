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
	struct node *temp , *p , *temp1;
	int size , i , location;

	printf("Enter the size of the Linked List::\n");
	scanf("%d",&size);

	for(i=0; i<size; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node *));

		printf("Enter the element of the Linked List::\n");
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

	printf("Enter the Element Location where you wanna enter the Node ::\n");
	scanf("%d",&location);

	if (location > size)
	{
		printf("Invalid Location :::\n");
	}

	else
	{
		p = head; 
		i=1;
		while (i < location-1)
		{
			p = p->right;
			i++;
		}

		temp = p->right;

		temp1 = (struct node *)malloc(sizeof(struct node *));
		printf("Enter the Element into the Linked List::\n");
		scanf("%d",&temp1->data);

		temp1->right = temp;
		p->right = temp1;
    temp->left = p;
    temp->left = temp1;
	}

	printf("Displaying The elements of the Linked List::\n");
	temp = head;

	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->right;

	}

	return 0;
}
