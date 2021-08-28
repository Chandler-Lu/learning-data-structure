#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue{
	int *data;
	int head, tail, length;
} Queue;

void init(Queue *q, int length) {
	q->data = (int *)malloc(sizeof(int) * length);
	q->length = length;
	q->head = 0;
	q->tail = -1;
}

int push(Queue *q, int element) {
	if (q->tail + 1 >= q->length) {
		return ERROR;
	}
	q->tail++;
	q->data[q->tail] = element;
	return OK;
}
void output(Queue *q) {
	for (int i = q->head; i <= q->tail; i++) {
		if (i == q->head) {
			printf("%d", q->data[i]);
		} else {
			printf(" %d", q->data[i]);
		}
		
	}
	printf("\n");
}
int front(Queue *q) {
	return q->data[q->head];
}
void pop(Queue *q) {
	q->head++;
}

int empty(Queue *q) {
	return q->head > q->tail;
}

void clear(Queue *q) {
	free(q->data);
	free(q);
}

int main() {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	init(queue, 100);
	
	//定义
	int m;
	int element[100];
	int n;
	
	//输入
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &element[i]);
	}
	scanf("%d", &n);
	
	//插入
	for (int i = 0; i < m; i++) {
		push(queue, element[i]);
	}
	
	//出队
	for(int i = 0; i < n; i++) {
		if (!empty(queue)) {
			pop(queue);
		}		
	}
	
	//输出头元素
	if (!empty(queue)) {
		printf("%d\n", front(queue));
	}
	
	//遍历输出
	output(queue);
	
	return 0;
}

