/*HUFFMAN COMPRESSION ASSIGNMENT 1 CS252 MIKEY BEAUCHAMP */
 
//HCOMPRESS.C STRUCTURES AND METHODS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct tnode {
  double weight;
  int c;
  struct tnode* left;
  struct tnode* right;
  struct tnode* parent;
} TreeStruct;

TreeStruct* createFreqTable(char* textFile){
  //open up the file and do concatenation to make it work
  FILE* fp;
  char* prepend = "./";
  char address[20];
  strcpy(address, prepend);
  strcat(address, textFile);
  fp = fopen(address, "r");
  // Check the make sure the file name is legit
  if (fp == NULL) {
    printf("Error: The filename you put in doesn't exist.\n"); 
    fflush(stdout);
    exit(1);
  }
  //create and zero out the array
  int frequencyArray[128];
  int i = 0;
  for(i = 0; i < 128; i++){
    frequencyArray[i] = 0;
  }
  //populate the array
  int x;
  while((x = fgetc(fp)) != EOF){
    frequencyArray[x] ++;
  }
  fclose(fp);
  //convert array to linkedList to be returned
  LinkedList* ll = llCreate();
  llDisplay(ll);
  for(i = 0; i < 128; i++){
    //something goes here i don't even know
  }
  
}

TreeStruct* createHuffmanTree(TreeStruct* leafNodes){

}

void encodeFile(char* outputFile, TreeStruct* leafNodes){

}

void decodeFile(char* outputFile, TreeStruct* treeRoot){

}
