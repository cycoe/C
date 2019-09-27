/* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 */

/* 有效字符串需满足： */

/*     左括号必须用相同类型的右括号闭合。 */
/*     左括号必须以正确的顺序闭合。 */

/* 注意空字符串可被认为是有效字符串。 */

/* 示例 1: */

/* 输入: "()" */
/* 输出: true */

/* 示例 2: */

/* 输入: "()[]{}" */
/* 输出: true */

/* 示例 3: */

/* 输入: "(]" */
/* 输出: false */

/* 示例 4: */

/* 输入: "([)]" */
/* 输出: false */

/* 示例 5: */

/* 输入: "{[]}" */
/* 输出: true */

/* 来源：力扣（LeetCode） */
/* 链接：https://leetcode-cn.com/problems/valid-parentheses */
/* 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <memory.h>

struct Node {
    char c;
    struct Node * next;
};

void push(struct Node ** head_ptr, char c) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->c = c;
    node->next = *head_ptr;
    *head_ptr = node;
}

char pop(struct Node ** head_ptr) {
    if (*head_ptr == NULL)
        return 0;

    struct Node * tmp = *head_ptr;
    *head_ptr = tmp->next;

    char c = tmp->c;
    free(tmp);
    return c;
}

void stackFree(struct Node * head) {
    struct Node * tmp = head;
    while (head != NULL) {
        head = head->next;
        free(tmp);
        tmp = head;
    }
}

// 使用栈來處理非常方便
bool isValid(char * s){
    struct Node * head = NULL;
    while (*s != 0) {
        // 此處使用哈希表來處理可以節省三分之一的時間，但空間開銷會增大
        if (head != NULL && (*s == head->c + 1 || *s == head->c + 2))
            // 栈非空並且可以配對時彈出
            pop(&head);
        else
            // 壓入栈
            push(&head, *s);
        ++s;
    }

    if (head == NULL)
        return 1;
    else {
        stackFree(head);
        return 0;
    }
}

int main(int argc, char *argv[])
{
    char * s = "[]([]{})";
    printf("%s is %svalid\n", s, isValid(s)? "": "not ");
    s = "[]([]{}";
    printf("%s is %svalid\n", s, isValid(s)? "": "not ");
    return 0;
}
