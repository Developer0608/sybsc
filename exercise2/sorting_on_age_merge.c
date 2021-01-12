#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
  char Firstname[50];
  int age;
};

struct employee emp[10];

int merge(struct employee *emp,int lower_bound , int upper_bound);
int merge_sort(struct employee *emp, int lower_bound , int mid , int upper_bound);
void print_sorted_data(struct employee *emp, int i);
void write_data(struct employee *emp, int size);
int main()
{
  FILE *fp;
  int i=0 , lower_bound , upper_bound;

  fp = fopen("emp.txt","r");

  if (fp == NULL)
  {
    printf("Couldn't open the File:::\n");
    exit(0);
  }

  lower_bound = i;

  printf("Displaying Data Before Sorting the Data:::\n\n");
  while((fscanf(fp,"%s %d", emp[i].Firstname, &emp[i].age)) != EOF)
  {
    printf("%s %d\n",emp[i].Firstname, emp[i].age);
    i++;
  }

  upper_bound = i-1;   

  merge(emp, lower_bound , upper_bound);
  print_sorted_data(emp, i);
  write_data(emp,i);

  fclose(fp);
   
}

int merge(struct employee *emp, int lower_bound , int upper_bound)
{
  int mid , i;
   
  if (lower_bound < upper_bound)
  {
        mid = (lower_bound + upper_bound)/2;
        merge(emp, lower_bound,mid);
        merge(emp, mid+1,upper_bound);
        merge_sort(emp, lower_bound, mid, upper_bound);

      }
  
  return 0;
}

int merge_sort(struct employee *emp, int lower_bound , int mid , int upper_bound)
{
  int i , j , k;

  struct employee temp[50];

  i = lower_bound;
  j = mid + 1;
  k = 0;

  while(i <= mid && j <= upper_bound)
  {
     if(emp[i].age > emp[j].age)
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

   
    while (j <= upper_bound)
    {
      temp[k] = emp[j];
      k++;
      j++; 
    }

    while (i <= mid)
    {
      temp[k] = emp[i];
      i++;
      k++;
    }

  for(i=lower_bound,j=0; i <= upper_bound; i++,j++)
  {
    emp[i] = temp[j];
  }

  return 0;
}

void print_sorted_data(struct employee *emp, int size)
{
  int i;
   
  printf("Displaying the Sorted Data:::\n\n");
  for(i=0; i < size; i++)
  {
      printf("Name = %s , Age =  %d\n",emp[i].Firstname, emp[i].age);
  }
}

void write_data(struct employee *emp , int size)
{
  FILE *fp;
  int i ;

  fp = fopen("File_to_write_data.txt","w");

  if (fp == NULL)
  {
    printf("Unable to Open File to write data::\n");
    exit(0);
  }

  for(i=0; i<size; i++)
  {
    fprintf(fp,"%s %d\n",emp[i].Firstname,emp[i].age);
  }
}