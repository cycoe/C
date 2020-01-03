/* 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。 */

/* 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。 */

/* 你可以假设除了整数 0 之外，这个整数不会以零开头。 */

/* 示例 1: */

/* 输入: [1,2,3] */
/* 输出: [1,2,4] */
/* 解释: 输入数组表示数字 123。 */

/* 示例 2: */

/* 输入: [4,3,2,1] */
/* 输出: [4,3,2,2] */
/* 解释: 输入数组表示数字 4321。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/plus-one */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 思路分析： */

/* 此题不难，其实就是让我们模拟竖式计算进位，然只需要加111即可。对此，我们将问题分成以下3类：
 */

/*     给定整数中最后一位不是数字999（如123412341234）； */
/*     给定整数中最后一位是数字999，但不全是数字999（如109910991099）； */
/*     给定整数所有位全是数字999（如999999999999）。 */

/* 算法思路： */

/*     对于上述情况1，直接在最后一位加111即可。 */
/*     对于上述情况2，只需从后向前遍历数组，逢999进111，直至非999结束。 */
/*     对于上述情况3，我们在最开始不需要与情况2区分，只需要在按照情况2遍历结束后判断首位，若首位为000，则代表情况3出现，此时直接在vector末尾添加1个000，再将首位由000变为111即可。
 */

/* 作者：donggua-2 */
/* 链接：https://leetcode-cn.com/problems/plus-one/solution/cbian-li-yi-ci-kong-jian-o1zhi-yao-0ms-by-donggua-/
 */
/* 来源：力扣（LeetCode） */
/* 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */

int *plusOne(int *digits, int digitsSize, int *returnSize) {
  int *ret = (int *)malloc(sizeof(int) * digitsSize);
  memcpy(ret, digits, sizeof(int) * digitsSize);

  for (int i = digitsSize - 1; i >= 0; i--) {
    if (ret[i] == 9)
      ret[i] = 0;
    else {
      ret[i]++;
      break;
    }
  }
  if (digits[0] == 0) {
    ret = realloc(ret, sizeof(int) * (++digitsSize));
    ret[0] = 1;
    ret[digitsSize - 1] = 0;
  }
  *returnSize = digitsSize;
  return ret;
}

int main(int argc, char *argv[])
{
  int digits[5] = {1, 2, 3, 4, 5};
  int returnSize;
  int *ret = plusOne(digits, 5, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d, ", ret[i]);
  }
  free(ret);
  return 0;
}
