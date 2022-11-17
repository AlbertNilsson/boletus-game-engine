#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int *const test = malloc(10*sizeof(int));
  *test = 5;
  printf("%d\n",*test);
  *test = 6;
  printf("%d\n",*test);
  return 0;
  free(test);
}
