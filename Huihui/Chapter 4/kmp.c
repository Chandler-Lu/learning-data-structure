/*
 * @Description: Knuth–Morris–Pratt algorithm
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-10-06 22:59:43
 * @LastEditTime: 2019-10-07 00:49:16
 */

#include <stdio.h>
#include <string.h>

#define SIZE 20

int kmp(char *, char *);

int main(int argc, char *argv[]) {
  char S[SIZE] = "ABABBAAABABABBA"; // 原串
  char T[SIZE] = "ABABABB";         // 模式串
  int loc = kmp(S, T);
  if (loc == -1) {
    printf("无匹配");
  } else {
    printf("匹配成功，起始位置：%d", loc);
  }
  return 0;
}

void getNext(int *next, char *T) {
  int k = 0;
  int j = -1;
  next[0] = -1;
  while (k < strlen(T)) {
    if (j == -1 || T[j] == T[k]) {
      next[k + 1] = j + 1;
      k++;
      j++;
    } else {
      j = next[j];
    }
  }
}

int kmp(char *S, char *T) {
  int i = 0;
  int j = 0;
  int next[SIZE] = {0};
  getNext(next, T);

  // 注意：strlen 返回无符号整型，当 j = -1 时将导致异常，故强制转换
  while (i < strlen(S) && j < (int)strlen(T)) {
    if (j == -1 || S[i] == T[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }

  if (j == (int)strlen(T)) {
    return i - j;
  } else {
    return -1;
  }
}