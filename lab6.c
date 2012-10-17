#include <stdio.h>
#include <stdlib.h>
typedef unsigned short bitSet;

//prototypes
bitSet makeBitSet(); // Create a new bitset
void displayBitSet(bitSet bs); // Displays the 16 bits of the bitset to the screen
void setBit(bitSet* bs, int index); // Sets bit 'index' of the bitset to 1
void clearBit(bitSet* bs, int index); // Sets bit 'index' of the bitset to 0
int bitValue(bitSet bs, int index); // Returns the value of the bit at 'index'

bitSet makeBitSet(){
  return 0;
}

void displayBitSet(bitSet bs){
  unsigned c, displayMask = 1 << 15; // only compare the last bit
  
  printf( "%7u = ", bs ); //displays value of the bs
  for ( c = 1; c <= 16; c++ ) { 
    // use the mask to test and see if it's set(1) else put 0
    putchar( bs & displayMask ? '1' : '0' );
    bs <<= 1;
    // throw in a space to separate bytes
    if ( c % 8 == 0 ){
      putchar( ' ' );
    }
  }
  
  putchar( '\n' );
}

void setBit(bitSet* bs, int index){
  bitSet temp = 1;
  temp <<= index;
  *bs = *bs | temp;
}

void clearBit(bitSet* bs, int index){
  bitSet temp = makeBitSet();
  setBit(&temp, index);  
  temp = ~temp;
  *bs = *bs & temp;
}

int bitValue(bitSet bs, int index){
  bitSet temp = bs;
  bitSet compare = makeBitSet();
  setBit(&compare, index);
  temp = temp & compare;
  temp >>= index;
  return (int) temp;
}

int main(){
 int x;
 bitSet bs = makeBitSet();

 printf("display test \n");
 displayBitSet(bs);
 printf("set test \n");

 setBit(&bs, 3);
 displayBitSet(bs);
 setBit(&bs, 5);
 displayBitSet(bs);

 printf("value test \n");
 x = bitValue(bs, 3);
 printf("bit value: %d \n", x);
 x = bitValue(bs, 2);
 printf("bit value: %d \n", x);
 
 printf("bit clear test \n");
 clearBit(&bs, 3);
 displayBitSet(bs);
}
