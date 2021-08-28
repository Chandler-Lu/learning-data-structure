/*
 * @Description: 七夕快乐
 * @version: 9.99
 * @Author: Chandler Lu
 * @Date: 2018-03-09 10:59:39
 * @LastEditTime: 2019-08-07 23:48:36
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
} Node;

Node* init(char data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

Node* build() {
	Node *node = init('9');
	node->lchild = init('0');
	node->rchild = init('a');
	node->rchild->lchild = init('M');
	node->rchild->rchild = init('p');
	node->rchild->rchild->lchild = init('g');
	node->rchild->rchild->rchild = init('e');
	node->rchild->rchild->rchild->lchild = init('i');
	node->lchild->lchild = init('2');
	node->lchild->lchild->lchild = init('a');
	node->lchild->lchild->lchild->lchild = init('H');
	node->lchild->lchild->lchild->rchild = init('p');
	node->lchild->lchild->lchild->rchild->lchild = init('p');
	node->lchild->lchild->lchild->rchild->rchild = init('y');
	node->lchild->rchild = init('1');
	return node;
}

void inorder(Node *node) {
	if (node->lchild != NULL) {
		inorder(node->lchild);
	}
	if (node->data == '2') {
		printf(" ");
	}
	if (node->data == 'M') {
		printf(" ");
	}
	printf("%c", node->data);
	if (node->rchild != NULL) {
		inorder(node->rchild);
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
	Node *root = build();
	inorder(root);
	printf("\n");
	clear(root);
	return 0;
}