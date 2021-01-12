#include<stdio.h>
#include<stdlib.h>
int quicksort(int *arr , int first , int last);
void print_sorted_data(int *arr , int size);
int main()
{
  int *arr , size , i;

  printf("Enter the size of the array::\n");
  scanf("%d",&size);

  printf("Enter the elements into the Array::\n");
  for(i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }

  quicksort(arr , 0 , size-1);
  print_sorted_data(arr , size);

  return 0;
}

int quicksort(int *arr , int first , int last)
{
  int i , j , pivot , temp;

  if(first < last)
  {
    i = first;
    pivot = first;
    j = last;

    while (i < j)
    {
      while(arr[i] <= arr[pivot] && i < j)
      {
        i++;
      }

      while(arr[j] > arr[pivot])
      {
        j--;
      }

      if (i < j)
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    
    quicksort(arr, first, j-1);
    quicksort(arr, j+1, last);
  }

  return 0;
}

void print_sorted_data(int *arr , int size)
{
  int i;

  printf("Printing Sorted data::\n");
  for(i=0; i<size; i++)
  {
    printf("%d ",arr[i]);
  }
}
