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
  for(i = 0; i < 128; i++){
    //something goes here i don't even know
    // TreeStruct nodeArray
  }
  
}

TreeStruct* createHuffmanTree(TreeStruct* leafNodes){
  /*  
      i mean, i know conceptually how this works, and i could probably
      have gotten this done if i a) started earlier and b) had any idea
      of how the linked list stuff is integrated (it doesn't help that 
      i don't have a lab4 linkedlist to work with but whatever
  */
}

void encodeFile(char* inputFile, TreeStruct* leafNodes){
  //open up the file and do concatenation to make it work
  FILE* fp;
  char* prepend = "./";
  char* append = ".huf";
  char address[20];
  strcpy(address, prepend);
  strcat(address, inputFile);
  fp = fopen(address, "r+"); //r+ or w+ (NO IDEA WHICH)
  // Check the make sure the file name is legit
  if (fp == NULL) {
    printf("Error: The filename you put in doesn't exist.\n"); 
    fflush(stdout);
    exit(1);
  }
  //read through file character by character
  int x;
  int buffer[7];
  int count = 0;
  int i = 0;
  while((x = fgetc(fp)) != EOF){
    //get the codes from the huffman tree
    printf("%c ", x);
    // overwrite the file 8 bits at a time
    buffer[count] = x;
    if(count == 7){
      for(i = 0; i < 8; i++){
	fprintf(fp, "%c", buffer[i]); //some weird ass bit shift thing
      }                               //you can see with printf's but 
      printf(" ");                    //that doesn't matter much when
      count = 0;                      //i'm not sure whether it should
    }                                 //be read in as r+ or w+, cuz
    count++;                          //only r worked with printf's idk
  }
  //pad with 'x' after EOF
  if(count < 7){
    for(i = 0; i < count; i++){
      fprintf(fp, "%c", buffer[i]);
      printf("%c", buffer[i]);
    }
    count = 8 - count;
    for(count = count; count < 8; count++){
      fprintf(fp,"x");
      printf("x");
    }
  }
  //append .huf
  strcat(address, append);
  fclose(fp);
}

void decodeFile(char* outputFile, TreeStruct* treeRoot){
 //open up the file and do concatenation to make it work
  FILE* fp;
  char* prepend = "./";
  char address[20];
  strcpy(address, prepend);
  strcat(address, outputFile);
  fp = fopen(address, "r"); //r+ or w+ (w+ for overwrite)
  // Check the make sure the file name is legit
  if (fp == NULL) {
    printf("Error: The filename you put in doesn't exist.\n"); 
    fflush(stdout);
    exit(1);
  }
  //read through file character by character
  int x;
  while((x = fgetc(fp)) != EOF){
    //somehow travel up the tree i haven't written yet to the root node
    //then decode the file from root -> leaves (opposite of encoding)
  }
  

  fclose(fp);
}
