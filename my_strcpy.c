#include <stdio.h>

#if 0
char *my_strcpy(char *restrict dst, const char *restrict src)
{
  int i = 0;
  while(src[i] != '\0')
  { dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return dst;
}
#endif

char* my_strcpy(char *dest, const char *src)
{
  char *d = dest;
  while(*d++ = *src++);
  return dest;
}

int main(void)
{
  const char src[] = "hello world";
  char dst[] = "";
  printf("%s\n", my_strcpy(dst, src));
  return 0;
}
