/* 第一阶段第11章排序与查找习题
* q1.实现一个算法，在一组随机排列的数中找出最小的一个。
*    你能想到的最直观的算法一定是Θ(n)的，想想有没有比Θ(n)更快的算法？
* q2. 在一组随机排列的数中找出第二小的，这个问题比上一个稍复杂，
*     你能不能想出Θ(n)的算法？
* q3. 进一步泛化，在一组随机排列的数中找出第k小的，这个元素称为
*     k-th Order Statistic。能想到的最直观的算法肯定是先把这些数
*     排序然后取第k个，时间复杂度和排序算法相同，可以是Θ(nlgn)。
*     这个问题虽然比前两个问题复杂，但它也有平均情况下时间复杂度
*     是Θ(n)的算法，将上一节习题1的快速排序算法稍加修改就可以解决这个问题：
*
*
*/

#include <stdio.h>

#define N 8

void q1(int *arr)
{
  int min = arr[0];
  for(int i = 0; i < N; i++)
  {
    if(arr[i] < min)
      min = arr[i];
  }
    printf("%d ", min);
}

int partition(int *arr, int p, int r)
{
  int x = arr[p];
  int i = p;
  for(int j = p + 1; j <= r; j++)
  {
    if(arr[j] <= x)
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

//从p到q之间找到第k小的元素
int order_statistic(int *arr, int p, int r, int k)
{
  int mid = partition(arr, p, r);
  int i = mid - p + 1; //pivot是第几小的
  if(k == i)
    return arr[i];
  else if(k > i)
  {
    return order_statistic(arr, mid + 1, r, k - i);
  }
  else
  {
    return order_statistic(arr, p, mid - 1, k);
  }
}

int main(void)
{
  int arr[N] = {5, 7, 2, 9, 4, 2, 10, 3};
  int kmin = order_statistic(arr, 0, N - 1, 3);
  printf("%d", kmin);
  return 0;
}
