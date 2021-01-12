#include<stdio.h>
#include<stdlib.h>
int merging(int *arr , int lower_bound , int upper_bound);
int merge_sort(int *arr, int lower_bound, int mid , int upper_bound);
void print_sorted_array(int *arr , int lower_bound , int upper_bound);
int main()
{
  int *arr , i=0 , lower_bound , upper_bound , size;

  printf("Enter the total number of elements you wanna enter into the array::\n");
  scanf("%d",&size);

  lower_bound = i;

  printf("Enter the Elements into the Array:::\n");
  for(i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }
  upper_bound = i-1;

  merging(arr , lower_bound , upper_bound);
  print_sorted_array(arr , lower_bound , upper_bound);

  return 0;

}
int merging(int *arr , int lower_bound , int upper_bound)
{
  int mid;

  if (lower_bound < upper_bound)
  {
    mid = (lower_bound + upper_bound)/2;

    merging(arr ,lower_bound ,mid);
    merging(arr ,mid+1 , upper_bound);
    merge_sort(arr, lower_bound, mid, upper_bound);
  }

  return 0;
}
int merge_sort(int *arr , int lower_bound , int mid , int upper_bound)
{
  int *arr1 , i , j , k;

  arr1 = (int *)malloc(sizeof(int *));
  i = lower_bound;
  j = mid + 1;
  k = lower_bound;

  while(i <= mid && j <= upper_bound)
  {
    if (arr[i] <= arr[j])
    {
      arr1[k] = arr[i];
      i++;
    }

    else
    {
      arr1[k] = arr[j];
      j++;
    }
    k++;
  }

   
    while ( j <= upper_bound)
    {
      arr1[k] = arr[j];
      j++;
      k++;
    }
   
    while ( i <= mid)
    {
      arr1[k] = arr[i];
      i++;
      k++;
    }


  for(i=lower_bound; i<=upper_bound; i++)
  {
    arr[i] = arr1[i];
  }

  return 0;
}

void print_sorted_array(int *arr , int lower_bound , int upper_bound)
{
  int i;

  printf("Displaying the Array in Sorted Manner:::\n");
  for(i=lower_bound; i<=upper_bound; i++)
  {
    printf("%d  ",arr[i]);
  }
  printf("\n");
} 