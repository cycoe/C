#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct DNode;

typedef struct DNodeHead {
  struct DNode *fwd;
  struct DNode *bwd;
} DNodeHead;

typedef struct DNode {
  DNodeHead head;
  int value;
} DNode;

DNodeHead *create_dlink(int nums[], unsigned size) {
  DNodeHead *head = (DNodeHead *)malloc(sizeof(DNodeHead));
  if (head == NULL)
    return NULL;

  head->fwd = NULL;
  head->bwd = NULL;

  DNode *current = NULL, *newNode = NULL;
  for (int i = 0; i < size; i++) {
    newNode = (DNode *)malloc(sizeof(DNode));
    if (newNode == NULL)
      break;

    newNode->value = nums[i];
    if (current) {
      current->head.fwd = newNode;
    } else {
      head->fwd = newNode;
    }
    newNode->head.bwd = current;
    current = newNode;
  }
  if (current)
    current->head.fwd = NULL;
  head->bwd = current;
  return head;
}

void destroy_dlink(DNodeHead **head) {
  if (head == NULL)
    return;

  DNode *node;
  while ((node = (*head)->fwd)) {
    (*head)->fwd = node->head.fwd;
    free(node);
  }
  free(*head);
  *head = NULL;
}

void print_dlink(DNodeHead *head, int reverse) {
  DNode *node = reverse ? head->bwd : head->fwd;
  do {
    printf("%d ", node->value);
  } while ((node = reverse ? node->head.bwd : node->head.fwd));
  printf("\n");
}
