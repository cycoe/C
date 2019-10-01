/* 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 */

/* 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 */

 

/* 示例: */

/* 给定 1->2->3->4, 你应该返回 2->1->4->3. */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * createLink(int * nums, int numsSize) {
    if (numsSize == 0)
        return NULL;

    struct ListNode * head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->val = nums[0];
    head->next = NULL;

    struct ListNode * cur = head;
    for (int i = 1; i < numsSize; i++) {
        cur->next = (struct ListNode *) malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = nums[i];
        cur->next = NULL;
    }
    return head;
}

void printLink(struct ListNode * head) {
    while (head) {
        printf("Node at address %p has value: %d\n", head, head->val);
        head = head->next;
    }
}

void freeLink(struct ListNode * head) {
    struct ListNode * cur;
    while (head) {
        cur = head;
        head = head->next;
        free(cur);
    }
}

struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL)
        return head;

    struct ListNode * prev = (struct ListNode *) malloc(sizeof(struct ListNode));
    prev->next = head;
    struct ListNode * tmp = prev;
    struct ListNode * left;
    struct ListNode * right;
    while (tmp->next && tmp->next->next) {
        left = tmp->next;
        right = tmp->next->next;
        tmp->next = right;
        left->next = right->next;
        right->next = left;
        tmp = left;
    }
    head = prev->next;
    free(prev);
    return head;
}

// 递归大法
struct ListNode* swapPairsRecur(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode * next = head->next;
    head->next = swapPairsRecur(next->next);
    next->next = head;
    return next;
}

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    struct ListNode * link = createLink(a, sizeof(a) / sizeof(int));
    link = swapPairsRecur(link);
    printLink(link);
    freeLink(link);
    return 0;
}
