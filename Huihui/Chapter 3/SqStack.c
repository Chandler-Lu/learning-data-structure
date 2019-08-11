/*
 * @Description: Sq-Stack
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-08-08 22:21:15
 * @LastEditTime: 2019-08-12 00:03:21
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define TRUE 1
#define MAXSIZE 20

typedef struct Stack {
  int top;
  int data[MAXSIZE];
} SqStack;

int push(SqStack *, int);
int pop(SqStack *);

int main(int argc, char *argv[]) {
  SqStack *s = (SqStack *)malloc(sizeof(SqStack));
  s->top = -1;
  for (int i = 0; i < MAXSIZE; i++) {
    push(s, i);
  }
  for (int i = 0; i < MAXSIZE; i++) {
    pop(s);
    if (i != MAXSIZE - 1) {
      printf(" ");
    }
  }
  free(s);
}

int push(SqStack *s, int e) {
  if (s->top == MAXSIZE - 1) {
    return ERROR;
  }
  s->top++;
  s->data[s->top] = e;
  return TRUE;
}

int pop(SqStack *s) {
  if (s->top == -1) {
    return ERROR;
  }
  printf("%d", s->data[s->top--]);
  return TRUE;
}