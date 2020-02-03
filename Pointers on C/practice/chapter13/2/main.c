#include "../link.h"
#include <stdio.h>

// 声明的函数类型必须于回调函数的原型匹配
void *handle_node(void *arg) {
  // 此处需要对 void* 类型的指针进行转换
  Node *node = (Node *)arg;
  printf("%d ", node->value);
  return node->next;
}

int walk_link(void *head, void *(*handle_node)(void *)) {
  if (head == NULL)
    return 0;

  while (head) {
    head = handle_node(head);
  }
  return 1;
}

int main(int argc, char *argv[])
{
  int nums[] = {1, 2, 3, 4, 5};
  Node *link = create_link(nums, 5);
  // void* 类型的指针可以接收任意类型的指针
  walk_link(link, handle_node);
  destroy_link(&link);
  return 0;
}
