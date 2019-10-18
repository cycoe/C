/* 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 *
 * 示例 1:
 *
 * 输入: [1,2,0]
 * 输出: 3
 *
 * 示例 2:
 *
 * 输入: [3,4,-1,1]
 * 输出: 2
 *
 * 示例 3:
 *
 * 输入: [7,8,9,11,12]
 * 输出: 1
 *
 * 说明:
 *
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/first-missing-positive
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <stdbool.h>

// 交换两个 int
void swap(int *a, int *b) {
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}

int firstMissingPositive(int* nums, int numsSize){
    int i = 0;
    int num;
    // 循环遍历 nums 中的元素
    while (i < numsSize) {
        // 第 i 个元素的值
        num = nums[i];
        // 长度为 numsSize 的数组，第一个正数不会超过 numsSize + 1
        // 因此只需要关心 [1, numsSize] 范围內的元素
        if (num > 0 && num <= numsSize) {
            // 与本应所在位置的数相同时，不做处理
            if (nums[i] == nums[num - 1]) {
                i++;
                continue;
            }
            // 位置不对，换到它该去的位置
            if (num - 1 != i)
                swap(&nums[i], &nums[num - 1]);
        }
        // 查看交换后的元素，如果超出范围或已是正确的位置，跳到下个位置
        num = nums[i];
        // 此处 num - 1 == i 要放在最后，因为 num 可能等于 INT_MIN
        if (num <= 0 || num > numsSize || num - 1 == i)
            i++;
    }

    // 找出第一个位置不对的元素
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] - 1 != i)
            return i + 1;
    }
    return numsSize + 1;
}

int main(int argc, char *argv[])
{
    int nums[] = {1, 2, 0};
    int min = firstMissingPositive(nums, sizeof(nums) / sizeof(int));
    printf("First Missing Positive is %d\n", min);
    return 0;
}
