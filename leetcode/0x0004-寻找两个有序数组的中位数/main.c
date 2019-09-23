/* 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。 */

/* 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。 */

/* 你可以假设 nums1 和 nums2 不会同时为空。 */

/* 示例 1: */

/* nums1 = [1, 3] */
/* nums2 = [2] */

/* 则中位数是 2.0 */

/* 示例 2: */

/* nums1 = [1, 2] */
/* nums2 = [3, 4] */

/* 则中位数是 (2 + 3)/2 = 2.5 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <limits.h>
#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  if (nums1Size > nums2Size)
    return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

  int max1 = 0;
  int max2 = 0;
  int min1 = 0;
  int min2 = 0;
  int c1 = 0;
  int c2 = 0;
  int lo = 0;
  int hi = nums1Size << 1;

  while (lo <= hi) {
    c1 = (lo + hi) >> 1;
    c2 = nums1Size + nums2Size - c1;

    max1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) >> 1];
    min1 = (c1 == nums1Size << 1) ? INT_MAX : nums1[c1 >> 1];
    max2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) >> 1];
    min2 = (c2 == nums2Size << 1) ? INT_MAX : nums2[c2 >> 1];

    if (max1 > min2)
      hi = c1 - 1;
    else if (max2 > min1)
      lo = c1 + 1;
    else
      break;
  }

  return (MAX(max1, max2) + MIN(min1, min2)) / 2.0;
}

int main(int argc, char *argv[]) {
  int nums1[] = {2, 3, 5};
  int nums2[] = {1, 4, 7, 9};
  printf("average: %f\n", findMedianSortedArrays(nums1, 3, nums2, 4));
  return 0;
}
