#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//prototyping
int fibonacci(int n);
long long fibonacciLong(int n);
void fibIntMax();
void fibLongMax();
void finiteRepresentation();
int binToDec(char* bin);
int baseToDec(char* bin, int base);
char* decToBin(int dec);

//CODE
int main(){
  //testing fibonacci code
  int a = 6;
  int b = 0;  
  b = fibonacci(a);
  printf("%d \n", b);
  //max values
  fibIntMax();
  fibLongMax();
  //doubles n stuff
  finiteRepresentation();
  //number conversion
  int decimal = binToDec("101");
  printf("decimal %d \n", decimal);

}

int fibonacci(int n){
  int first = 0;
  int second = 1;
  int next = 0;
  int i = 0;
  for(i = 0; i < n-1; i++){
    next = first + second;
    first = second;
    second = next;
  }
  return next;
}

long long fibonacciLong(int n){
  long long first = 0;
  long long second = 1;
  long long next = 0;
  int i = 0;
  for(i = 0; i < n-1; i++){
    next = first + second;
    first = second;
    second = next;
  }
  return next;
}

void fibIntMax(){
  // -2,147,483,648 to 2,147,483647
  int maximumInt = 2147483647;
  int maxFib;
  int check = 0;
  int input = 0;
  while (check < maximumInt && check > -1){
    check = fibonacci(input);
    // printf("%d \n", check);
    // printf("%d \n", input);
    input++;
  }
  maxFib = input -2;
  printf("MAXIMUM INT (FIBONACCI INPUT) %d \n", maxFib); //46
}

void fibLongMax(){
  // - 9,223,372,036,854,775,808 to 9,224,372,036,854,775,807
  long long maximumLong = 9223372036854775807;
  int maxFib;
  long long check = 0;
  int input = 0;
  while (check < maximumLong && check > -1){
    check = fibonacciLong(input);
    // printf("%lld \n", check);
    // printf("%d \n", input);
    input++;
  }
  maxFib = input -2;
  printf("MAXIMUM LONG (FIBONACCI INPUT) %d \n", maxFib); //92
}

void finiteRepresentation(){
  double num0 = 0.2;
  double num1 = 0.2;
  double num2 = 0.2;
  double num3 = 0.6;
  double num4 = num0 + num1 + num2 - num3;
  double booleans;
  /*
    if (num4 > 0){
    booleans = 1;
    }else if(num4 < 0){
    booleans = -1;
    }else{
    booleans = 0;
    }
  */
  if (num4 > 0.00001){
    booleans = 1;
  }else if(num4 < 0){
    booleans = -1;
  }else{
    booleans = 0;
  }

  //honestly i'm learning more about printf than anything else
  //printf doesn't print 0 without the .1 precision flag
  //booleans prints 1 if %d, and prints 0.000000 if %f
  //wow you explained precision after i spent 20 minutes figuring it out fuck me
  printf("num0 %f \nnum1 %f \nnum2 %f \nnum3 %f \nnum4 %.1f \nbooleans %f \n"
	 , num0, num1, num2, num3, num4, booleans);
}

int binToDec(char* bin){
  int i = 0;                         //WORK ON THIS SHIT ONCE HE SHOWS US THE
  int dec;                           //DEBUGGER TOMORROW IN CLASS (THURSDAY)
  while (bin[i] != '/0'){            //REMINDER: MAKE SURE STEVENSON CHECKS OFF 
    if(bin[i] = 1){                  //245 HASHMAPS LAB
      dec = dec + ((int)pow((float)2,(float) i));
    }   
    i++;
  }
  return dec;
}

int baseToDec(char* bin, int base){
  int i = 0;
  int dec;
   while (bin[i] != NULL){
     if(bin[i] = 1){
       dec = dec + ((int)pow((float)bin[i],(float) i) * base);
     }   
 i++;
  }
  return dec;
}
/*
char* decToBin(int dec){
  //somehow convert the int to a char* //LOOK UP SPRINTF
  char* bin;
  while( bin[i] != NULL){
    bin[i] = (int)bin[i]; //something with a base or idk whatever im going to bed
    
    i++;
  } 
}
*/
