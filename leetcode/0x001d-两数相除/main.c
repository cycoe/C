/* 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。 */

/* 返回被除数 dividend 除以除数 divisor 得到的商。 */

/* 示例 1: */

/* 输入: dividend = 10, divisor = 3 */
/* 输出: 3 */

/* 示例 2: */

/* 输入: dividend = 7, divisor = -3 */
/* 输出: -2 */

/* 说明: */

/*     被除数和除数均为 32 位有符号整数。 */
/*     除数不为 0。 */
/*     假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/divide-two-integers */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor){
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    if (dividend == 0)
        return 0;

    // 结果是否为负
    int flag = dividend > 0 ^ divisor > 0;
    int negDividend = dividend > 0? -dividend: dividend;
    int negDivisor = divisor > 0? -divisor: divisor;
    int start = dividend > 0? dividend: 0;
    int end = dividend > 0? 0: dividend;

    int carry = 0;
    while ((negDivisor << carry ) >= (negDividend >> 1)) carry++;
    printf("Carry is: %d\n", carry);
    int ret = 0;
    while (carry >= 0) {
        start += (negDivisor << carry);
        ret += (1 << carry);
        if (start + (negDivisor << carry) == end) break;
        while (start + (negDivisor << carry) < end && carry >= 0) carry--;
        printf("start is %d, carry is %d\n", start, carry);
    }
    return flag? -ret: ret;
}

int main(int argc, char *argv[])
{
    printf("result is: %d\n", divide(-2147483648, 1));
    return 0;
}
