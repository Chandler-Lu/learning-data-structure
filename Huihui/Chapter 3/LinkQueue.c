/*
 * @Description: 队列（链式表示）
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-02 19:39:57
 * @LastEditTime: 2019-09-02 21:23:26
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

typedef struct QNode {
  struct QNode *next;
  int data;
} QNode, *Queueptr;
typedef struct {
  Queueptr front;
  Queueptr rear;
} LinkQueue;

void InitQueue(LinkQueue *q);
int QueueEmpty(LinkQueue *q);
void EnQueue(LinkQueue *, int);
int DeQueue(LinkQueue *, int *);
void DestroyQueue(LinkQueue *);

int main(int argc, char *argv[]) {
  LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
  InitQueue(queue);
  int num;
  for (int i = 0; i < MAXSIZE; i++) {
    EnQueue(queue, i);
  }
  for (int i = 0; i < MAXSIZE; i++) {
    DeQueue(queue, &num);
    printf("%d ", num);
  }
  DestroyQueue(queue);
}

void InitQueue(LinkQueue *q) {
  q->front = q->rear = (Queueptr)malloc(sizeof(QNode));
  q->front->next = NULL;
}

int QueueEmpty(LinkQueue *q) {
  if (q->front == q->rear) {
    return TRUE;
  }
  return FALSE;
}

void EnQueue(LinkQueue *q, int data) {
  QNode *node = (Queueptr)malloc(sizeof(QNode));
  if (!node) {
    exit(OVERFLOW);
  }
  node->data = data;
  node->next = NULL;
  q->rear->next = node;
  q->rear = node;
}

int DeQueue(LinkQueue *q, int *data) {
  if (QueueEmpty(q)) {
    return ERROR;
  }
  QNode *deQueueNode = (Queueptr)malloc(sizeof(QNode));
  deQueueNode = q->front->next;
  *data = deQueueNode->data;
  q->front->next = deQueueNode->next;
  if (q->rear == deQueueNode) {
    q->rear = q->front;
  }
  free(deQueueNode);
  return OK;
}

void DestroyQueue(LinkQueue *q) {
  free(q->front);
  free(q);
}