#include <stdio.h>
#include <math.h>

// Structures
struct point {
	int x;
	int y;
};

// Prototypes
void swap(int* a, int* b);

void test(int* c) {
	printf("in test: %d\n", c[0]);
}

void bar (struct point p) {
	p.x = 2;
	printf("in bar: %d\n", p.x);
	
}

int main() {



	int a[5];
	a[0] = 1;
	*(a+1) = 0;
	
	printf("%d\n", *(a+1));
	
	int* b;
	b = a;
	printf("%d\n", b[0]);
	
	test(a);
	
	struct point p1;
	p1.x = 3;
	p1.y = 4;
	

	bar(p1);
	printf("%d\n", p1.x);
	
/*
  printf("Hello World!\n");

  int x = 5;
  int y = 8;
  
  int* p;  // p is a pointer to an int
  p = &x;  // assign p the value of the address of x
  
  printf("%d\n", *p);
  
  //*p = 9;
 
  float z = 2.9;

  z = ceil(z);

  swap(&x, &y);

  printf("in main: %d %d %f\n", x, y, z);
  */
  return 0;
}


void swap(int* a, int* b) {
  //  printf("%d\n", a);
  int tmp = *b;
  *b = *a;
  *a = tmp;

  printf("in swap: %d %d\n", *a, *b);
}
