#include <stdio.h>
#include "increment.c"
#include "negate.c"


int main(int argc, char *argv[])
{
  printf("%d %d %d %d %d %d\n", increment(10), increment(0), increment(-10),
         negate(10), negate(0), negate(-10));
  return 0;
}
