#include <malloc.h>
#include <memory.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct _Node {
  char *s;
  struct _Node *next;
} Node;

typedef struct {
  int len;
  int *map;
  Node *link;
} Group;

Node *createNode(Node *next, char *s) {
  Node *node = (Node *) malloc(sizeof(Node));
  node->s = s;
  node->next = next;
  return node;
}

void insertNode(Group *group, Node *node) {
  group->len++;
  group->link = node;
}

Group *createGroup(Node *node, int *map) {
  Group *group = (Group *) malloc(sizeof(Group));
  group->len = 1;
  group->map = (int *) malloc(sizeof(int) * 26);
  for (int i = 0; i < 26; i++)
    group->map[i] = map[i];
  group->link = node;
  return group;
}

void destroyGroup(Group *group) {
  Node *node = NULL;
  while (group->link) {
    node = group->link;
    group->link = group->link->next;
    free(node);
  }
  free(group->map);
  free(group);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
  int *count = (int *) malloc(sizeof(int) * 26);
  *returnSize = 0;
  Group **groups = NULL;

  // count alphabets in str
  for (int i = 0; i < strsSize; i++) {
    memset(count, 0, sizeof(int) * 26);
    char *str = strs[i];
    while (*str) {
      count[*str - 'a'] += 1;
      ++str;
    }
    str = strs[i];

    int j;
    for (j = 0; j < *returnSize; j++) {
      int k;
      for (k = 0; k < 26; k++) {
	if (groups[j]->map[k] != count[k])
	  break;
      }
      if (k == 26) {
	insertNode(groups[j], createNode(groups[j]->link, str));
	break;
      }
    }
    if (j == *returnSize) {
      groups = realloc(groups, sizeof(Group *) * (*returnSize + 1));
      groups[*returnSize] = createGroup(createNode(NULL, str), count);
      *returnSize += 1;
    }
  }

  char ***ret = (char ***) malloc(sizeof(char **) * (*returnSize));
  *returnColumnSizes = (int *) malloc(sizeof(int *) * (*returnSize));
  for (int i = 0; i < *returnSize; i++) {
    Group *group = groups[i];
    (*returnColumnSizes)[i] = group->len;
    ret[i] = (char **) malloc(sizeof(char*) * group->len);
    Node *node = group->link;
    for (int j = 0; j < group->len; j++) {
      ret[i][j] = node->s;
      node = node->next;
    }
    destroyGroup(group);
  }
  free(groups);
  free(count);

  return ret;
}

int main(int argc, char *argv[])
{
  char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
  int returnSize;
  int *returnColumnSizes;
  char ***ret = groupAnagrams(strs, sizeof(strs) / sizeof(char *), &returnSize, &returnColumnSizes);
  for (int i  = 0; i < returnSize; i++) {
    for (int j = 0; j < returnColumnSizes[i]; j++) {
      printf("%s ", ret[i][j]);
    }
    printf("\n");
    free(ret[i]);
  }
  free(ret);
  free(returnColumnSizes);
  return 0;
}

