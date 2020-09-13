/* 实现 int sqrt(int x) 函数。 */

/* 计算并返回 x 的平方根，其中 x 是非负整数。 */

/* 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 */

/* 示例 1: */

/* 输入: 4 */
/* 输出: 2 */

/* 示例 2: */

/* 输入: 8 */
/* 输出: 2 */
/* 说明: 8 的平方根是 2.82842...,  */
/*      由于返回类型是整数，小数部分将被舍去。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/sqrtx */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>

int mySqrt(int a){
  if (a == 0)
    return 0;

  if (a == 1)
    return 1;

  double x0 = a;

  while (1)
    {
      double xi = 0.5 * (x0 + a / x0);
      if ((xi > x0 ? xi - x0 : x0 - xi) < 1e-7)
        break;

      x0 = xi;
    }

  return (int) x0;
}

int main()
{
  printf("sqrt(8): %d\n", mySqrt(8));
  printf("sqrt(9): %d\n", mySqrt(9));
}
