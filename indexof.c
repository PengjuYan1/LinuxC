#include <stdio.h>

char a[] = "hello world";

int indexof(char letter)
{
  int i = 0;
  while(a[i] != '\0')
  {
    if(a[i] == letter)
      return i;
    i++;
  }
  return i - 1;
}

int main(void)
{
  printf("%d %d\n", indexof('o'), indexof('w'));
  
  return 0;
}
