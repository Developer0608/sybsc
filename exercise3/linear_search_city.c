#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cities 
{
  char city[20];
  int code;
};
struct cities city_name[100];

int read_city(struct cities *city_name);
int linear_search(struct cities *city_name, int size);
int main()
{
  int size , flag;

  size = read_city(city_name);
  flag = linear_search(city_name, size);

  if (flag == -1)
  {
    printf("City is not present in that List:::\n");
  }

  else
  {
    printf("City is Present at ::: %d Position\n",flag+1);
  }

  return 0;
}
int read_city(struct cities *city_name)
{
  FILE *fp;
  int i=0;

  fp = fopen("cities.txt","r");

  if (fp == NULL)
  {
    printf("Couldn't Open the File:::\n");
    exit(0);
  }

  while(fscanf(fp,"%s %d",city_name[i].city, &city_name[i].code) != EOF)
  {
    printf("%s %d\n",city_name[i].city,city_name[i].code);
    i++;
  }

  printf("\n");
  return i;
}

int linear_search(struct cities *city_name, int size)
{
  char element[10];  
  int i;

  printf("Enter the name of the city to be searched :::: \n");
  scanf("%s",element);

  for(i=0; i<size; i++)
  {
    if (strcmp(element,city_name[i].city) == 0)
    {
      return i;
    }
  }

  return -1;
}
