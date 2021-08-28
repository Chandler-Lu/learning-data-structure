/*
 * @Description: 2017-武汉科技大学(856)-算法设计 01 [合并两递减链表，使结果递增]
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-03 23:03:33
 * @LastEditTime: 2019-09-04 20:29:46
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct LNode {
  int data;
  struct LNode *next;
} LNode, *LinkList;

LinkList InitList();
void ListStructure(LinkList &, LinkList &);
int Merge(LinkList &, LinkList &, LinkList &);
void ListTraverse(LinkList &);
void Destroy(LinkList &, LinkList &, LinkList &);

int main(int argc, char *argv[]) {
  LNode *La = InitList();
  LNode *Lb = InitList();
  LNode *Lc;
  ListStructure(La, Lb);
  printf("Lc 总数: %d\nLc 遍历: ", Merge(La, Lb, Lc));
  ListTraverse(Lc);
}

LinkList InitList() {
  LNode *head = (LinkList)malloc(sizeof(LNode));
  if (!head) {
    exit(OVERFLOW);
  }
  head->next = NULL;
  return head;
}

void ListStructure(LinkList &La, LinkList &Lb) {
  LinkList pa = La;
  LinkList pb = Lb;
  int La_arr[] = {19, 17, 15, 10, 8, 6, 4, 2, 1};
  int Lb_arr[] = {20, 17, 16, 15, 8, 5, 3, 2, 1, 0};
  for (int i = 0; i < (sizeof(La_arr) / sizeof(La_arr[0])); i++) {
    LNode *node = (LinkList)malloc(sizeof(LNode));
    if (!node) {
      exit(OVERFLOW);
    }
    node->data = La_arr[i];
    node->next = NULL;
    pa->next = node;
    pa = node;
  }
  for (int i = 0; i < (sizeof(Lb_arr) / sizeof(Lb_arr[0])); i++) {
    LNode *node = (LinkList)malloc(sizeof(LNode));
    if (!node) {
      exit(OVERFLOW);
    }
    node->data = Lb_arr[i];
    node->next = NULL;
    pb->next = node;
    pb = node;
  }
}

/**
 * @description: Merge La and Lb
 * @param {LinkList} La
 * @param {LinkList} Lb
 * @param {LinkList} Lc
 * @return: The number of elements of Lc
 */
int Merge(LinkList &La, LinkList &Lb, LinkList &Lc) {
  LinkList pa = La->next;
  LinkList pb = Lb->next;
  Lc = (LinkList)malloc(sizeof(LNode));
  Lc->next = NULL;
  int num = 0;
  while (pa && pb) {
    num++;
    LNode *node = (LinkList)malloc(sizeof(LNode));
    if (pa->data > pb->data) {
      node->data = pa->data;
      pa = pa->next;
    } else if (pa->data < pb->data) {
      node->data = pb->data;
      pb = pb->next;
    } else if (pa->data == pb->data) {
      node->data = pa->data;
      pa = pa->next;
      pb = pb->next;
    }
    node->next = Lc->next;
    Lc->next = node;
  }
  while (pa) {
    num++;
    LNode *node = (LinkList)malloc(sizeof(LNode));
    node->data = pa->data;
    node->next = Lc->next;
    Lc->next = node;
    pa = pa->next;
  }
  while (pb) {
    num++;
    LNode *node = (LinkList)malloc(sizeof(LNode));
    node->data = pb->data;
    node->next = Lc->next;
    Lc->next = node;
    pb = pb->next;
  }
  return num;
}

void ListTraverse(LinkList &L) {
  LinkList p = L->next;
  while (p) {
    printf("%d", p->data);
    if (p->next != NULL) {
      printf(" ");
    }
    p = p->next;
  }
}

void Destroy(LinkList &La, LinkList &Lb, LinkList &Lc) {
  while (La) {
    LNode *p = La;
    La = La->next;
    free(p);
  }
  while (Lb) {
    LNode *p = Lb;
    Lb = Lb->next;
    free(p);
  }
  while (Lc) {
    LNode *p = Lc;
    Lc = Lc->next;
    free(p);
  }
}