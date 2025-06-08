#include <stdio.h>
#include <math.h>
#define N 8

int arr[N] = {1, 2, 3, 3, 5 ,6, 7, 8};

//折半查找q1
int binarysearch(int num)
{
  int mid, start = 0, end = N - 1;
  while(start <= end)
  {
    mid = (start + end) / 2;
    if(arr[mid] < num)
      start = mid + 1;
    else if(arr[mid] > num)
        end = mid - 1;
    else
    {
      while(arr[--mid] == num);
      return mid+1;
    }
  }
  return -1;
}

//q2
double mysqrt(double y)
{
  double low = 0, high = y, mid = -1;
  while(low < high)
  {
    mid = (low + high) / 2;
    if(fabs(mid*mid - y) < 1e-5)
      break;
    else if(mid*mid < y)
      low = mid + 1e-5;
    else 
      high = mid - 1e-5;
  }
  return mid;
}

//q3
double mypow(double x, int n)
{
//递归实现
#if 0
  if(n == 0) return 1.0L;
  double half = mypow(x*x, n/2);
  return (n%2==0) ? half : x*half;
#endif
//循环实现
  double res = 1.0;
  while(n > 0)
  {
    if(n%2 == 1) res *=x;
    x*=x;
    n/=2;
  }
  return res;

}


int main(void)
{
  //printf("%d\n", binarysearch(3));
  double p  = mypow(2, 3);
  printf("%lf", p);
  return 0;
}
