#include <stdio.h>
#include <malloc.h>
#include <memory.h>

struct ListNode {
    int val;
    struct ListNode * next;
};

// 从 link 中删除节点 node
// 常规模式
struct ListNode * removeNode(struct ListNode * link, struct ListNode * node) {
    struct ListNode * prev = NULL;
    struct ListNode * walk = link;
    while (walk != node) {
        prev = walk;
        walk = walk->next;
    }
    if (!prev)
        link = node->next;
    else
        prev->next = node->next;
    free(node);
    return link;
}

// 从 link 中删除节点 node
// Linus Torvalds 魔力加持
struct ListNode * removeNodeLinus(struct ListNode * link, struct ListNode * node) {
    struct ListNode ** indirect = &link;
    while ((*indirect) != node) {
        indirect = &((*indirect)->next);
    }
    *indirect = node->next;
    free(node);
    return link;
}
