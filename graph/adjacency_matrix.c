#include<stdio.h>
#include<stdlib.h>

void create_graph(int **arr, int size);
void print_graph(int **arr, int size);
int main()
{
  int **arr,size;

  printf("Enter the total number of node in  the graph::\n");
  scanf("%d",&size);

  create_graph(arr, size);
  print_graph(arr, size);
}

void create_graph(int **arr, int size)
{
  int i, j;
  char ch = 'A',ch1;

  arr = malloc(sizeof(int *));
  
  for(i=0; i<size; i++)
  {
    arr[i] = malloc(sizeof(int *));
    printf("Create the outgoing edge from the vertex:: %c\n",ch);
    while(1)
    {
      printf("Enter the node to which edge to be added from the %c\n",ch);
      scanf("%d",&j);

      if(j == -1)
      {
        break;
      }

      if(j < size)
      {
        arr[i][j] = 1;
      }

      else
      {
        printf("Invalid Location::\n");
      }
    }
    ch++;
  }
}

void print_graph(int **arr, int size)
{
  int i, j;

  printf("Displaying the graph in form of Matrix:::\n");
  for(i=0; i<size; i++)
  {
    for(j=0; j<size; j++)
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}