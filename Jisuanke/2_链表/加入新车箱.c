#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkedList;

// 请在下面实现插入函数 insert
LinkedList insert(LinkedList head, Node *node, int index) {
	if (head == NULL) {
		if (index != 0) {
			return head;
		}
		head = node;
		return head;
	}
	if (index == 0) {
		node->next = head;
		head = node;
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
	}
	return head;
}

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
	for (int i = 1; i <= 10; i++){
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = i;
		node->next = NULL;
		linkedlist = insert(linkedlist, node, i - 1);
	}
	clear(linkedlist);
	return 0;
}