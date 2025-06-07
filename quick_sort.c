#include <stdio.h>

#define N 8

int partition(int *arr, int p, int r)
{
  int x = arr[p];
  int i = p;
  for(int j = p + 1; j <= r; j++)
  {
    if(arr[j] >= x)
    {
      i++;
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    }
  }
  int tmp = arr[i];
  arr[i] = arr[p];
  arr[p] = tmp;
  return i;
}

void quicksort(int *arr, int p, int r)
{
  int q;
  if(r > p)
  {
    q = partition(arr, p, r);
    quicksort(arr, p, q - 1);
    quicksort(arr, q + 1, r);
  }
}

int main(void)
{
  int arr[N] = {5 ,2, 4, 7, 1, 3, 2, 6};
  
  quicksort(arr, 0, N - 1);
  
  for(int i = 0; i < N; i++)
  {
    printf("%d ",arr[i]);
  }

  return 0;
}
