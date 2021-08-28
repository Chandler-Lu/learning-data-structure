#include <stdio.h>
#include <stdlib.h>

// 请在下面定义结构体栈 Stack
typedef struct Stack {
	int *elements;
	int max_size, top_index;
} Stack;

// 请在下面实现初始化函数 init
void init (Stack *s, int length_input) {
	s->elements = (int *)malloc(sizeof(int) * length_input);
	s->max_size = length_input;
	s->top_index = -1;
}

// 请在下面实现 clear 函数
void clear (Stack *s) {
	free(s->elements);
	free(s);
}

int main() {
	int n;
	scanf("%d", &n);
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	init(stack, n);
	clear(stack);
	return 0;
}