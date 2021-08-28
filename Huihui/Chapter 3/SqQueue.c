/*
 * @Description: Sq-Queue（存在假溢出）
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-08-11 23:44:40
 * @LastEditTime: 2019-08-12 00:03:00
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define TRUE 1
#define MAXSIZE 10

typedef struct SqQueue {
  int data[MAXSIZE];
  int front;
  int rear;
} SqQueue;

int EnQueue(SqQueue *, int);
int DeQueue(SqQueue *, int *);

int main(int argc, char *argv[]) {
  SqQueue *q = (SqQueue *)malloc(sizeof(SqQueue));
  q->front = 0;
  q->rear = 0;
  int num = 0;
  for (int i = 0; i < MAXSIZE; i++) {
    EnQueue(q, i * 2);
  }
  for (int i = 0; i < MAXSIZE; i++) {
    DeQueue(q, &num);
    printf("%d", num);
    if (i != MAXSIZE - 1) {
      printf(" ");
    }
  }
  free(q);
}

int EnQueue(SqQueue *q, int e) {
  if (q->rear == MAXSIZE) {
    return ERROR;
  }
  q->data[q->rear] = e;
  q->rear++;
  return TRUE;
}

int DeQueue(SqQueue *q, int *num) {
  if (q->front == MAXSIZE) {
    return ERROR;
  }
  *num = q->data[q->front];
  q->front++;
  return TRUE;
}