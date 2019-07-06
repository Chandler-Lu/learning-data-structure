#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
	int *elements;
	int max_size, top_index;
} Stack;

void init(Stack *s, int length_input) {
	s->elements = (int *)malloc(sizeof(int) * length_input);
	s->max_size = length_input;
	s->top_index = -1;
}

// 请在下面实现入栈函数 push
int push (Stack *s, int element) {
	if (s->top_index >= s->max_size - 1) {
		return ERROR;
	}
	s->top_index++;
	s->elements[s->top_index] = element;
	return OK;
}

void clear(Stack *s) {
	free(s->elements);
	free(s);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	init(stack, n);
	for(int i = 1; i <= m; i++) {
		int opr;
		scanf("%d", &opr);
		if (opr == 0) {
			int element;
			scanf("%d", &element);
			if (push(stack, element)) {
				printf("push success!\n");
			} else {
				printf("push failed!\n");
			}
		}
	}
	clear(stack);
	return 0;
}