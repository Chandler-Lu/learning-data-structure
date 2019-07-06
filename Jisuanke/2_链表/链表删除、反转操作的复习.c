#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
	if (head == NULL) {
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
		return head;
	}
	printf("failed\n");
	return head;
}

void output(LinkedList head) {
	if (head == NULL) {
		return;
	}
	Node *current_node = head;
	while (current_node != NULL) {
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	printf("\n");
}

LinkedList delete_node(LinkedList head, int index) {
	if (head == NULL) {
		printf("failed\n");
		return head;
	}
	Node *current_node = head;
	int count = 0;
	if (index == 0) {
		head = head->next;
		free(current_node);
		printf("success\n");
		return head;
	}
	while (count < index - 1 && current_node->next != NULL) {
		current_node = current_node->next;
		count++;
	}
	if (current_node->next == NULL) {
		printf("failed\n");
		return head;
	}
	if (count == index - 1 && current_node->next != NULL) {
		Node *delete_node = current_node->next;
		current_node->next = delete_node->next;
		free(delete_node);
	}
	printf("success\n");
	return head;
}

LinkedList reverse(LinkedList head) {
	if (head == NULL) {
		return head;
	}
	Node *current_node, *node_next;
	current_node = head->next;
	head->next = NULL;
	while (current_node != NULL) {
		node_next = current_node->next;
		current_node->next = head;
		head = current_node;
		current_node = node_next;
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
	
	int m;
	scanf("%d", &m);
	
	int t_arr[100], a_arr[100], b_arr[100];
	for (int i = 0; i < m; i++) {
		scanf("%d", &t_arr[i]);
		if (t_arr[i] == 1) {
			scanf("%d %d", &a_arr[i], &b_arr[i]);
		}
		if (t_arr[i] == 3) {
			scanf("%d", &a_arr[i]);
		}
	}
	
	for (int i = 0; i < m; i++) {
		if (t_arr[i] == 1) {
			Node *node = (Node *)malloc(sizeof(Node));
			node->data = b_arr[i];
			node->next = NULL;
			linkedlist = insert(linkedlist, node, a_arr[i]);
		}
		if (t_arr[i] == 2) {
			output(linkedlist);
		}
		if (t_arr[i] == 3) {
			linkedlist = delete_node(linkedlist, a_arr[i]);
		}
		if (t_arr[i] == 4) {
			linkedlist = reverse(linkedlist);
		}
	}
	clear(linkedlist);
	return 0;
}