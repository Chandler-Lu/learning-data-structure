#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size; 	// 当前分配的储存容量
	int length; // 当前长度
	int *data;	// 储存空间基址
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
	for (int i = 0; i < vector->length; i++){
		vector->data[i] = old_data[i];	
	}
	free(old_data);
}

int insert(Vector *vector, int loc, int value) {
	if (loc < 0 || loc > vector->length){
		return ERROR;
	}
	
	if (vector->length >= vector->size){
		expand(vector);
	}
	
	for (int i = vector->length; i > loc; --i) {
		vector->data[i] = vector->data[i - 1];
	}
	
	vector->data[loc] = value;
	vector->length++;
	return OK;
}

int search(Vector *vector, int value) {
	for (int i = 0; i < vector->length; ++i) {
		if (vector->data[i] == value){
			return i;
		}
	}
	return -1;
}

int delete_node(Vector *vector, int index) {
	if(index < 0 || index >= vector->length){
		return ERROR;
	}
	for (int i = index + 1; i < vector->length; ++i) {
		vector->data[i - 1] = vector->data[i];
	}
	vector->length--;
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

void clear(Vector *vector) {
	free(vector->data);
	free(vector);
}

int main() {
	Vector *a = (Vector *)malloc(sizeof(Vector));
	init(a, 20);
	
	//array
	int t_arr[101];
	int a_arr[101];
	int b_arr[101];
	
	//initialize
	for (int i = 0; i <= 101; i++){
		t_arr[i] = 0;
		a_arr[i] = 0;
		b_arr[i] = 0;
	}
	
	//operation
	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++){
		scanf("%d", &t_arr[i]);
		if (t_arr[i] == 1){
			scanf("%d %d", &a_arr[i], &b_arr[i]);
		}
		if (t_arr[i] == 2 || t_arr[i] == 3){
			scanf("%d", &a_arr[i]);
		}
	}
	
	//print
	for (int i = 0; i < m; i++){
		if (t_arr[i] == 1){
			if(insert(a, a_arr[i], b_arr[i])){
				printf("success\n");
			} else {
				printf("failed\n");
			}
		}
		if (t_arr[i] == 2){
			if(delete_node(a, a_arr[i])){
				printf("success\n");
			} else {
				printf("failed\n");
			}
		}
		if (t_arr[i] == 3){
			if(search(a, a_arr[i]) >= 0){
				printf("success\n");
			} else {
				printf("failed\n");
			}
		}
		if (t_arr[i] == 4){
			print(a);
		}
	}
			
	return 0;
}

