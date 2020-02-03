#include <stdio.h>
#include <stdlib.h>

int *read_int(void) {
  unsigned i = 1, length = 1;
  int value;
  int *nums = calloc(length, sizeof(int));

  while (scanf("%d", &value) == 1) {
    if (i >= length) {
      length <<= 1;
      nums = realloc(nums, sizeof(int) * length);
      if (nums == NULL)
        return NULL;
    }
    nums[i] = value;
    *nums = i++;
  }

  nums = realloc(nums, sizeof(int) * (*nums + 1));
  return nums;
}

int main(int argc, char *argv[])
{
  int *nums = read_int();
  for (int i = 0; i < *nums; i++) {
    printf("%d ", *(nums + i + 1));
  }
  free(nums);
  return 0;
}
