#include<stdio.h>
#include<stdlib.h>
int accept_array(int *arr);
void display_array(int *arr, int size);
int linear_search(int *arr, int size);
int main()
{
  int *arr , size, flag;

  arr = malloc(sizeof(int *));

  size = accept_array(arr);
  display_array(arr, size);
  flag = linear_search(arr , size);

  if(flag == -1)
  {
    printf("Element is not present in the array:::\n");
  }

  else
  {
    printf("Element is present at the %d Position:::\n",flag+1);
  }
  
}

int accept_array(int *arr)
{
  int i , size;

  printf("Enter the size of the array:::\n");
  scanf("%d",&size);

  printf("Enter the elements into the array:::\n");
  for(i=0; i<size; i++)
  {
      scanf("%d",&arr[i]);
  }

  return size;
}

void display_array(int *arr, int size)
{
  int i;

  printf("Display the contenets of the Array:::\n");
  for(i=0; i<size; i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int linear_search(int *arr, int size)
{
  int i , element;

  printf("Enter the element to be searched:::\n");
  scanf("%d",&element);

  for(i=0; i<size; i++)
  {
    if (element == arr[i])
    {
      return i;
    }
  }

  return -1;
}