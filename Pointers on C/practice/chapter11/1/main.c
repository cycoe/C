#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr)
    memset(ptr, 0, size);

  return ptr;
}
