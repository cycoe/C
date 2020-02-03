#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *create_link(int nums[], unsigned size) {
  Node *head;
  Node **curent = &head;
  for (int i = 0; i < size; i++) {
    *curent = (Node *)malloc(sizeof(Node));
    (*curent)->value = nums[i];
    (*curent)->next = NULL;
    curent = &(*curent)->next;
  }
  return head;
}

void destroy_link(Node **linkptr) {
  if (linkptr == NULL)
    return;

  Node *link;
  while (*linkptr) {
    link = *linkptr;
    *linkptr = link->next;
    free(link);
  }
}

void print_link(Node *link) {
  do {
    printf("%d ", link->value);
  } while ((link = link->next));
  printf("\n");
}
