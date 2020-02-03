#include <stdio.h>
#include <unistd.h>

#include "../link.h"

Node *sll_reverse_helper(Node *link) {
  Node *head;
  if (link->next) {
    head = sll_reverse_helper(link->next);
    link->next->next = link;
    return head;
  } else {
    return link;
  }
}

Node *sll_reverse(Node *link) {
  if (link == NULL)
    return NULL;

  Node *head = sll_reverse_helper(link);
  link->next = NULL;
  return head;
}

int main(int argc, char *argv[])
{
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Node *link = create_link(nums, 10);
  printf("The original array is:\n");
  print_link(link);
  link = sll_reverse(link);
  printf("The reversed array is:\n");
  print_link(link);
  destroy_link(&link);
  return 0;
}
