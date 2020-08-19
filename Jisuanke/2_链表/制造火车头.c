#include <stdio.h>
#include <stdlib.h>

// 请在下面实现结构体 Node
typedef struct Node {
	int data;
	struct Node *next;
} Node, *LinkedList;

// 请在下面实现函数 clear
void clear(LinkedList head) {
	Node *current_node  = head;
	while (current_node != NULL){
		Node *delete_node = current_node;
		current_node = current_node->next;
		free(delete_node);
	}
}

int main() {
	LinkedList linkedlist = NULL;
	clear(linkedlist);
	return 0;
}