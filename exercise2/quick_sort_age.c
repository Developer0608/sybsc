#include<stdio.h>
#include<stdlib.h>
struct employee 
{
  char Firstname[20];
  char Lastname[20];
  int age;
};
struct employee emp[10];

int read_file(struct employee *emp);
int quick(struct employee *emp, int lower_bound , int upper_bound);
void print_data(struct employee *emp, int size);
void write_in_file(struct employee *emp , int size);
int main()
{
    int size;

    size = read_file(emp);
    quick(emp, 0, size-1);
    print_data(emp , size);
    write_in_file(emp, size);


}
int read_file(struct employee *emp)
{
  FILE *fp;
  int i=0;

  fp = fopen("emp.txt","r");

  if (fp == NULL)
  {
    printf("Couldn't open the File:::\n");
    exit(0);
  }
  while((fscanf(fp,"%s %s %d",emp[i].Firstname,emp[i].Lastname,&emp[i].age)) != EOF)
  {
    printf("%s %s %d\n",emp[i].Firstname,emp[i].Lastname,emp[i].age);
    i++;
  }

  return (i);
}

int quick(struct employee *emp , int lower_bound , int upper_bound)
{
  int i , j , pivot,k;
  struct employee temp[10];

  if (lower_bound < upper_bound)
  {
      i = lower_bound;
      j = upper_bound;
      pivot = lower_bound;
      k = lower_bound;
      
      while(i < j)
      {
        while(emp[i].age >= emp[pivot].age && i < j)
        {
          i++;
        }

        while(emp[j].age < emp[pivot].age)
        {
          j--;
        }

        if (i < j)
        {
          temp[k] = emp[i];
          emp[i] = emp[j];
          emp[j] = temp[k];
           
        }
      }

        temp[k] = emp[j];
        emp[j] = emp[pivot];
        emp[pivot] = temp[k];
        quick(emp, lower_bound, j-1);
        quick(emp, j+1, upper_bound);
  }

  return 0;
}

void print_data(struct employee *emp , int size)
{
  int i;

  printf("\nDisplaying the Sorted data:::\n");
  for(i=0; i<size; i++)
  {
      printf("%s %s %d\n",emp[i].Firstname,emp[i].Lastname,emp[i].age);
  }
}

void write_in_file(struct employee *emp, int size)
{
  FILE *fp ;
  int i;

  fp = fopen("Sorting.txt","w");

  if (fp == NULL)
  {
    printf("Couldn't open the file:::\n");
    exit(0);
  }

  for(i=0; i<size; i++)
  {
    fprintf(fp,"%s %s %d\n",emp[i].Firstname,emp[i].Lastname,emp[i].age);
  }

  printf("Contents are copied :::\n");
}
