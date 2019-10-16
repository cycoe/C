/* 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用一次。
 *
 * 说明：
 *
 *     所有数字（包括目标数）都是正整数。
 *     解集不能包含重复的组合。
 *
 * 示例 1:
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 *
 * 示例 2:
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 *   [1,2,2],
 *   [5]
 * ]
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/combination-sum-ii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

/* Return an array of arrays of size *returnSize. */
/* The sizes of the arrays are returned as *returnColumnSizes array. */
/* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free(). */

void merge(int * nums, int * tmp, int leftStart, int rightStart, int rightEnd, int reverse) {
    int cur = leftStart;
    int leftEnd = rightStart - 1;
    int numsSize = rightEnd - leftStart + 1;
    while (leftStart <= leftEnd && rightStart <= rightEnd) {
        if ((nums[leftStart] < nums[rightStart]) ^ reverse)
            tmp[cur++] = nums[leftStart++];
        else
            tmp[cur++] = nums[rightStart++];
    }
    while (leftStart <= leftEnd)
        tmp[cur++] = nums[leftStart++];
    while (rightStart <= rightEnd)
        tmp[cur++] = nums[rightStart++];
    for (int i = 0; i < numsSize; i++, rightEnd--) {
        nums[rightEnd] = tmp[rightEnd];
    }
}

// 归并排序
void mergeSort(int * nums, int * tmp, int left, int right, int reverse) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(nums, tmp, left, mid, reverse);
        mergeSort(nums, tmp, mid + 1, right, reverse);
        merge(nums, tmp, left, mid + 1, right, reverse);
    }
}

// 每个 node 储存一种解法
typedef struct _Node {
    int *data;
    int len;
    struct _Node *next;
} Node;

Node *create_node(int num) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = (int *) malloc(sizeof(int));
    node->data[0] = num;
    node->len = 1;
    node->next = NULL;

    return node;
}

// 动态规划递归求解
Node *combinationSumHelper(int *candidates, int left, int right, int target) {
    Node *head = NULL;
    Node **ptr = &head;
    // 记录上一次的值，防止重复
    int prev = -1;
    // 从前往后扫描数组
    for (int i = left; i < right; i++) {
        // 如果本次的值与上一次相同，则直接跳过，因为本次的解必然是上一次的子集
        if (prev == candidates[i])
            continue;
        prev = candidates[i];

        // 如果 candidates[i] > target，说明找不到 target 的组合
        if (target < candidates[i]) {
            break;
        }
        // 如果找到一个 candidates[i] 与 target 相等，则创造一个新组合 [target]
        else if (target == candidates[i]) {
            *ptr = create_node(target);
            break;
        }
        // 以 target - candidates[i] 作为子问题进行求解
        *ptr = combinationSumHelper(candidates, i + 1, right, target - candidates[i]);

        // 对于求得的所有子问题解，扩展为当前问题
        while (*ptr) {
            Node *node = *ptr;
            node->data = (int *) realloc((void *) node->data, sizeof(int) * (node->len + 1));
            node->data[node->len++] = candidates[i];
            ptr = &(*ptr)->next;
        }
    }

    return head;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    // 对 candidates 进行排序
    int *tmp = (int *) malloc(sizeof(int) * candidatesSize);
    mergeSort(candidates, tmp, 0, candidatesSize - 1, 0);
    free(tmp);

    // 计算最后总的组合个数
    *returnSize = 0;
    Node *head = combinationSumHelper(candidates, 0, candidatesSize, target);
    Node *node = head;
    while (node) {
        (*returnSize)++;
        node = node->next;
    }

    int **ret = (int **) malloc(sizeof(int *) * (*returnSize));
    *returnColumnSizes = (int *) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        node = head;
        ret[i] = node->data;
        (*returnColumnSizes)[i] = node->len;
        head = head->next;
        free(node);
    }

    return ret;
}

// 此问题是个动态规划问题，将源问题逐渐分解为小问题进行求解
int main(int argc, char *argv[])
{
    int nums[] = {2,5,2,1,2};
    int returnSize;
    int *returnColumnSizes;
    int **ret = combinationSum2(nums, 5, 5, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d, ", ret[i][j]);
        }
        printf("\n");
        free(ret[i]);
    }
    free(returnColumnSizes);
    free(ret);
    return 0;
}
