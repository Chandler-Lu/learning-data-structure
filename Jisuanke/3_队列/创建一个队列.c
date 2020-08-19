#include <stdio.h>
#include <stdlib.h>

// 请在下面实现队列 Queue
typedef struct Queue {
	int *data;
	int head, tail, length;
}Queue;

// 请在下面实现初始化函数 init
void init(Queue *q, int length) {
	q->data = (int *)malloc(sizeof(int) * length);
	q->length = length;
	q->head = 0;
	q->tail = -1;
}

// 请在下面实现 clear 函数
void clear(Queue *q) {
	free(q->data);
	free(q);
}

int main() {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	init(queue, 120);
	clear(queue);
	return 0;
}