#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

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

void expand(Vector *vector) {
	int *old_data = vector->data;
	vector->size = vector->size * 2;
	vector->data = (int *)malloc(sizeof(int) * vector->size);
	for(int i = 0; i < vector->length; ++i){
		vector->data[i] = old_data[i];
	}
	free(old_data);
}

int insert(Vector *vector, int loc, int value) {
	//loc不在范围
	if(loc < 0 || loc > vector->length){
		return ERROR;
	}
	
	//超出
	if(vector->length >= vector->size){
		expand(vector);
		printf("expand\n");
	}
	
	//后移
	for(int i = vector->length; i > loc; --i){
		vector->data[i] = vector->data[i - 1];
	}
	
	//插入
	vector->data[loc] = value;
	vector->length ++;
	return OK;
}


void clear(Vector *vector) {
	free(vector->data);
	free(vector);
}

int main() {
	Vector *a = (Vector *)malloc(sizeof(Vector));
	init(a, 5);
	
	int num;
	int loc[101];
	int value[101];
	
	scanf("%d", &num);
	for(int i = 0; i < num; i++){
		scanf("%d %d", &loc[i], &value[i]);
	}
	
	for(int i = 0; i < num; i++){
		if(insert(a, loc[i], value[i])){
			printf("success\n");
		} else {
			printf("failed\n");
		}
	}	
	
	return 0;
}