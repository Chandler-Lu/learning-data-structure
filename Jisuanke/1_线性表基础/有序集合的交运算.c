#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct Vector {
	int size;
	int length;
	int *data;
} Vector;

void init(Vector *vector, int size) {
	vector->size = size;
	vector->length = 0;
	vector->data = (int *)malloc(sizeof(int) * size);
}

int insert(Vector *vector, int loc, int value) {
	vector->data[loc] = value;
	vector->length++;
	return OK;
}

void print(Vector *vector) {
	for(int i = 0; i < vector->length; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", vector->data[i]);
	}
	printf("\n");
}

int UnionVector(Vector *a, Vector *b, Vector *c) {
	int acount = 0;
	int bcount = 0;
	int ccount = 0;
	while ((acount <= a->size) && (bcount <= b->size)) {
		if (a->data[acount] == b->data[bcount]) {
			insert(c, ccount, a->data[acount]);
			acount++;
			bcount++;
			ccount++;
		}
		if (a->data[acount] < b->data[bcount]) {
			acount++;
		}
		if (a->data[acount] > b->data[bcount]) {
			bcount++;
		}
	}
	return ccount;
}


void clear(Vector *vector) {
	free(vector->data);
	free(vector);
}

int main(int argc, char *argv[]) {
	int n1;
	scanf("%d", &n1);
	int A[n1];
	for (int i = 0; i < n1; i++) {
		scanf("%d", &A[i]);
	}
	int n2;
	scanf("%d", &n2);
	int B[n2];
	for (int i = 0; i < n2; i++) {
		scanf("%d", &B[i]);
	}
	
	Vector *a = (Vector *)malloc(sizeof(Vector));
	Vector *b = (Vector *)malloc(sizeof(Vector));
	Vector *c = (Vector *)malloc(sizeof(Vector));
	
	init(a, n1);
	init(b, n2);
	init(c, (n1>n2 ? n1:n2));
	
	for (int i = 0; i < n1; i++) {
		insert(a, i, A[i]);
	}
	
	for (int i = 0; i < n2; i++) {
		insert(b, i, B[i]);
	}
	
	printf("%d\n", UnionVector(a, b, c));
	print(c);
	
	
	clear(a);
	clear(b);
	clear(c);
	
	return 0;
}