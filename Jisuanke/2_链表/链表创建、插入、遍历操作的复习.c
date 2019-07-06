#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkedList;
// Node:节点类型
// LinkedList:节点指针类型（头指针类型，或链表）

LinkedList insert(LinkedList head, Node *node, int index) {
	if (head == NULL){
		if (index != 0) {
			printf("failed\n");
			return head;
		}
		head = node;
		printf("success\n");
		return head;
	}
	if (index == 0) {
		node->next = head;
		head = node;
		printf("success\n");
		return head;
	}
	Node *current_node = head;
	int count = 0;
	while (current_node->next != NULL && count < index - 1) {
		current_node = current_node->next;
		count++;
	}
	if (count == index - 1) {
		node->next = current_node->next;
		current_node->next = node;
		printf("success\n");
	} else {
		printf("failed\n");
	}
	return head;
}

void output(LinkedList head) {
	if (head == NULL) {
		return;
	}
	Node *current_node = head;
	while (current_node != NULL) {
		if (current_node->next == NULL) {
			printf("%d", current_node->data);
			break;
		}
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
}

// 空格控制方式2
//void output(LinkedList head) {
//	if (head == NULL) {
//		return;
//	}
//	Node *current_node = head;
//	while (current_node != NULL) {
//		printf("%d", current_node->data);
//		if (current_node->next != NULL) {
//			printf(" ");
//		}
//		current_node = current_node->next;
//	}
//}

void clear(LinkedList head) {
	Node *current_node = head;
	while (current_node != NULL) {
		Node *delete_node = current_node;
		current_node = current_node->next;
		free(delete_node);
	}
}

int main() {
	LinkedList linkedlist = NULL;
	
	int n;
	int p[101];
	int q[101];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i], &q[i]);
	}
	
	for (int i = 0; i < n; i++){
		Node *node = (Node *)malloc(sizeof(node));
		node->data = q[i];
		node->next = NULL;
		linkedlist = insert(linkedlist, node, p[i]);
	}
	
	output(linkedlist);
	free(linkedlist);
	return 0;
}