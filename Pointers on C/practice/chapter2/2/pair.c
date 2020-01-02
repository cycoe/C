#include <malloc.h>
#include <stdio.h>

typedef struct _Node {
  char ch;
  struct _Node *next;
} Node;

typedef struct {
  Node *link;
} Pool;

Node *create_node(char ch) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->ch = ch;
  node->next = NULL;
  return node;
}

Pool *create_pool() {
  Pool *pool = (Pool *)malloc(sizeof(Pool));
  pool->link = NULL;
  return pool;
}

void free_link(Node **link) {
  for (Node *node = NULL; *link; free(node)) {
    node = *link;
    *link = (*link)->next;
  }
}

void free_pool(Pool **pool) {
  free_link(&(*pool)->link);
  free(*pool);
  *pool = NULL;
}

void push(Pool *pool, Node *node) {
  node->next = pool->link;
  pool->link = node;
}

Node *pop(Pool *pool) {
  Node *node = NULL;
  if (pool->link) {
    node = pool->link;
    pool->link = node->next;
    node->next = NULL;
  }

  return node;
}

int main(int argc, char *argv[]) {
  Pool *stack = create_pool();
  Pool *buff = create_pool();
  Node *node;

  char ch;
  while ((ch = getchar()) != EOF) {
    if (ch == '{') {
      if ((node = pop(buff)) == NULL)
        node = create_node(ch);
      else
        node->ch = ch;

      printf("push...\n");
      push(stack, node);
    } else if (ch == '}' && stack->link && stack->link->ch == '{') {
      printf("pop...\n");
      node = pop(stack);
      push(buff, node);
    }
  }

  if (stack->link)
    printf("All brackets cannot be paired!\n");
  else
    printf("All brackets can be paired!\n");

  free_pool(&stack);
  free_pool(&buff);
  return 0;
}
