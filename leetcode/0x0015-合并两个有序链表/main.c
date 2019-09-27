/* 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 */ 

/* 示例： */

/* 输入：1->2->4, 1->3->4 */
/* 输出：1->1->2->3->4->4 */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/merge-two-sorted-lists */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <malloc.h>
#include <memory.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// 是否有更好地鏈表初始化方法
struct ListNode * listNodeCreate(int * arr, int size) {
    struct ListNode * head = NULL;
    struct ListNode * node = NULL;
    for (int i = 0; i < size; i++) {
        if (node == NULL) {
            node = (struct ListNode *) malloc(sizeof(struct ListNode));
            head = node;
        }
        else {
            node->next = (struct ListNode *) malloc(sizeof(struct ListNode));
            node = node->next;
        }
        node->val = arr[i];
    }
    return head;
}

void listNodePrint(struct ListNode * head) {
    while (head != NULL) {
        printf("%d, ", head->val);
        head = head->next;
    }
}

void listNodeFree(struct ListNode * head) {
    struct ListNode * tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode * tmp = NULL;
    if (l1->val > l2->val) {
        tmp = l1;
        l1 = l2;
        l2 = tmp;
    }

    struct ListNode * c1 = l1;
    while (c1->next != NULL || l2 != NULL) {
        if (c1->next == NULL) {
            c1->next = l2;
            break;
        }
        else if (l2 == NULL)
            break;

        if (c1->next->val <= l2->val)
            c1 = c1->next;
        else {
            tmp = c1->next;
            c1->next = l2;
            c1 = c1->next;
            l2 = tmp;
        }
    }
    return l1;
}

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 4};
    int b[] = {1 ,3, 4};
    struct ListNode * l1 = listNodeCreate(a, 3);
    struct ListNode * l2 = listNodeCreate(b, 3);
    listNodePrint(mergeTwoLists(l1, l2));
    return 0;
}
