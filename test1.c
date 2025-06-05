#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/****************《LinuxC一站式编程》第一部分习题*********************
* q1.写一个函数，参数是整型变量x,功能是打印x的个位和十位
* q2.编写一个布尔函数int is_leap_year(int year), 判断参数year是不是闰年。
*    如果某年份能被4整除，但不能被100整除，那么这一年就是闰年，此外，能被400整除的年份也是闰年。
* q3.编写一个函数double myronud(double x)，输入一个小数，将它四舍五入，可以调用math.h中的ceil和floor。
* q4.使用递归求一个数的阶乘
* q5.编写递归函数求两个正整数a和b的最大公约数，使用Euclid算法:
*    1) 如果a除以b能整除，则最大公约数为b。
*    2）否则，最大公约数等于b和a%b的最大公约数。
*    3) 修改程序使之适用所有的整数，而不仅仅是正整数
* q6.编写递归函数求Fibonacci数列的第n项，这个数列是这样定义的：
*     fib(0) = 1
*     fib(1) = 1
*     fib(n) = fib(n - 1) + fib(n - 2)
*/

void q1(void)  
{
  int x, a, b;
  scanf("%d", &x);
  a = x % 10;
  b = (x/10) % 10;
  printf("a = %d, b = %d\n", a, b);
}

int is_leap_year(int year)
{
  if((year%4==0 && year%100!=0) || year %400 == 0)
    return 1;
  else 
    return 0;
}
void q2(void)
{
  int year = 0;
  scanf("%d", &year);
  int result = is_leap_year(year);
  printf("%d\n", result);
}

// -3.51 4.40
double myround(double x)
{
  if(x >= 0.0)
    return floor(x + 0.5);
  else
    return ceil(x - 0.5);
}

void q3(void)
{
  double x = 0.0;
  scanf("%lf", &x);
  double y = myround(x);
  printf("%.1f->%.1f\n", x, y);
}

int factorial(int n)
{
  if(n == 0)
    return 1;
  else 
  {
    return n * factorial(n - 1);
  }
}

void q4(void)
{
  int n;
  scanf("%d", &n);
  printf("%d! = %d\n", n,factorial(n));
}

int gcd(int a, int b)
{
  if(b == 0)
    return abs(a);
  //if(a % b == 0)
  //  return abs(b);
  else
    return gcd(b, a%b);
}

void q5(void)
{
  // int a, b;
  // scanf("%d%d", &a, &b);
  // int c = GCD(a, b);
  // printf("%d\n", c);
  //测试用例
  int test_cases[][3] = 
  {
        {10, 15, 5},      // 正数常规情况
        {14, 9, 1},       // 互质数
        {18, 6, 6},       // 倍数关系
        {11, 11, 11},     // 两数相同
        {0, 7, 7},        // 一个数为零
        {0, 0, 0},        // 两个数都为零
        {-24, 16, 8},     // 负数处理
        {100, 75, 25},    // 大数计算
        {13, 39, 13},     // 质数和合数
        {7, 0, 7},        // 另一个为零的例子
        {17, 1, 1},       // 包含1
        {22, 23, 1},      // 连续整数
        {-45, -30, 15},   // 两个负数
        {42, -56, 14},    // 正负混合
        {0, -5, 5}        // 零和负数 
  };
  for(int i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); i++)
  {
    int a = test_cases[i][0];
    int b = test_cases[i][1];
    int result = gcd(a, b);
    int expected = test_cases[i][2];
    printf("gcd(%d, %d) = %d [%s]\n", 
            a, b, result,
            result == expected ? "正确" : "错误");
  }
}

int fib(int n)
{
  if(n == 0 || n == 1)
    return 1;
  else 
    return fib(n - 1) + fib(n - 2);
}

void q6(void)
{
  // 测试用例数组：{输入n, 期望输出}
    int test_cases[][2] = {
        {0, 1},     // fib(0) = 1
        {1, 1},     // fib(1) = 1
        {2, 2},     // fib(2) = fib(1) + fib(0) = 1 + 1 = 2
        {3, 3},     // fib(3) = fib(2) + fib(1) = 2 + 1 = 3
        {4, 5},     // fib(4) = fib(3) + fib(2) = 3 + 2 = 5
        {5, 8},     // fib(5) = fib(4) + fib(3) = 5 + 3 = 8
        {6, 13},    // fib(6) = fib(5) + fib(4) = 8 + 5 = 13
        {7, 21},    // fib(7) = fib(6) + fib(5) = 13 + 8 = 21
        {8, 34},    // fib(8) = fib(7) + fib(6) = 21 + 13 = 34
        {9, 55},    // fib(9) = fib(8) + fib(7) = 34 + 21 = 55
        {10, 89},   // fib(10) = fib(9) + fib(8) = 55 + 34 = 89
        {15, 987},  // fib(15) = fib(14) + fib(13) = ... = 987
        {20, 10946} // fib(20) = 10946
    };
  for(int i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); i++)
  {
    int expected = test_cases[i][1];
    int result = fib(test_cases[i][0]);
    printf("fib(%d) = %d [%s]\n", 
            test_cases[i][0], result,
            result == expected ? "正确" : "错误");
  }

}

int main(void)
{
  //q1();
  //q2();
  //q3();
  //q4();
  //q5();
  q6();
  return 0;
}
