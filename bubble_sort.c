#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *arr , i , j , size , temp;

  printf("Enter the size of the array::\n");
  scanf("%d",&size);

  arr = (int *)malloc(sizeof(int *));

  printf("Enter the elements into the array::\n");
  for(i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }

  printf("Displaying the Elements befour the Sorting::\n");
  for(i=0; i<size; i++)
  {
    printf("%d\n",arr[i]);
  }

  for(i=0; i<size-1; i++)
  {
    for(j=0; j<size-1; j++)
    {
      if (arr[j] < arr[j+1])
      {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }

  printf("Displaying the Array After Sorting::::\n");
  for(i=0; i<size; i++)
  {
    printf("%d\n",arr[i]);
  }

  return 0;
}