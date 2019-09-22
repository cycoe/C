/* 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。 */

/* 示例 1: */

/* 输入: 123 */
/* 输出: 321 */

/*  示例 2: */

/* 输入: -123 */
/* 输出: -321 */

/* 示例 3: */

/* 输入: 120 */
/* 输出: 21 */

/* 注意: */

/* 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/reverse-integer */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <limits.h> // include INT_MAX and INT_MIN

int reverse(int x){
    int ret = 0;
    while (x != 0) {
        int mod = x % 10;
        x = x / 10;
        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && mod > 7)) return 0;
        if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && mod < -8)) return 0;
        ret = ret * 10 + mod;
    }
    return ret;
}


int main(int argc, char *argv[])
{
    int x = 12345;
    printf("original: %d\n", x);
    printf("reverse: %d\n", reverse(x));
    return 0;
}
