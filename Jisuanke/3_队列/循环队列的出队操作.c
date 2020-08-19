#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue {
	int *data;
	int head, tail, length, count;
}Queue;

void init(Queue *q, int length) {
	q->data = (int *)malloc(sizeof(int) * length);
	q->length = length;
	q->head = 0;
	q->tail = -1;
	q->count = 0;
}

int push(Queue *q, int element) {
	if (q->count >= q->length) {
		return ERROR;
	}
	q->tail = (q->tail + 1) % q->length;
	q->data[q->tail] = element;
	q->count++;
	return OK;
}

void output(Queue *q) {
	int i = q->head;
	do {
		printf("%d ", q->data[i]);
		i = (i + 1) % q->length;
	} while(i != (q->tail + 1) % q->length);
	printf("\n");
}

int front(Queue *q) {
	return q->data[q->head];
}

void pop(Queue *q) {
	q->head = (q->head + 1) % q->length;
	q->count--;
}

int empty(Queue *q) {
	return q->count == 0;
}

void clear(Queue *q) {
	free(q->data);
	free(q);
}

int main() {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	init(q, 100);
	for (int i = 1; i <= 10; i++) {
		push(q, i);
	}
	output(q);
	if (!empty(q)) {
		printf("%d\n", front(q));
		pop(q);        
	}
	output(q);
	clear(q);
	return 0;
}