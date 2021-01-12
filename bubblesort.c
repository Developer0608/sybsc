#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *arr, i, j, temp, n;

  printf("Enter the size of array: ");
  scanf("%d", &n);

  arr = (int *)malloc(sizeof(int *));

  printf("Enter the nos. into the array:: ");
  for(i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Elements of Array are:: ");
  for(i = 0; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n - 1; j++)
    {
      if(arr[j] < arr[j + 1])
      {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }

  printf("After Sorting Array in decending order::::\n");
  for(i = 0; i < n; i++)
  {
    printf("%d\t",arr[i]);
  }
  printf("\n");

   for(i = 0; i < n; i++)
  {
    for(j = 0; j < n - 1; j++)
    {
      if(arr[j] > arr[j + 1])
      {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }

  printf("After Sorting Array in ascending order::::\n");
  for(i = 0; i < n; i++)
  {
    printf("%d\t",arr[i]);
  }
  printf("\n");

  return 0;
}
 
//   
//  