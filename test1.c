#include <stdio.h>
#include <math.h>

/*
* 1.写一个函数，参数是整型变量x,功能是打印x的个位和十位
* 2.编写一个布尔函数int is_leap_year(int year), 判断参数year是不是闰年。
*   如果某年份能被4整除，但不能被100整除，那么这一年就是闰年，此外，能被400整除的年份也是闰年。
* 3. 编写一个函数double myronud(double x)，输入一个小数，将它四舍五入，可以调用math.h中的ceil和floor。
* 
*
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

int main(void)
{
  //q1();
  //q2();
  //q3();
  return 0;
}
