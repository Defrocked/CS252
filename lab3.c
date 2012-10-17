#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Structures
typedef struct frequency {
  int whatNumber;
  int numOfNum;
    
} Histogram;

//prototypes
int* readScores(int* readIn);
void displayScores(int* numbers, int readIn);
int calcHistogram(Histogram** histo, int* numbers, int readIn);
void displayHistogram(Histogram* histo, int count);
void sortHistogram(Histogram* histo, int* count);

int main(){
  printf("starting\n");
  Histogram* histo;
  int count;
  int readIn = 0;
  int* numbers;
  numbers = readScores(&readIn);
  printf("numbers read in...\n");
  // readScores(numbers, &readIn);
  displayScores(numbers, readIn);
  count = calcHistogram(&histo, numbers, readIn);
  //calcHistogram(histo, &count, numbers, readIn);
  displayHistogram(histo, count);
  sortHistogram(histo, &count);
  displayHistogram(histo, count);
  free(numbers);
  free(histo);
}

int* readScores(int* readIn){
  int* number = (int*)malloc(16*sizeof(int));
  int temp = 0;
  while(scanf("%d\n", &temp) != EOF){
    number[*readIn] = temp;
    (*readIn)++;
  }
  return number;
}

void displayScores(int* numbers, int readIn){
  int i = 0;
  for(i = 0; i < readIn; i++){
    printf("score %d: ", i);
    printf("%d\n", numbers[i]);
  }
}

int calcHistogram(Histogram** histo, int* numbers, int readIn){
  int tmp = 0;
  int k = 0;
  int count = 0;
  Histogram* temporary;
  temporary = (Histogram*)malloc(8*sizeof(Histogram));
  int l = 0;
  for(k = 0; k < readIn; k++){
    while(l < (count) && ((temporary[l]).whatNumber) != numbers[k]){
      l++;
    }
    if( l < count) {
      ((temporary[l]).numOfNum)++;
    } else {
      ((temporary[l]).whatNumber) = (numbers[k]);
      ((temporary[l]).numOfNum) = 1;
      (count)++;
    }
    l = 0;
    *histo = temporary;
  }
  return count;
}

void displayHistogram(Histogram* histo, int count){
  printf("\n\nDisplay:\n");
  int j = 0;
  for(j = 0; j < count; j++){
    printf("value %d: ", histo[j].whatNumber);
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
	tempo = (histo[o].whatNumber);
	(histo[o].whatNumber) = (histo[n].whatNumber);
	(histo[n].whatNumber) = tempo ;
      }
    }
  }
}

