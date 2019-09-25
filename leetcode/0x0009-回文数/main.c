/* 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。 */

/* 示例 1: */

/* 输入: 121 */
/* 输出: true */

/* 示例 2: */

/* 输入: -121 */
/* 输出: false */
/* 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。 */

/* 示例 3: */

/* 输入: 10 */
/* 输出: false */
/* 解释: 从右向左读, 为 01 。因此它不是一个回文数。 */

/* 进阶: */

/* 你能不将整数转为字符串来解决这个问题吗？ */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/palindrome-number */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>

int isPalindrome(int x){
    // 如果 x 是负数或 x 以 0 结尾，则必不可能为回文数
    if (x < 0 || (x % 10 == 0 && x))
        return 0;

    // 储存 x 的反向数
    int reverse = 0;
    while (x > reverse) {
        // 每次取出 x 的最位，并加于 reverse 之后
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    // 如果 x 偶数位长，判斷 x == reverse
    // 如果 x 奇数位长，去掉 reverse 的最后一位
    return (x == reverse || x == reverse / 10);
}

int main(int argc, char *argv[])
{
    int a = 1232;
    printf("%d is %sa palindrome", a, isPalindrome(a)? "": "not ");
    return 0;
}
