#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Structures
typedef struct frequency {
  char* whatNumber;
  int numOfNum;
    
} Histogram;

//prototypes
char** readScores(int* readIn);
void displayScores(char** numbers, int readIn);
int calcHistogram(Histogram** histo, char** numbers, int readIn);
void displayHistogram(Histogram* histo, int count);
void sortHistogram(Histogram* histo, int* count);

int main(){
  printf("starting\n");
  Histogram* histo;
  int count;
  int readIn = 0;
  char** numbers;
  numbers = readScores(&readIn);
  printf("strings read in...\n");;
  displayScores(numbers, readIn);
  printf("before histogram\n");
  count = calcHistogram(&histo, numbers, readIn);
  printf("after calchisto\n");
  displayHistogram(histo, count);
  printf("after disphisto1\n");
  sortHistogram(histo, &count);
  printf("\n after sorthisto\n");
  displayHistogram(histo, count);
  printf("after disphisto2\n");
  int p;
  for(p = 0; p < readIn; p++){
    free(numbers[p]);
   }
  free(numbers);
  free(histo);
}

char** readScores(int* readIn){
  char** number = (char**)malloc(1024*sizeof(char*));
  char* temporary = (char*)malloc(1024*sizeof(char));
  while(scanf("%s", temporary) != EOF){
    number[*readIn] = temporary;
    (*readIn)++;
    temporary = (char*)malloc(1024*sizeof(char));
  }
  free(temporary);
  return number;
}

void displayScores(char** numbers, int readIn){
  int i = 0;
   for(i = 0; i < readIn; i++){
   printf("string %d: ", i);
   printf("%s\n", numbers[i]);
  }
}

int calcHistogram(Histogram** histo, char** numbers, int readIn){
  int tmp = 0;
  int k = 0;
  int count = 0;
  Histogram* tempo;
  tempo = (Histogram*)malloc(8*sizeof(Histogram));
  int l = 0;
  for(k = 0; k < readIn; k++){
    while(l < (count) && strcmp(((tempo[l]).whatNumber), ((numbers[k]))) != 0){
      l++;
    }
    if( l < count) {
      ((tempo[l]).numOfNum)++;
    } else {
      (tempo[l]).whatNumber = (numbers[k]);
      ((tempo[l]).numOfNum) = 1;
      (count)++;
    }
    l = 0;
    *histo = tempo;
  }
  return count;
}

void displayHistogram(Histogram* histo, int count){
  printf("\n\nDisplay:\n");
  int j = 0;
  for(j = 0; j < count; j++){
    printf("value %s: ", histo[j].whatNumber);
    printf("freq %d\n",  histo[j].numOfNum);
  }
}

void sortHistogram(Histogram* histo, int* count){
  int n;
  int o;
  int tempo = 0;
  for ( n = 0 ; n < (*count) ; n++ ){
    for ( o = n ; o < (*count) ; o++ ){
      if ( (histo[o].numOfNum) > (histo[n].numOfNum) ){
	tempo = (histo[o].numOfNum);
	(histo[o].numOfNum) = (histo[n].numOfNum);
	(histo[n].numOfNum) = tempo ;
	tempo = (*(histo[o]).whatNumber);
	(histo[o].whatNumber) = (histo[n].whatNumber);
	(*(histo[n]).whatNumber) = tempo ;
      }
    }
  }
}

