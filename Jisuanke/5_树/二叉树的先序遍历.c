#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
}Node;

Node* init(int data) {
	Node *node =(Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

Node* build_demo() {
	Node *node = init(1);
	node->lchild = init(2);
	node->rchild = init(3);
	node->lchild->lchild = init(4);
	node->lchild->rchild = init(5);
	node->rchild->rchild = init(6);
	return node;
}

// 请在下面实现先序遍历函数 preorder
void preorder(Node *node) {
	printf("%d ", node->data);
	if (node->lchild != NULL) {
		preorder(node->lchild);
	}
	if (node->rchild != NULL) {
		preorder(node->rchild);
	}
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
	preorder(root);
	printf("\n");
	clear(root);
	return 0;
}