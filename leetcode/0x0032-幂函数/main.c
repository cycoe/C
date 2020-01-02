/* 实现 pow(x, n) ，即计算 x 的 n 次幂函数。 */

/* 示例 1: */

/* 输入: 2.00000, 10 */
/* 输出: 1024.00000 */

/* 示例 2: */

/* 输入: 2.10000, 3 */
/* 输出: 9.26100 */

/* 示例 3: */

/* 输入: 2.00000, -2 */
/* 输出: 0.25000 */
/* 解释: 2-2 = 1/22 = 1/4 = 0.25 */

/* 说明: */

/*     -100.0 < x < 100.0 */
/*     n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/powx-n */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <limits.h>
#include <stdio.h>

double myPow(double x, int n) {
  // 如果底为 0 则直接返回 0
  if (x == 0)
    return 0.0;

  // 返回值
  double ret = 1;
  // 补偿因子
  double hack = 0;

  if (n == INT_MIN) {
    // 如果 n == INT_MIN，则让 n = INT_MAX，并让 x 作为补偿因子
    hack = x;
    n = INT_MAX;
   } else if (n < 0) {
     // 如果 n < 0，则让 1 作为补偿因子，并且让 n = -n
     hack = 1;
     n = -n;
   }

   // 快速幂
   for (; n != 0; n >>= 1) {
     if (n & 1) {
       ret *= x;
     }
     x *= x;
  }

  // 如果补偿因子不为 0，结果除去补偿因子
  if (hack)
    ret = 1 / ret / hack;

  return ret;
}

int main(int argc, char *argv[])
{
  double x = 3;
  int n = -5;
  printf("%.2f^%d = %.8f\n", x, n, myPow(x, n));
  return 0;
}
