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

node *rev(node *h) {
  node *p = 0, *c = h, *n = h->next;
  while(n) {
    c->next = p;
    p = c;
    c = n;
    n = n->next;
  }
  c->next = p;
  return c;
}

void rec_rev(node **h) {
  if (!(*h) || !(*h)->next)
    return;

  node* rest = (*h)->next;
  rec_rev(&rest);
  (*h)->next->next  = *h;
  (*h)->next  = 0;
 
  *h = rest;
}

int main(void) {
  node *h = new_node(1);

  for(int i = 2; i < 10; i++)
    add(h, i);

  print(h);
  //print(rev(h));
  rec_rev(&h);
  print(h);
  return 0;
}
