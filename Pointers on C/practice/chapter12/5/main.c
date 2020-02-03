#include <stdio.h>

#include "../link.h"

int sll_remove(Node **rootp, Node *node) {
  if (rootp == NULL || node == NULL) {
    return -1;
  }

  // 使用寄存器变量避免三次间接访问
  register Node *current;

  while ((current = *rootp)) {
    if (current == node) {
      *rootp = node->next;
      free(node);
      return 1;
    }
    rootp = &current->next;
  }

  return 0;
}

int main(int argc, char *argv[])
{
  int nums[] = {1, 2, 3, 4, 5};
  Node *link = create_link(nums, 5);
  sll_remove(&link, link->next);
  print_link(link);
  destroy_link(&link);
  return 0;
}
