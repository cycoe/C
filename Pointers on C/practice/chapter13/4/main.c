#include <stdio.h>

int sort(void *list, unsigned *item_len, unsigned len,
         int (*compare)(void *a, void *b)) {
  if (list == NULL)
    return 0;

  for (int i = 1; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      compare(list + i, list + j);
    }
  }

  return 1;
}

int compare_int(void *a, void *b) {
  int tmp, *ap, *bp;
  ap = (int *)a;
  bp = (int *)b;
  if (*ap > *bp) {
    tmp = *ap;
    *ap = *bp;
    *bp = tmp;
  }

  return 1;
}

int main(int argc, char *argv[])
{
  int nums[10] = {4, 1, 2, 4, 6, 7, 2, 3, 4, 8};
  unsigned lens[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  sort(nums, lens, 10, compare_int);
  for (int i = 0; i < 10; i++) {
    printf("%d ", nums[i]);
  }
  return 0;
}
