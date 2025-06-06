#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 40

int a[N];

void gen_random(int upper_bound)
{
  for(int i = 0; i < N; i++)
  {
    a[i] = rand() % upper_bound;
  }
}


void rand_count(int *histogram)
{
  for(int i = 0; i < N; i++)
  {
    //histogram[a[i]]++;
    (*(histogram + *(a + i)))++;
  }
}

void histogram_print(int *histogram)
{
  int histogram_max(int *);
  int row = histogram_max(histogram);
  for(int i = 0; i < 10; i++)
  {
    printf("%-2d", i);
  }
  printf("\n\n");
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      if(*(histogram+j) >i)
        printf("%-2c", '*');
      else
        printf("%-2c", ' ');
    }
    printf("\n");
  }

}

int histogram_max(int *histogram)
{
  int max = *histogram;
  for(int i = 0; i < 10; i++)
  {
    if(*(histogram+i) > max)
      max = *(histogram + i);
  }
  return max;
}

int main(void)
{
  srand(time(NULL));
  int histogram[10] = {0};
  gen_random(10);
  rand_count(histogram);
  histogram_print(histogram);
  for(int i = 0; i < sizeof(histogram)/sizeof(int); i++)
  {
    printf("%d: %d\n", i, histogram[i]);
  }
  return 0;
}
