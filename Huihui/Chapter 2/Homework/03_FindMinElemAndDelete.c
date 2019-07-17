/*
 * @Description: Huihui-Chapter 2-Homework-03
 * @version: 1.1
 * @Author: Chandler Lu
 * @Date: 2019-07-17 18:29:53
 * @LastEditTime: 2019-07-17 23:50:22
 */
#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW 0

typedef struct LNode {
  int data;
  struct LNode *next;
} LNode, *LinkList;

LinkList CreateLinkList(LinkList, int);
void FindAndDeleteMinNode(LinkList);
void LinkListTraverse(LinkList);
void DestoryLinkList(LinkList);

int main(int argc, char *argv[]) {
  int n;
  printf("Input LNode Number(s): ");
  scanf("%d", &n);
  LNode *linklist = CreateLinkList(linklist, n);
  printf("Before Delete: ");
  LinkListTraverse(linklist);
  FindAndDeleteMinNode(linklist);
  printf("After Delete: ");
  LinkListTraverse(linklist);
  DestoryLinkList(linklist);
  return 0;
}

LinkList InitLinkList(LinkList linklist) {
  linklist = (LNode *)malloc(sizeof(LNode));
  if (linklist != NULL) {
    linklist->next = NULL;
  } else {
    exit(OVERFLOW);
  }
  return linklist;
}

LinkList CreateLinkList(LinkList linklist, int n) {
  int x;
  if (!linklist) {
    linklist = InitLinkList(linklist);
  }
  for (int i = 0; i < n; i++) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
    scanf("%d", &x);
    p->data = x;
    p->next = linklist->next;
    linklist->next = p;
  }
  return linklist;
}

/**
 * @description: Find the Minimum Node
 * @param {LinkList}
 * @return: A Point to the Minimum Node
 */
LinkList FindMinNode(LinkList linklist) {
  int min;
  if (linklist->next == NULL) {
    return NULL;
  }
  LNode *currentNode = linklist->next;
  LNode *minNode_point = currentNode;
  min = currentNode->data;
  while (1) {
    if (currentNode->data < min) {
      min = currentNode->data;
      minNode_point = currentNode;
    }
    if (currentNode->next == NULL) {
      break;
    }
    currentNode = currentNode->next;
  }
  return minNode_point;
}

void FindAndDeleteMinNode(LinkList linklist) {
  LinkList minNode_point = FindMinNode(linklist);
  LNode *currentNode = linklist;
  while (currentNode->next != minNode_point) {
    currentNode = currentNode->next;
  }
  currentNode->next = minNode_point->next;
  free(minNode_point);
}

void LinkListTraverse(LinkList linklist) {
  if (linklist->next == NULL) {
    printf("Empty");
  }
  LNode *currentNode = linklist->next;
  while (currentNode != NULL) {
    if (currentNode->next == NULL) {
      // Space Control
      printf("%d\n", currentNode->data);
      break;
    }
    printf("%d ", currentNode->data);
    currentNode = currentNode->next;
  }
}

void DestoryLinkList(LinkList linklist) {
  LNode *currentNode = linklist;
  while (currentNode != NULL) {
    LNode *deleteLNode = currentNode;
    currentNode = currentNode->next;
    free(deleteLNode);
  }
}