#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
	char Firstname[20];
	char Lastname[20];
	int age;
};
struct employee emp[10];

int readfile(struct employee *emp);
int merge(struct employee *emp , int lower_bound , int upper_bound);
int merge_sort(struct employee *emp , int lower_bound , int mid , int upper_bound);
void print_data(struct employee *emp , int size);
void write_in_file(struct employee *emp , int size);
int main()
{
	int size,lower_bound , upper_bound = 0;
	lower_bound = 0;
	
	size = readfile(emp);

	upper_bound = size;

	merge(emp , lower_bound , upper_bound);
	write_in_file(emp , size);
	print_data(emp , size);

}
int readfile(struct employee *emp)
{
	FILE *fp;
	int i = 0;

	fp = fopen("emp.txt","r");

	if (fp == NULL)
	{
		printf("Couldn't open the File::\n");
		exit(0);
	}

	while((fscanf(fp,"%s %s %d" ,emp[i].Firstname , emp[i].Lastname , &emp[i].age)) != EOF)
	{
		printf("%s %s %d\n",emp[i].Firstname , emp[i].Lastname , emp[i].age);
		i++;
	}
	printf("\n");

	return (i-1);
}
int merge(struct employee *emp , int lower_bound , int upper_bound)
{
	int mid = 0;

	if (lower_bound < upper_bound)
	{
		mid = (lower_bound + upper_bound)/2;
		merge(emp , lower_bound , mid);
		merge(emp , mid+1 , upper_bound);
		merge_sort(emp ,lower_bound , mid , upper_bound);
	}

	return 0;
}
int merge_sort(struct employee *emp , int lower_bound , int mid , int upper_bound)
{
	int i , j , k;
	struct employee temp[10];

	i = lower_bound;
	j = mid + 1;
	k = 0;

	while (i<=mid && j<=upper_bound)
	{
		if (strcmp(emp[i].Firstname ,emp[j].Firstname) < strcmp(emp[j].Firstname,emp[j].Firstname))
		{
			temp[k] = emp[i];
			i++,k++;
		}

		else
		{
			temp[k] = emp[j];
			j++,k++;
		}
	}


	while (i <= mid)
	{
		temp[k] = emp[i];
		i++,k++;
	}

	while (j <= upper_bound)
	{
		temp[k] = emp[j];
		j++,k++;
	}

	for(i=lower_bound,j=0; i<=upper_bound; i++,j++)
	{
		emp[i] = temp[j];
	}

	return 0;
}

void write_in_file(struct employee *emp , int size)
{
	FILE *fp;
	int i;

	fp = fopen("Sorting.txt","w");

	if (fp == NULL)
	{
		printf("Couldn't open the File:::\n");
		exit(0);
	}
	
	for(i=0; i<size; i++)
	{
		fprintf(fp,"%s %s %d\n",emp[i].Firstname , emp[i].Lastname , emp[i].age);
	}

}
void print_data(struct employee *emp , int size)
{
	int i;

  printf("Displaying Sorted Data:::\n");
	for(i=0; i<=size; i++)
	{
		printf("Name = %s %s, Age = %d\n",emp[i].Firstname , emp[i].Lastname , emp[i].age);
	}

}

	