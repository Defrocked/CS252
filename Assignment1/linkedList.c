/*HUFFMAN COMPRESSION ASSIGNMENT 1 CS252 MIKEY BEAUCHAMP */

#include "linkedList.h"

/*
shit i have to do still: first this isnt based off the lab cuz idt i even did this lab so fuck. this is just the in class code. second need to chance this from a linked list of strings to linked list of humman tree nodes. third add method list_add_in_order which works like the current add except that it takes the data in question and searches down the linked list from the given point and places the node "in order" into the list" "in oder" will be based on weights so that the lowest 2 weighted nodes will always be at the front.
 */

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
