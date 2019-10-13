/* 假设按照升序排序的数组在预先未知的某个点上进行了旋转。 */

/* ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 */

/* 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。 */

/* 你可以假设数组中不存在重复的元素。 */

/* 你的算法时间复杂度必须是 O(log n) 级别。 */

/* 示例 1: */

/* 输入: nums = [4,5,6,7,0,1,2], target = 0 */
/* 输出: 4 */

/* 示例 2: */

/* 输入: nums = [4,5,6,7,0,1,2], target = 3 */
/* 输出: -1 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>

// 解析
/* 注意到原数组为有限制的有序数组（除了在某个点会突然下降外均为升序数组） */

/*     if nums[0] <= nums[I] 那么 nums[0] 到 nums[i] 为有序数组,那么当 nums[0] <= target <= nums[i] 时我们应该在 0−i0-i0−i 范围内查找； */

/*     if nums[i] < nums[0] 那么在 0−i0-i0−i 区间的某个点处发生了下降（旋转），那么 nums[i+1] 到最后一个数字的区间为有序数组，并且所有的数字都是小于 nums[0] 且大于 nums[i]，当target不属于 nums[0] 到 nums[i] 时（target <= nums[i] < nums[0] or nums[i] < nums[0] <= target），我们应该在 0−i0-i0−i 区间内查找。 */
/*     上述三种情况可以总结如下： */

/*     nums[0] <= target <= nums[i] */
/*                target <= nums[i] < nums[0] */
/*                          nums[i] < nums[0] <= target */

/* 所以我们进行三项判断： */

/* (nums[0] <= target)， (target <= nums[i]) ，(nums[i] < nums[0])，现在我们想知道这三项中有哪两项为真（明显这三项不可能均为真或均为假（因为这三项可能已经包含了所有情况）） */

/* 所以我们现在只需要区别出这三项中有两项为真还是只有一项为真。 */

/* 使用 “异或” 操作可以轻松的得到上述结果（两项为真时异或结果为假，一项为真时异或结果为真，可以画真值表进行验证） */

/* 之后我们通过二分查找不断做小 target 可能位于的区间直到 low==high，此时如果 nums[low]==target 则找到了，如果不等则说明该数组里没有此项。 */

/* 作者：LukeLee */
/* 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-jian-solution-by-lukelee/ */
/* 来源：力扣（LeetCode） */
/* 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */

// 本题与二分查找类似
int search(int* nums, int numsSize, int target){
    int L = 0;
    int R = numsSize - 1;
    int M;
    while (L < R) {
        M = (L + R) >> 1;
        if ((nums[0] > target) ^ (nums[0] > nums[M]) ^ (target > nums[M]))
            L = M + 1;
        else
            R = M;
    }
    return L == R && nums[L] == target? L: -1;
}
