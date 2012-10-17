#include <stdio.h>
#include <stdlib.h>

//Structures
typedef struct frequency {
  int whatNumber;
  int numOfNum;

} freq;

//prototypes
void readScores(int* numbers, int* readIn);
void displayScores(int* numbers, int readIn);
void calcHistogram(freq* histo, int* count, int* numbers, int readIn);
void displayHistogram(freq* histo, int count);
void sortHistogram(freq* histo, int* count);

int main(){
  int numbers[100];
  freq histo[15];
  int count = 0;
  int readIn = 0;
  readScores(numbers, &readIn);
  displayScores(numbers, readIn);
  calcHistogram(histo, &count, numbers, readIn);
  displayHistogram(histo, count);
  sortHistogram(histo, &count);
  displayHistogram(histo, count);
}

void readScores(int* numbers, int* readIn){
  int temp = 0;
   while(scanf("%d\n", &temp) != EOF){
    *(numbers + *readIn) = temp;
    (*readIn)++;
   }
}

void displayScores(int* numbers, int readIn){
  int i = 0;
  for(i = 0; i < readIn; i++){
    printf("score %d: ", i);
    printf("%d\n", *(numbers + i));
  }
}

void calcHistogram(freq* histo, int* count, int* numbers, int readIn){
  int tmp = 0;
  int k = 0;
  *count = 0;
  int l = 0;
  for(k = 0; k < readIn; k++){
    while(l < (*count) && ((*(histo + l)).whatNumber) != (*(numbers + k))  ){
      l++;
    }
    if( l < *count) {
      ((*(histo + l)).numOfNum)++;
    } else {
      ((*(histo + l)).whatNumber) = (*(numbers + k));
      ((*(histo + l)).numOfNum) = 1;                  
      (*count)++;
    }
    l = 0;
  }
}

void displayHistogram(freq* histo, int count){
  printf("\n\nDisplay:\n");
  int j = 0;
  for(j = 0; j < count; j++){
    printf("value %d: ", (((*(histo+j)).whatNumber)));
    printf("freq %d\n",  (((*(histo+j)).numOfNum)));
  }
}

void sortHistogram(freq* histo, int* count){
 int n;
 int o;
 int tempo = 0;
 for ( n = 0 ; n < (*count) ; n++ ){
   for ( o = n ; o < (*count) ; o++ ){
     if ( ((*(histo + o)).numOfNum) > ((*(histo + n)).numOfNum) ){
	tempo = ((*(histo + o)).numOfNum);
       ((*(histo + o)).numOfNum) = ((*(histo + n)).numOfNum);
       ((*(histo + n)).numOfNum) = tempo ;
       tempo = ((*(histo + o)).whatNumber);
       ((*(histo + o)).whatNumber) = ((*(histo + n)).whatNumber);
       ((*(histo + n)).whatNumber) = tempo ;
     }
   }
 }
}
