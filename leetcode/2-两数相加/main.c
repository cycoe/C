// this problem need knowledges about single linked list
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>

/*给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。*/
/*如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。*/
/*您可以假设除了数字0之外，这两个数都不会以0开头。*/

/*示例：*/

/*输入：(2->4->3)+(5->6->4)*/
/*输出：7->0->8*/
/*原因：342+465=807*/

// define a data structure of linked list
struct ListNode {
    int val;
    struct ListNode * next;
};

// change an array to a linked list
struct ListNode * init(int * arr, unsigned int len) {
    struct ListNode * ret = NULL; // declare a list node pointer for returning
    struct ListNode * tail = NULL; // declare a list node pointer for cursor

    for (unsigned int i = 0; i < len; i++) {
        // allocate memory for new node
        struct ListNode * node = (struct ListNode *) malloc(sizeof(struct ListNode));
        // you have to set all byte to zero to avoid memory illegal access error in leet code
        // you don't have to set memory manually if you use some compilers support automatic memset
        /* memset(node, 0, sizeof(struct ListNode)); */
        node->val = arr[i];
        node->next = NULL; // you can also set pointer to NULL manually
        if (tail) {
            // if tail already point to an existed node, you should just link the tail node to the new node
            tail->next = node;
            tail = tail->next; // move the tail pointer to the new node
        } else {
            // if tail is NULL, let current pointer point to the new node
            ret = node;
            tail = node;
        }
    }
    return ret;
}

// free linked list memory
void freeListNode(struct ListNode * l) {
    struct ListNode * tmp = l;
    while (l) {
        l = tmp->next;
        free(tmp);
        tmp = l;
    }
}

void printListNode(struct ListNode * l) {
    while (l) {
        printf("%d", l->val);
        l = l->next;
    }
    printf("\n");
}

// add numbers up in two linked list
// number must be smaller than 10 in each node of return
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * ret = NULL;
    struct ListNode * tail = NULL;
    int carry = 0;
    int sum = 0;

    while (l1 || l2 || carry) {
        struct ListNode * node = (struct ListNode *) malloc(sizeof(struct ListNode));
        /* memset(node, 0, sizeof(struct ListNode)); */
        sum = (l1? l1->val: 0) + (l2? l2->val: 0) + carry;
        node->val = sum % 10;
        node->next = NULL;
        carry = sum / 10;

        if (tail) {
            tail->next = node;
            tail = tail->next;
        } else {
            ret = node;
            tail = node;
        }
        l1 = l1? l1->next: NULL;
        l2 = l2? l2->next: NULL;
    }
    return ret;
}

int main() {
    int a[] = {2, 4, 5};
    int b[] = {5, 6, 4, 1, 2};
    struct ListNode * l1 = init(a, 3);
    struct ListNode * l2 = init(b, 5);

    struct ListNode * ret = addTwoNumbers(l1, l2);
    printListNode(ret);

    freeListNode(ret);
    freeListNode(l1);
    freeListNode(l2);

    return 0;
}
