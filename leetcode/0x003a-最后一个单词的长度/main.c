/* 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。 */

/* 如果不存在最后一个单词，请返回 0 。 */

/* 说明：一个单词是指由字母组成，但不包含任何空格的字符串。 */

/* 示例: */

/* 输入: "Hello World" */
/* 输出: 5 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/length-of-last-word */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>

int lengthOfLastWord(char *s) {
  // 左指针和右指针
  int left = -1, right = 0;
  // 记录单词长度，左右指针差
  int length = 0, diff = 0;

  while (s[right]) {
    // 如果右指针遇到一个空格
    if (s[right] == ' ') {
      // 并且 diff 大于 1，则认为左右指针之间形成了一个新单词
      if ((diff = right - left - 1) > 0)
        length = diff;
      // 更新左指针位置
      left = right;
    }
    right++;
  }

  // 字符串读取完毕，更新单词长度
  if ((diff = right - left - 1) > 0)
    length = diff;

  return length;
}

int main(int argc, char *argv[])
{
  char *s = "Hello World";
  printf("Length of the last word is %d\n", lengthOfLastWord(s));
  return 0;
}
