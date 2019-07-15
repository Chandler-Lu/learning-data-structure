#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW 0

typedef struct SqList {
	int length, size;
	int *data;
} SqList;

void init(SqList *SqList, int size) {
	SqList->data = (int *)malloc(sizeof(int) * size);
	if(!SqList->data) {
		exit(OVERFLOW);
	}
	SqList->length = 0;
	SqList->size = size;
}

void expand(SqList *SqList) {
	SqList->size = SqList->size * 2;
	SqList->data = realloc(SqList->data, sizeof(int) * SqList->size);
	if(!SqList->data) {
		exit(OVERFLOW);
	}
}

int insert(SqList *SqList, int loc, int value) {
	if (loc < 0 || loc > SqList->length) {
		return ERROR;
	}
	if (SqList->length >= SqList->size) {
//		return ERROR;
		expand(SqList);
	}
	for (int i = SqList->length; i > loc; i--) {
		SqList->data[i] = SqList->data[i - 1];
	}
	SqList->data[loc] = value;
	SqList->length++;
	return OK;
}

int delete(SqList *SqList, int loc) {
	if (loc < 0 || loc >= SqList->length) {
		return ERROR;
	}
	for (int i = loc; i < SqList->length; i++) {
		SqList->data[i] = SqList->data[i + 1];
	}
	SqList->length--;
	return OK;
}

void clear(SqList *SqList) {
	free(SqList->data);
	free(SqList);
}

int main() {
	SqList *sqlist = (SqList *)malloc(sizeof(SqList));
	init(sqlist, 2);
	for (int i = 0; i < 5; i++) {
		insert(sqlist, i, i);
	}
	printf("Before delete:\n");
	for (int i = 0; i < 5; i++) {
		printf("%d\n", sqlist->data[i]);
	}
	printf("After delete:\n");
	printf("Delete status: %d\n", delete(sqlist, 5));
	for (int i = 0; i < 5; i++) {
		printf("%d\n", sqlist->data[i]);
	}
	clear(sqlist);
	return 0;
}