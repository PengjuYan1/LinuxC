#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void *main(size_t size);
//返回值：成功返回所分配内存空间的首地址，出错返回NULL
//void free(void *ptr);

typedef struct {
  int number;
  char *msg;
}unit_t;

int main(void)
{
  unit_t *p = malloc(sizeof(unit_t));

  if(p == NULL){
    printf("out of memory\n");
    exit(1);
  }
  p->number = 3;
  p->msg = malloc(20);
  strcpy(p->msg, "Hello world!");
  printf("number: %d\nmsg: %s\n", p->number, p->msg);
  free(p->msg);
  free(p);
  p = NULL;

  return 0;
}
