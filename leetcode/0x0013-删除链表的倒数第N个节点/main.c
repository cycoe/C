/* 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。 */

/* 示例： */

/* 给定一个链表: 1->2->3->4->5, 和 n = 2. */

/* 当删除了倒数第二个节点后，链表变为 1->2->3->5. */

/* 说明： */

/* 给定的 n 保证是有效的。 */

/* 进阶： */

/* 你能尝试使用一趟扫描实现吗？ */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list */
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    // 使用了 Linus Torvalds 的魔法
    // 无需使用 if 语句区分移除的是否是头节点
    struct ListNode ** cur = &head; // 第一个指针
    struct ListNode ** fol = &head; // 间隔为 n 的跟随指针
    // cur 先走 n 步
    for (; n > 0; n--)
        cur = &((*cur)->next);
    // 两指针同时移动
    while (*cur) {
        cur = &((*cur)->next);
        fol = &((*fol)->next);
    }
    // 记录待移除节点
    struct ListNode * tmp = *fol;
    // 跨过待移除节点
    *fol = tmp->next;
    free(tmp);
    return head;
}

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    struct ListNode * link = createLink(a, sizeof(a) / sizeof(int));
    link = removeNthFromEnd(link, 5);
    printLink(link);
    freeLink(link);
    return 0;
}
