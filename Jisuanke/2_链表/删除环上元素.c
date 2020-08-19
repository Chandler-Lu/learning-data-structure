#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
	if (head == NULL) {
		if (index != 0) {
			return head;
		}
		head = node;
		head->next = head;
		return head;
	}
	if (index == 0) {
		node->next = head->next;
		head->next = node;
		return head;
	}
	Node *current_node = head->next;
	int count = 0;
	while (current_node != head && count < index - 1) {
		current_node = current_node->next;
		count++;
	}
	if (count == index - 1) {
		node->next = current_node->next;
		current_node->next = node;
	}
	if (node == head->next) {
		head = node;
	}
	return head;
}

// 请在下面实现输出函数 output_josephus
void output_josephus(LinkedList head, int m) {
	Node *current_node = head;
	head = NULL;
	while (current_node->next != current_node) {
		for (int i = 1; i < m; i++) {
			current_node = current_node->next;
		}
		printf("%d ", current_node->next->data);
		Node *delete_node = current_node->next;
		current_node->next = current_node->next->next;
		free(delete_node);
	}
	printf("%d\n", current_node->data);
	free(current_node);
}

int main() {
	LinkedList linkedlist = NULL;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = i;
		node->next = NULL;
		linkedlist = insert(linkedlist, node, i - 1);
	}
	output_josephus(linkedlist, m);
	return 0;
}