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

int main()
{
	struct employee temp;
	FILE *fp;
	int i=0 , size , j;
	char ch; 
 
	fp = fopen("emp.txt","r");
	
	if(fp == NULL)
	{ 
		printf("\n Cannot open the file \n");
		exit(0);
	}


	while(fscanf(fp,"%s %s %d", emp[i].Firstname, emp[i].Lastname, &emp[i].age) != EOF)
  {
    
		printf("%s %s %d\n", emp[i].Firstname, emp[i].Lastname, emp[i].age);
		i += 1;
	}

	 
 	size = i;	
	
  for(i=0; i<size-1; i++)
	{
     
		for(j=0; j<size-1; j++)
		{
	    if((strcmp(emp[j+1].Firstname,emp[j].Firstname)) < (strcmp(emp[j].Firstname,emp[j+1].Firstname)))
			{
				temp=emp[j];
				emp[j]=emp[j+1];
				emp[j+1]=temp;
			}   
		}
    
	}

	fp = fopen("filesorted.txt","w");
	
	for(i=0; i<size; i++)
	{
		fprintf(fp,"%s %s %d\n", emp[i].Firstname, emp[i].Lastname, emp[i].age);		
	}

  printf("\nDisplaying the Contents of the File After Sorting::\n");
  for(i=0; i<size; i++)
  {
    printf("%s %s %d\n",emp[i].Firstname , emp[i].Lastname , emp[i].age);
  }

	return 0;
}