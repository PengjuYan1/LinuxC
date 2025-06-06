#include <stdio.h>
#include <stdlib.h>
struct rational{
  int numerator, denominator;
};

int numerator_part(struct rational num)
{
  return num.numerator;
}

int denominator_part(struct rational num)
{
  return num.denominator;  
}

struct rational make_ratinal(int a, int b)
{
  struct rational num;
  num.numerator = a;
  num.denominator = b;
  return num;
}

int gcd(int a, int b)
{
  if(b == 0)
    return abs(a);
  else return gcd(b, a%b);
}

struct rational add_rational(struct rational a, struct rational b)
{
  int lcm = (denominator_part(a)*denominator_part(b)) / gcd(denominator_part(a), denominator_part(b));
  int num_tmp = numerator_part(a)*(lcm/denominator_part(b)) + numerator_part(b)*(lcm/denominator_part(a));
  if(num_tmp == 0)
    return make_ratinal(0, lcm);
  else 
    return  make_ratinal(num_tmp/gcd(lcm, num_tmp), lcm/gcd(lcm, num_tmp));
}

struct rational sub_rational(struct rational a, struct rational b)
{
  int lcm = (denominator_part(a)*denominator_part(b)) / gcd(denominator_part(a), denominator_part(b)); 
  int num_tmp = numerator_part(a)*(lcm/denominator_part(b)) - numerator_part(b)*(lcm/denominator_part(a));
  if(num_tmp == 0)
    return make_ratinal(0, lcm);
  else
    return  make_ratinal(num_tmp/gcd(lcm, num_tmp), lcm/gcd(lcm, num_tmp));
}

struct rational mul_rational(struct rational a, struct rational b)
{
  int numerator_tmp = numerator_part(a) * numerator_part(b);
  int denominator_tmp = denominator_part(a) * denominator_part(b);
  if(numerator_tmp == 0)
    return make_ratinal(0, denominator_tmp);
  else 
    return make_ratinal(numerator_tmp/gcd(numerator_tmp, denominator_tmp), denominator_tmp/gcd(numerator_tmp, denominator_tmp));
}
struct rational div_rational(struct rational a, struct rational b)
{
  struct rational rational_tmp = make_ratinal(b.denominator, b.numerator);
  return mul_rational(a, rational_tmp);
}
void print_rational(struct rational num)
{
  printf("%d/%d\n", numerator_part(num), denominator_part(num));
}

int main(void)
{
  struct rational a = make_ratinal(1, 8);
  struct rational b = make_ratinal(-1, 8);
  print_rational(add_rational(a, b));
  print_rational(sub_rational(a, b));
  print_rational(mul_rational(a, b));
  print_rational(div_rational(a, b));

  return 0;
}
