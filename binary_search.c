#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int *arr , int size);
void sorted_array(int *arr , int size);
int binary_search(int *arr , int size);
int main()
{
  int *arr , i , j , size , flag = 0;

  printf("Enter the size of the array:::\n");
  scanf("%d",&size);

  arr = (int *)malloc(sizeof(int *));

  printf("Enter the elements into the array:::\n");
  for(i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }

  bubble_sort(arr , size);
  sorted_array(arr , size);
  flag = binary_search(arr , size);

  if (flag == -1)
  {
    printf("Element is not present in array:::\n");
  }

  else
  {
    printf("Element is present at :::: %d Location\n",flag+1);
  }

}

void bubble_sort(int *arr , int size)
{
  int i , j , temp;

  for(i=0; i<size-1; i++)
  {
    for(j=0; j<size-1; j++)
    {
      if (arr[j] > arr[j+1])
      {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }

}

void sorted_array(int *arr , int size)
{
  int i;

  printf("Displying the Sorted Array:::\n");
  for(i=0; i<size; i++)
  {
    printf("%d  ",arr[i]);
  }
  printf("\n");
}

int binary_search(int *arr , int size)
{
  int i , j , mid , element;

  printf("\nEnter the element to be searched::::\n");
  scanf("%d",&element);

  i = 0;
  j = size-1;
  
  while(i <= j)
  {
      mid = (i + j)/2;

      if (element < arr[mid])
      {
        j = mid - 1;
      }

      else if (element > arr[mid])
      {
        i = mid + 1;
      }

      else if (element == arr[mid])
      {
        return mid;
      }
  }

  return -1;
}