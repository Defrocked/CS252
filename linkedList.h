/*HUFFMAN COMPRESSION ASSIGNMENT 1 CS252 MIKEY BEAUCHAMP */

//LINKEDLIST.C STRUCTURES AND METHODS
#include <stdio.h>
#include <stdlib.h>

/*
problems with linkedList.h:
First this isnt based off the lab because I don't think I did the lab that week (was it the same week as the 245 assigment 1? This is just the in class code. 
Second need to change this from a linked list of strings to linked list of huffman tree nodes.
Third add method list_add_in_order which works like the current add except that it takes the data in question and searches down the linked list from the given point and places the node "in order" into the list" "in order" will be based on weights so that the lowest 2 weighted nodes will always be at the front. Yeah I don't even know.
 */

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

