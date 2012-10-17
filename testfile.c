#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(){
  //open up the file and do concatenation to make it work
  char* inputFile = "jboss.txt";
  FILE* fp;
  char* prepend = "./";
  char* append = ".huf";
  char address[20];
  strcpy(address, prepend);
  strcat(address, inputFile);
  fp = fopen(address, "r"); //r+ or w+ (w+ for overwrite)
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
	fprintf(fp, "%c", buffer[i]);
	//	printf("%c", buffer[i]);
      }
      for(i = 0; i < 8; i++){
	//	fprintf(fp, "%c", buffer[i]);
	printf("%c", buffer[i]);
      }
      printf(" ");
      count = 0;
    }
    count++;
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
