#include<stdio.h>
#include<stdlib.h>
int read_array(int *arr);
void bubble_sort(int *arr , int size);
void display_array(int *arr , int size);
int binary_search(int *arr, int size);
int main()
{
  int *arr, size, flag;

  arr = (int *)malloc(sizeof(int *));

  size = read_array(arr);
  bubble_sort(arr,size);
  display_array(arr, size);
  flag = binary_search(arr, size);

  if (flag == -1)
  {
    printf("Element is not present in the spcified array:::\n");
  }
  else
  {
    printf("Element is Present at :::: %d Position\n",flag+1);
  }

  return 0;

}
int read_array(int *arr)
{
  int i , size;

  printf("Enter the size of the array::\n");
  scanf("%d",&size);
  
  printf("Enter the elements into the array::\n");
  for(i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }

  return size;
}

void bubble_sort(int *arr, int size)
{
  int i, j, temp;

   
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

void display_array(int *arr, int size)
{
    int i;

    printf("Dispalying the sorted array:::\n");
    for(i=0; i<size; i++)
    {
      printf("%d  ",arr[i]);
    }
    printf("\n");
}

int binary_search(int *arr, int size)
{
   
  int i , element ,j, mid;

  i = 0;
  j = size-1;

  printf("Enter the element to be searched ::::\n");
  scanf("%d",&element);

  while(i < j)
  {
     mid = (i+j)/2;

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
