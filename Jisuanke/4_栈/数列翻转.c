#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
	int *elements;
	int max_size, top_index;
} Stack;

void init(Stack *s, int length) {
	s->elements = (int *)malloc(sizeof(int) * length);
	s->max_size = length;
	s->top_index = -1;
}

int push(Stack *s, int element) {
	if (s->top_index >= s->max_size - 1) {
		return ERROR;
	}
	s->top_index++;
	s->elements[s->top_index] = element;
	return OK;
}

int pop(Stack *s) {
	if (s->top_index < 0) {
		return ERROR;
	}
	s->top_index--;
	return OK;
}

int top(Stack *s) {
	return s->elements[s->top_index];
}

// 请在下面实现判断栈是否为空的函数 empty
int empty(Stack *s) {
	if (s->top_index < 0) {
		return 1;
	} else {
		return 0;
	}
}

void clear(Stack *s) {
	free(s->elements);
	free(s);
}

int main() {
	int n, num;
	scanf("%d", &n);
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	init(stack,n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &num);
		push(stack, num);
	}
	while(!empty(stack)) {
		printf("%d ", top(stack));
		pop(stack);
	}
	clear(stack);
	return 0;
}