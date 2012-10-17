/*HUFFMAN COMPRESSION ASSIGNMENT 1 CS252 MIKEY BEAUCHAMP */

//LINKEDLIST.C STRUCTURES AND METHODS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char* value;
  struct node* next;
} LinkedList;

LinkedList* llCreate() {
  return NULL;
}

void llDisplay(LinkedList* ll) {
  LinkedList* p = ll;

  printf("[");
  while (p != NULL) {   
    printf(" %s ", p->value);   // (*p).value
    p = p->next;
  }

  printf("]\n");
}

void llAdd(LinkedList** ll, char* str) {

  LinkedList* nn = (LinkedList*)malloc(1*sizeof(LinkedList));
  nn->value = str;
  nn->next = NULL;

  // Find the end of the list
  LinkedList* p = *ll;

  if (p == NULL) {
    // adding to empty list
    *ll = nn;

  } else {
    while (p->next != NULL) {   
      p = p->next;
    }
    p->next = nn;
  }
}

