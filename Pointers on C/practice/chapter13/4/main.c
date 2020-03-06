#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* sort 函数原型
 * list 是待排序的数组
 * n_elements 元素的个数
 * el_size 元素的字节大小，用于交换元素
 * int (*compare)(const void *a, const void *b) 比较函数
 */
void sort(void *list, size_t n_elements, size_t el_size,
          int (*compare)(const void *a, const void *b)) {

  /* 断言数组指针不为空 */
  assert(list != NULL);

  /* 分配 el_size 大小的内存用于临时存放元素 */
  void *temp = malloc(el_size);

  /* 以下最关键的是内存地址的转换，void* 型的指针每次加 1 只加 1 个字节，
   * 因此需要根据实际的 el_size 做指针偏移
   */
  for (size_t i = 0; i < n_elements - 1; i++) {
    for (size_t j = 0; j < n_elements - i - 1; j++) {
      if (compare(list + j * el_size, list + (j + 1) * el_size) > 0) {
        memcpy(temp, list + j * el_size, el_size);
        memcpy(list + j * el_size, list + (j + 1) * el_size, el_size);
        memcpy(list + (j + 1) * el_size, temp, el_size);
      }
    }
  }

  free(temp);
}

int compare_int(const void *a, const void *b) {
  int *ap = (int *)a;
  int *bp = (int *)b;
  if (*ap > *bp) {
    return 1;
  } else if (*ap < *bp) {
    return -1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int nums[10] = {4, 8, 2, 4, 6, 7, 2, 3, 4, 8};
  sort(nums, 10, sizeof(int), compare_int);
  for (int i = 0; i < 10; i++) {
    printf("%d ", nums[i]);
  }
  return 0;
}
