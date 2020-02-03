#include "../dlink.h"

int dll_remove(DNodeHead *head, DNode *node) {
  if (head == NULL || node == NULL)
    return -1;

  DNode **current = &head->fwd;
  DNode *next;
  do {
    if (*current == node) {
      *current = node->head.fwd;
      if ((next = node->head.fwd)) {
        next->head.bwd = node->head.bwd;
      } else {
        head->bwd = node->head.bwd;
      }
      free(node);
      return 1;
    }
  } while ((current = &(*current)->head.fwd));
  return 0;
}

int main(int argc, char *argv[])
{
  int nums[] = {1, 2, 3, 4, 5};
  DNodeHead *head = create_dlink(nums, 5);
  printf("Print as normal sort:\n");
  print_dlink(head, 0);
  printf("Print as reverse sort:\n");
  print_dlink(head, 1);
  dll_remove(head, head->fwd->head.fwd);
  printf("Print as normal sort:\n");
  print_dlink(head, 0);
  printf("Print as reverse sort:\n");
  print_dlink(head, 1);
  destroy_dlink(&head);
  return 0;
}
