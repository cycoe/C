/* 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。 */

/* 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 */

/* 必须原地修改，只允许使用额外常数空间。 */

/* 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。 */
/* 1,2,3 → 1,3,2 */
/* 3,2,1 → 1,2,3 */
/* 1,1,5 → 1,5,1 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/next-permutation */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>

// 从倒序列表中找出比 target 大的第一个元素
int findIndex(int * nums, int start, int end, int target) {
    // 二分法中点
    int mid = start;
    while (end > start) {
        mid = (start + end) >> 1;
        // start == mid 时只剩 1 个元素
        if (start == mid)
            return target < nums[end]? end: mid;
        else if (nums[mid] > target)
            start = mid;
        else
            end = mid;
    }
    return mid;
}

// 对 nums 数组的 start 到 end 做倒序排列
void reverse(int * nums, int start, int end) {
    nums += start;
    end -= start;
    int tmp;
    for (int i = 0; i < (end >> 1); i++) {
        tmp = nums[i];
        nums[i] = nums[end - i - 1];
        nums[end - i - 1] = tmp;
    }
}

void nextPermutation(int* nums, int numsSize){
    int index = -1;    // 记录第一个下降点的索引
    // 从后往前遍历，直到遇到 nums[i - 1] < nums[i]，记录 index
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
            index = i - 1;
            break;
        }
    }
    // 当 index == -1，说明没有下降点，直接对全数组做反转
    if (index == -1) {
        reverse(nums, 0, numsSize);
        return;
    }
    // 获取待交换的索引
    int swap = findIndex(nums, index + 1, numsSize - 1, nums[index]);
    int tmp = nums[index];
    nums[index] = nums[swap];
    nums[swap] = tmp;
    reverse(nums, index + 1, numsSize);
}

int main(int argc, char *argv[])
{
    int nums[] = {1, 2, 3};
    int len = sizeof(nums) / sizeof(int);
    nextPermutation(nums, len);
    for (int i = 0; i < len; i++)
        printf("%d: %d\n", i, nums[i]);
    return 0;
}
