/*
 * @Description: 2017-武汉科技大学(856)-算法设计 02 [整数 1 到 n 从小到大依次进栈，期间可以出栈，检查一序列是否为正确出栈序列]
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-04 17:25:01
 * @LastEditTime: 2019-09-04 17:30:05
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

typedef struct SqStack {
  int top;
  int *data;
} SqStack;

SqStack *InitStack();
int Judge(int[], int);

int main(int argc, char *argv[]) {
  int a[] = {3, 4, 5, 1, 2};
  printf("%d", Judge(a, 5));
}

SqStack *InitStack() {
  SqStack *s = (SqStack *)malloc(sizeof(SqStack));
  s->top = -1;
  s->data = (int *)malloc(sizeof(int) * MAXSIZE);
  return s;
}

int StackPush(SqStack *s, int data) {
  if (s->top == MAXSIZE - 1) {
    return ERROR;
  }
  s->data[s->top++] = data;
  return OK;
}

int StackPop(SqStack *s) {
  if (s->top == -1) {
    return ERROR;
  }
  s->top--;
  return OK;
}

int GetStackTop(SqStack *s) { return s->data[s->top]; }

int Judge(int a[], int n) {
  int m = 0;                // 当前出栈元素的最大值
  SqStack *s = InitStack(); // 辅助栈
  for (int i = 0; i < n; i++) {
    if (a[i] > m + 1) {
      for (int j = 1; j < m; j++) {
        StackPush(s, j);
        m = a[i];
      }
    } else if (a[i] == m + 1) {
      m = a[i];
    } else if (a[i] < m + 1) {
      if (a[i] == GetStackTop(s)) {
        StackPop(s);
      } else {
        return FALSE;
      }
    }
  }
  return TRUE;
}