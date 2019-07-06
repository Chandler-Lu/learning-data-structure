#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int * elem;
	int length;
	int listsize;
}Vector;

void InitList(Vector *vector, int size) {
	vector->elem = (int *)malloc(sizeof(int) * size);
	vector->length = 0;
	vector->listsize = size;
}

int ListInsert(Vector *vector, int locate, int value) {
	if (locate < 0 || locate > vector->length) {
		return ERROR;
	}
	for (int i = vector->length; i > locate; i--) {
		vector->elem[i] = vector->elem[i - 1];
	}
	vector->elem[locate] = value;
	vector->length++;
	return OK;
}

void ListPrint(Vector *vector){
	for (int i = 0; i < vector->length; i++){
		if (i > 0) {
			printf(" ");
		}
		printf("%d", vector->elem[i]);
	}
	printf("\n");
}

void LeftMove(Vector *vector, Vector *Newvector, int k, int n) {
	int k_temp = k;
	for (int i = 0; i < (n - k); i++) {
		ListInsert(Newvector, i, vector->elem[k_temp]);
		k_temp++;
	}
	int m = 0;
	for (int i = (n - k); i < vector->length; i++) {
		ListInsert(Newvector, i, vector->elem[m]);
		m++;
	}
}

void ListClear(Vector *vector){
	free(vector->elem);
	free(vector);
}

int main(int argc, char *argv[]) {
	Vector * vector = (Vector *)malloc(sizeof(Vector));
	Vector * Newvector = (Vector *)malloc(sizeof(Vector));
	
	int n;
	int k;
	int a;
	scanf("%d %d", &n, &k);
	
	InitList(vector, n);
	InitList(Newvector, n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		ListInsert(vector, i, a);
	}
	
	
	LeftMove(vector, Newvector, k, n);
	ListPrint(Newvector);
	
	ListClear(vector);
	ListClear(Newvector);
}