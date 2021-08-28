#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Node {
	int id, height;
} Node;

typedef struct Stack {
	Node *elements;
	int max_size, top_index;
} Stack;

void init(Stack *s, int length) {
	s->elements = (Node *)malloc(sizeof(Node) * length);
	s->max_size = length;
	s->top_index = -1;
}

int push(Stack *s, Node element) {
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

Node top(Stack *s) {
	return s->elements[s->top_index];
}

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
	int n, ans = 0;
	scanf("%d", &n);
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	init(stack, n);
	Node temp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp.height);
		temp.id = i;
		while (!empty(stack) && top(stack).height <= temp.height) {
			ans = ans + i - top(stack).id - 1;
			pop(stack);
		}
		push(stack, temp);
	}
	while (!empty(stack)) {
		ans = ans + n + 1 - top(stack).id - 1;
		pop(stack);
	}
	printf("%d\n", ans);
	clear(stack);
	return 0;
}