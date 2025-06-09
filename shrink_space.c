#include <stdio.h>
#include <stddef.h>

const char src[] = "This Content hoho       is ok\
        ok?\
 \
        file system\
uttered words   ok ok      ?\
end.";

char *shrink_space(char *dest, const char *src)
{
  char *p = dest;
  while(*src)
  {
    if(*src != '\t' && *src != '\n' && *src != '\r' && *src != ' ')
      *p++ = *src++;
    src++;
  }
  *p = '\0';
  return dest;
}

int main(void)
{
  char dest[50] = "";
  printf("%s\n", shrink_space(dest, src));
  return 0;
}

