#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char* value;
  struct node* next;
  int* size;
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

void llAdd(LinkedList** ll, char* str, int** size) {

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
  ll->size++;
}

int* size(LinkedList* ll){
  return *(ll.size);
}

int main() {
  
  LinkedList* ll = llCreate();
  llDisplay(ll);
  int* size = 0;
  char* s = (char*)malloc(6*sizeof(char));
  s[0] = 'h';
  s[1] = 'e';
  s[2] = 'l';
  s[3] = 'l';
  s[4] = 'o';
  s[5] = '\0';

  llAdd(&ll, s, &size);
  //  llAdd(ll, 5);
  //  llAdd(ll, 7);
  llDisplay(ll);
}
