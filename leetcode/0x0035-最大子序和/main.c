/* 给定一个整数数组 nums
 * ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 */

/* 示例: */

/* 输入: [-2,1,-3,4,-1,2,1,-5,4], */
/* 输出: 6 */
/* 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。 */

/* 进阶: */

/* 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/maximum-subarray */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int maxSubArray(int *nums, int numsSize) {
  int max_sum = nums[0], sum = nums[0];

  // 贪心算法
  for (int i = 1; i < numsSize; i++) {
    sum = MAX(nums[i], sum + nums[i]);
    max_sum = MAX(sum, max_sum);
  }

  return max_sum;
}

int main(int argc, char *argv[]) {
  int nums[4] = {-3, -2, 0, -1};

  printf("max sum of sub-squence is %d\n", maxSubArray(nums, 4));
  return 0;
}
