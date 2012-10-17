/* second half of lab6 */
#include <stdio.h>
#include <stdlib.h>

//union
typedef union fi {
   unsigned int i;
   float f;
}fi;

//prototypes
void displayFloat(float f);
float makeFloat(char* f);
void decToBin(char* cc, int input);

void displayFloat(float f){
  fi fint;
  fint.f = f;
  unsigned int c, displayMask = 1 << 31; // only compare the last bit
  
  printf( "%7f = ", f ); //displays the float's value
  for ( c = 1; c <= 32; c++ ) { 
    // use the mask to test and see if it's set(1) else put 0
    putchar( fint.i & displayMask ? '1' : '0' );
    fint.i <<= 1;
    // space to separate sign and bias from mantissa
    if ( c == 1 ){
      putchar( ' ' );
    }
    if ( c == 9 ){
      putchar( ' ' );
    }
  }
  putchar( '\n' );
}

void decToBin(char* cc, int input){
  int i;
  int k;
 
  for (i = 7; i >= 0; i--)
  {
    k = input >> i;
 
    if (k & 1)
      cc[i] = '1';
    else
      cc[i] = '0';
  }
}

float makeFloat(char* f){
  fi fint;
  int i;
  int findExp;
  char binExp[7];
  int postPeriod;
  int count = 0;

  while(f[count] != '\0'){
     if(f[count] == '.'){
      findExp = count - 2;
    }
    count++;
  }
  postPeriod = count;
  char ppFloat[postPeriod];
  
  count = 2;
  int ppCount = 0;
  while(f[count] != '\0'){
    if(f[count] == '1' || f[count] == '0'){
      ppFloat[ppCount] = f[count];
      ppCount++;
    }
    count++;
  }
  //sign bit
  unsigned int temp = 1;
  if(f[0] == '-'){
    fint.i = temp;
  }
  //127 bias and exponent
  findExp += 127;
  decToBin(binExp, findExp);
  for(i = 7; i >= 0; i--){
    if((binExp)[i] == '1'){
      fint.i <<= 1;
      fint.i = fint.i | temp;
    }else{
      fint.i <<=1;
    }
  }
  //mantissa
  for(i = 0; i < postPeriod; i++){
    if((ppFloat)[i] == '1'){
      fint.i <<= 1;
      fint.i = fint.i | temp;
    }else{ //if((ppFloat)[i] == '.'){
      //fint.i >>= 1;
      // }else{
      fint.i <<=1;
    }
  }
  
  for(i = 0; i < 23 - postPeriod; i++){
       fint.i <<= 1;
  }
  return fint.f;
}

int main(){
  printf("test displayFloat \n");
  float f1 = -5.8125;
  displayFloat(f1);

  printf("test makeFloat \n");
  float f2 = makeFloat("-101.1101");
  displayFloat(f2);
}
