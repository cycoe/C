/* 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 */

/* candidates 中的数字可以无限制重复被选取。 */

/* 说明： */

/*     所有数字（包括 target）都是正整数。 */
/*     解集不能包含重复的组合。 */ 

/* 示例 1: */

/* 输入: candidates = [2,3,6,7], target = 7, */
/* 所求解集为: */
/* [ */
/*   [7], */
/*   [2,2,3] */
/* ] */

/* 示例 2: */

/* 输入: candidates = [2,3,5], target = 8, */
/* 所求解集为: */
/* [ */
/*   [2,2,2,2], */
/*   [2,3,3], */
/*   [3,5] */
/* ] */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/combination-sum */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

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
Node *combinationSumHelper(int *candidates, int candidatesSize, int target, int max) {
    Node *head = NULL;
    Node **ptr = &head;
    // 从前往后扫描数组
    for (int i = 0; i < candidatesSize; i++) {
        // 如果 candidates[i] > target，说明找不到 target 的组合
        // 如果 candidates[i] > max，说明会出现重复组合
        if (target < candidates[i] || max < candidates[i]) {
            break;
        }
        // 如果找到一个 candidates[i] 与 target 相等，则创造一个新组合 [target]
        else if (target == candidates[i]) {
            *ptr = create_node(target);
            break;
        }
        // 以 target - candidates[i] 作为子问题进行求解，并且子问题的解最大值不超过 candidates[i]
        *ptr = combinationSumHelper(candidates, candidatesSize, target - candidates[i], candidates[i]);

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

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    // 就地去除重复数字，newSize 为新数组的长度
    int newSize = 1;
    for (int i = 1; i < candidatesSize; i++) {
        if (candidates[i] != candidates[newSize - 1]) {
            candidates[newSize] = candidates[i];
            newSize++;
        }
    }

    // 对 candidates 进行排序
    int *tmp = (int *) malloc(sizeof(int) * newSize);
    mergeSort(candidates, tmp, 0, newSize - 1, 0);
    free(tmp);

    // 计算最后总的组合个数
    *returnSize = 0;
    Node *head = combinationSumHelper(candidates, newSize, target, target);
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
    free(head);

    return ret;
}

// 此问题是个动态规划问题，将源问题逐渐分解为小问题进行求解
int main(int argc, char *argv[])
{
    int nums[] = {2, 3, 5};
    int returnSize;
    int *returnColumnSizes;
    int **ret = combinationSum(nums, 3, 8, &returnSize, &returnColumnSizes);

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
