#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
	
	struct A {
		int num_1;
	} A1, *A1_p;
	
	typedef struct B {
		int num_2;
	} B1, *B1_p;
	B1 b1;
	
	// 此处 b1 与 A1 等价
	
	printf("%lu\n", sizeof(A1));
	printf("%lu\n", sizeof(B1));
	printf("%lu\n", sizeof(b1));
}