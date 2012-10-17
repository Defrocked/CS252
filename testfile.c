#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>






int main(){
  char* textFile = "decind.txt";
 FILE* fp;
  char* prepend = "./Assignment1/";
  char address[20];
  strcpy(address, prepend);
  strcat(address, textFile);
  fp = fopen(address, "r");
  // Check the make sure the file name is legit
  if (fp == NULL) {
    printf("Error: The filename you put in doesn't exist. Maybe you typed it wrong.\n"); 
    fflush(stdout);
    exit(1);
  }
  int frequencyArray[128];
  int i = 0;
  for(i = 0; i < 128; i++){
    frequencyArray[i] = 0;
  }
  int x;
  while((x = fgetc(fp)) != EOF){
    //  printf( "%d ", x );
    frequencyArray[x] ++;
  }
  for(i = 0; i < 128; i++ ){
    printf("%d ", frequencyArray[i]);
  }
  

  fclose(fp);

}
