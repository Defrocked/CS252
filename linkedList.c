/*HUFFMAN COMPRESSION ASSIGNMENT 1 CS252 MIKEY BEAUCHAMP */

#include "linkedList.h"

int main() {
  
  LinkedList* ll = llCreate();
  llDisplay(ll);
  
  char* s = (char*)malloc(6*sizeof(char));
  s[0] = 'h';
  s[1] = 'e';
  s[2] = 'l';
  s[3] = 'l';
  s[4] = 'o';
  s[5] = '\0';

  llAdd(&ll, s);
  //  llAdd(ll, 5);
  //  llAdd(ll, 7);
  llDisplay(ll);
}
