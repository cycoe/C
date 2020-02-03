#include <stdio.h>
#include "../link.h"

unsigned count_nodes(Node *link) {
  unsigned count;
  for (count = 0; link; link = link->next)
    count++;

  return count;
}
