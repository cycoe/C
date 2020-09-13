/* 给你两个二进制字符串，返回它们的和（用二进制表示）。 */

/* 输入为 非空 字符串且只包含数字 1 和 0。 */



/* 示例 1: */

/* 输入: a = "11", b = "1" */
/* 输出: "100" */

/* 示例 2: */

/* 输入: a = "1010", b = "1011" */
/* 输出: "10101" */



/* 提示： */

/*     每个字符串仅由字符 '0' 或 '1' 组成。 */
/*     1 <= a.length, b.length <= 10^4 */
/*     字符串如果不是 "0" ，就都不含前导零。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/add-binary */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char * addBinary(char * a, char * b){
  size_t len_a = strlen(a);
  size_t len_b = strlen(b);
  size_t len_ret = (len_a > len_b ? len_a : len_b) + 2;
  char *ret = malloc(sizeof(char) * len_ret);

  unsigned char carry = 0;
  unsigned char dig;
  char *pa = a + len_a - 1;
  char *pb = b + len_b - 1;
  char *cur = ret;
  for (; pa >= a && pb >= b; --pa, --pb, ++cur)
    {
      dig = *pa - '0' + *pb - '0' + carry;
      *cur = (dig & 0x01) + '0';
      carry = dig >> 1 & 0x01;
    }

  for (; pa >= a; --pa, ++cur)
    {
      dig = *pa - '0' + carry;
      *cur = (dig & 0x01) + '0';
      carry = dig >> 1 & 0x01;
    }

  for (; pb >= b; --pb, ++cur)
    {
      dig = *pb - '0' + carry;
      *cur = (dig & 0x01) + '0';
      carry = dig >> 1 & 0x01;
    }

  if (carry)
    {
      *cur++ = '1';
    }

  *cur-- = '\0';

  char tmp;
  for (char *rev = ret ;rev < cur; ++rev, --cur)
    {
      tmp = *rev;
      *rev = *cur;
      *cur = tmp;
    }

  return ret;
}

int main()
{
  char a[] = "11";
  char b[] = "1";
  char *ret = addBinary(a, b);
  printf("%s\n", ret);
}
