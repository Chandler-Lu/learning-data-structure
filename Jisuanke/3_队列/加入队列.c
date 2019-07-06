#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue {
	int *data;
	int head, tail, length;
}Queue;

void init(Queue *q, int length) {
	q->data = (int *)malloc(sizeof(int) * length);
	q->length = length;
	q->head = 0;
	q->tail = -1;
}

// 请在下面实现插入函数 push
int push(Queue *q, int element) {
	if (q->tail + 1 >= q->length) {
		return ERROR;
	}
	q->tail++;
	q->data[q->tail] = element;
	return OK;
}


void clear(Queue *q) {
	free(q->data);
	free(q);
}

int main() {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	init(queue, 100);
	for(int i = 1; i <= 10; i++) {
		push(queue, i);
	}
	clear(queue);
	return 0;
}