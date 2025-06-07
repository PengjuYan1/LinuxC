#include <stdio.h>

#define N 8

void merge(int *arr, int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], R[n2];
  
  for(int i = 0; i < n1; i++)
  {
    L[i] = arr[p+i];
  }
  for(int j = 0; j < n2; j++)
  {
    R[j] = arr[q+j+1];
  }
  int k = p, i = 0, j = 0;
  while(i < n1 && j < n2)
  {
    if(L[i] > R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while(i < n1)
    arr[k++] = L[i++];
  while(j < n2)
    arr[k++] = R[j++];

}

void merge_sort(int *arr, int p, int r)
{
  int q;
  if(p < r)
  {
    q = (p + r)/2;
    merge_sort(arr, p, q);
    merge_sort(arr, q+1, r);
    merge(arr, p, q, r);
  }
  else return;
}

int main(void)
{
  int arr[N] = {5, 2, 4, 7, 1, 3, 2, 6};
  int arr1[N] = {3, 5, 6, 7, 9, 1, 2, 11};
  merge_sort(arr1, 0, N -1);
  for(int i = 0; i < N; i++)
  {
    printf("%d ", arr1[i]);
  }
  return 0;
}
