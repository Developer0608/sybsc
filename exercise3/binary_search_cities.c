#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct code
{
  char city[20];
  int pin;
};
struct code cities[100];

int read_file(struct code *cities);
int sort_cities(struct code *cities, int size);
void display(struct code *cities, int size);
int binary_search(struct code *cities, int size);
int main()
{
  int size , flag;

  size = read_file(cities);
  sort_cities(cities, size);
  display(cities, size);
  flag = binary_search(cities, size);

  if (flag == 0)
  {
    printf("Citi is Not Present in that List:::\n");
    exit(0);
  }

  else
  {
    printf("City is Present at %d Position::",flag+1);
  }

  return 0;
}

int read_file(struct code *cities)
{
  int i=0;
  FILE *fp;

  fp = fopen("cities.txt","r");

  if (fp == NULL)
  {
    printf("Couldn't Open the File:::\n");
    exit(0);
  }

  while(fscanf(fp,"%s %d",cities[i].city, &cities[i].pin) != EOF)
  {
    printf("%s %d\n",cities[i].city,cities[i].pin);
    i++;
  }

  printf("\n");
  return i;
}
int sort_cities(struct code *cities, int size)
{
  int i , j , k=0;
  struct code temp[5];

  for(i=0; i<size; i++)
  {
    for(j=0; j<size-1; j++)
    {
      if(strcmp(cities[j+1].city,cities[j].city) < strcmp(cities[j].city,cities[j+1].city))
      {
        temp[k] = cities[j+1];
        cities[j+1] = cities[j];
        cities[j] = temp[k];
      }
    }
  }
  return 0;
}
void display(struct code *cities, int size)
{
  int i;

  printf("Displying the Cities in the Sorted Manner:::\n");
  for(i=0; i<size; i++)
  {
    printf("%s %d\n",cities[i].city,cities[i].pin);
  }

  printf("\n");
}

int binary_search(struct code *cities, int size)
{
  char element[20];
  int i, j, mid = 0;

  i = 0;
  j = size -1;

  printf("j is :::: %d\n",j);

  printf("Enter the element to be searched in that List:::\n");
  scanf("%s",element);

  while (i < j)
  {
    mid = (i + j)/2;

    if (strcmp(element,cities[mid].city) > 0)
    {
      i = mid + 1;
    }

    else if(strcmp(element,cities[mid].city) < 0)
    {
      j = mid - 1;
    }

    else if (strcmp(element,cities[mid].city) == 0)
    {
      return mid;
    }

  }

  return -1;
}