#include <stdio.h>
#include <stdlib.h>

// 请在下面实现二叉树结点的结构体 Node
typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
} Node;

// 请在下面实现初始化函数 init
Node* init(int data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

// 请在下面实现函数 clear
void clear(Node *node) {
	if (node->lchild != NULL) {
		clear(node->lchild);
	}
	if (node->rchild != NULL) {
		clear(node->rchild);
	}
	free(node);
}

int main() {
	return 0;
}