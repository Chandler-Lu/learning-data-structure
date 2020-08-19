/*
 * @Description:
 * @version:
 * @Author: Chandler Lu
 * @Date: 2020-03-10 18:09:39
 * @LastEditTime: 2020-03-10 18:28:58
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

typedef struct SqList {
  int data[MAXSIZE];
  int length;
} SqList;

int main(int argc, char *argv[]) {
  SqList b;
  b.length=5;
  printf("%d", b.length);
}