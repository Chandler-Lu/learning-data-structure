/*
 * @Description: KMP algorithm - Get Next Array
 * @version: 1.1
 * @Author: Chandler Lu
 * @Date: 2019-07-27 11:28:13
 * @LastEditTime: 2019-08-06 11:47:23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetNext(char *, int *);

int main(int argc, char *argv[]) {
  char p[] = "abababca";
  int *next = (int *)malloc(sizeof(int) * strlen(p));
  GetNext(p, next);
  printf("Next[%lu]: ", strlen(p));
  for (int i = 0; i < strlen(p); i++) {
    printf("%d", next[i]);
    if (i != strlen(p) - 1) {
      printf(" ");
    }
  }
  free(next);
  return 0;
}

void GetNext(char *p, int *next) {
  next[0] = -1;
  int i = 0, j = -1;
  while (i < strlen(p)) {
    if (j == -1 || p[i] == p[j]) {
      ++i;
      ++j;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}