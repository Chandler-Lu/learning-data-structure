/*
 * @Description: 循环队列（顺序表示）
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-02 17:46:08
 * @LastEditTime: 2019-09-02 18:13:12
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct SqQueue {
  int front, rear;
  int data[MAXSIZE];
} SqQueue;

void InitQueue(SqQueue *);
int QueueEmpty(SqQueue *);
int EnQueue(SqQueue *, int);
int DeQueue(SqQueue *, int *);
int DeQueue(SqQueue *, int *);
void GetHead(SqQueue *, int *);

int main(int argc, char *argv[]) {
  SqQueue *q = (SqQueue *)malloc(sizeof(SqQueue));
  InitQueue(q);
  int num;
  GetHead(q, &num);
  for (int i = 0; i < MAXSIZE - 1; i++) {
    EnQueue(q, i);
  }
  printf("队头为：%d\n队列为：", num);
  for (int i = 0; i < MAXSIZE - 1; i++) {
    DeQueue(q, &num);
    printf("%d", num);
    if (i != MAXSIZE - 2) {
      printf(" ");
    }
  }
  free(q);
}

void InitQueue(SqQueue *q) {
  q->front = 0;
  q->rear = 0;
}

int QueueEmpty(SqQueue *q) {
  if (q->rear == q->front) {
    return TRUE;
  }
  return FALSE;
}

int EnQueue(SqQueue *q, int data) {
  if ((q->rear + 1) % MAXSIZE == q->front) {
    return ERROR;
  }
  q->data[q->rear] = data;
  q->rear = (q->rear + 1) % MAXSIZE;
  return OK;
}

int DeQueue(SqQueue *q, int *data) {
  if (q->rear == q->front) {
    return ERROR;
  }
  *data = q->data[q->front];
  q->front = (q->front + 1) % MAXSIZE;
  return OK;
}

void GetHead(SqQueue *q, int *data) { *data = q->data[q->front]; }