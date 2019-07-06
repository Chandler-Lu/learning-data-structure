#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
} Node;

Node* init(int data) {
	Node *node =(Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

// 请在下面实现二叉树的建立函数 build_demo
Node* build_demo() {
	Node *node = init(1);
	node->lchild = init(2);
	node->rchild = init(3);
	node->lchild->lchild = init(4);
	node->lchild->rchild = init(5);
	node->rchild->rchild = init(6);
	return node;
}

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
	Node *root = build_demo();
	clear(root);
	return 0;
}