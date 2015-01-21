#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  struct node *next;
  int val;
} node;

node* new_node(int val) {
  node *t = malloc(sizeof *t);
  t->val = val;
  t->next = 0;
  return t;
}

void add(node* n, int val) {
  while(n->next)
    n = n->next;
  n->next = new_node(val);
}

void print(node* n) {
  while(n) {
    printf("%d ", n->val);
    n = n->next;
  }
  printf("\n");
}

int main(void) {
  node *h = new_node(1);

  for(int i = 2; i < 10; i++)
    add(h, i);

  print(h);

  return 0;
}
