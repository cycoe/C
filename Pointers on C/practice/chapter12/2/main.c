#include <unistd.h>
#include "../link.h"

Node *search_node(Node *link, int value) {
  while (link) {
    if (link->value == value)
      return link;
  }
  return NULL;
}

Node *search_sorted_node(Node *link, int value) {
  while (link) {
    if (link->value == value)
      return link;
    if (link->value > value)
      break;
  }

  return NULL;
}
