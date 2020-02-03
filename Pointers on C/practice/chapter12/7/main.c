#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUL 0
#define WHITESPACE " .,?!'\""

struct Node;

typedef struct Table {
  char alpha;
  struct Table *next;
  struct Node *node;
} Table;

typedef struct Node {
  char *word;
  struct Node *next;
} Node;

Table *create_table(Table **table, const char alpha) {
  Table *new = (Table *)malloc(sizeof(Table));
  new->next = *table;
  new->alpha = alpha;
  *table = new;
  return *table;
}

Node *create_node(Node **node, const char *word) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->next = *node;
  new->word = (char *)malloc(strlen(word) + 1);
  strcpy(new->word, word);
  *node = new;
  return *node;
}

Table **insert_table(Table **table, char alpha) {
  if (table == NULL)
    return NULL;

  while (*table && alpha > (*table)->alpha) {
    table = &(*table)->next;
  }

  if (*table == NULL || (*table)->alpha != alpha)
    create_table(table, alpha);

  return table;
}

Node **insert_node(Node **node, const char *word) {
  if (node == NULL || word == NULL)
    return NULL;

  /* strcmp return a negative number if s1 < s2, maybe not -1
   * return a positive number if s1 > s2, maybe not 1
   * return 0 if s1 == s2
   */
  while (*node && strcmp(word, (*node)->word) > 0) {
    node = &(*node)->next;
  }

  if (*node == NULL || strcmp(word, (*node)->word) != 0)
    create_node(node, word);

  return node;
}

int insert_word(Table **tableHead, const char *word) {
  if (word == NULL || *word < 'a' || *word > 'z')
    return 0;

  Table **table;
  if ((table = insert_table(tableHead, *word)) &&
      insert_node(&(*table)->node, word))
    return 1;
  else
    return 0;
}

void print_table(Table **tableHead) {
  Node **node;
  while (*tableHead) {
    printf("Words begin with '%c'\n", (*tableHead)->alpha);
    fflush(stdout);
    node = &(*tableHead)->node;
    while (*node) {
      printf("%s ", (*node)->word);
      fflush(stdout);
      node = &(*node)->next;
    }
    printf("\n\n");
    fflush(stdout);
    tableHead = &(*tableHead)->next;
  }
}

void parse_line(Table **table, char *buff) {
  char *token;
  for (token = strtok(buff, WHITESPACE); token != NULL;
       token = strtok(NULL, WHITESPACE)) {
    insert_word(table, token);
  }
}

int main(int argc, char *argv[])
{
  Table *table = NULL;
  char buff[4096];
  while (fgets(buff, 4095, stdin)) {
    parse_line(&table, buff);
  }
  print_table(&table);
  return 0;
}
