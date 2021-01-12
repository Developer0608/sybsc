#include<stdio.h>
#include<stdlib.h>
int accept_array(int *arr);
void sorting(int *arr , int size);
void display_array(int *arr , int size);
int binary_search(int *arr, int lower, int upper, int element);
int main()
{
  int *arr,size,flag,element;

  arr = malloc(sizeof(int *));

  size = accept_array(arr);
  sorting(arr, size);
  display_array(arr,size);

  printf("Enter the element to be searched in the array:::\n");
  scanf("%d",&element);

  flag =binary_search(arr, 0, size, element);
  
  if (flag == -1)
  {
    printf("Element is not Present in the Specified Array:::\n");
  }

  else
  {
    printf("Element is Present at %d Position:::\n",flag+1);
  }
}

int accept_array(int *arr)
{
  int i,size;

  printf("Enter the size of the array:::\n");
  scanf("%d",&size);

  printf("Enter the elements into the array::\n");
  for(i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }

  return size;
}
void sorting(int *arr, int size)
{
  int i, j, temp;

  for(i=0; i<size-1; i++)
  {
    for(j=0; j<size-1; j++)
    {
      if (arr[j+1] > arr[j])
      {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int binary_search(int *arr, int lower, int upper, int element)
{
  int mid = 0;

  if (lower < upper)
  {
    mid = (lower + upper)/2;

    if(element < arr[mid])
    {
      binary_search(arr,mid+1,upper,element);
    }

    else if(element > arr[mid])
    {
      binary_search(arr,lower,mid-1,element);
    }

    else if(element == arr[mid])
    {
      return mid;
    }
  }
  return 0;
}

void display_array(int *arr , int size)
{
  int i;

  printf("Displaying the Sorted Array:::\n");
  for(i=0; i<size; i++)
  {
    printf("%d  ",arr[i]);
  }
  printf("\n");
}

 