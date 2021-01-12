#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *arr , i , j , size , key;

  printf("Enter the elements to enter into the array::\n");
  scanf("%d",&size);

  arr = malloc(sizeof(int *));

  printf("Enter the elements into the array::\n");
  for(i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }

  for(i=1; i<size; i++)
  {
    key = arr[i];
    j = i-1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j+1] = arr[j];
      j--;
    }
    
    arr[j+1] = key;
  }

  printf("Displaying the Contents of the Array After Sorting::\n");
  for(i=0; i<size; i++)
  {
    printf("%d\n",arr[i]);
  }

}