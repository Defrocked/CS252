#include <stdio.h>
#include <stdlib.h>

/*
struct al {
  int maxSize;
  int size;
  int* elements;
};
typedef struct al ArrayList;
*/
typedef struct al {
  int maxSize;
  int size;
  int* elements;
} ArrayList;

ArrayList* alCreate() {
  
  ArrayList* foo;
  foo = (ArrayList*)malloc(1*sizeof(ArrayList));
  foo->maxSize = 10;
  foo->size = 0;

  foo->elements = (int*)malloc((foo->maxSize)*sizeof(int));

  return foo;
}

void alDelete(ArrayList** a) {
  free((*a)->elements);
  free((*a));
  (*a) = NULL; // not quite right...
}

int alSize(const ArrayList* a) {
  return a->size;
}

void alAdd(ArrayList* a, int value) {
  if ((a->size) < (a->maxSize)) {
    (a->elements)[a->size] = value;
  } else {
    // Grow array
  }
  (a->size)++;
}

int alGet(const ArrayList* a, int index) {
  return (a->elements)[index];
}


int main() {

  ArrayList* a = alCreate();

  int s = alSize(a);
  printf("%d\n", s);

  alAdd(a, 5);

  s = alSize(a);
  printf("%d\n", s);
  
  printf("%d\n", alGet(a, 0));

  alDelete(&a);

  //  int x = a->size;

  /*
  // heap
  ArrayList* foo;
  foo = (ArrayList*)malloc(1*sizeof(ArrayList));

  //(*foo).size = 0;
  // or
  foo->size = 0;

  // runtime stack
  ArrayList bar;

  bar.size = 0;
  */
}
