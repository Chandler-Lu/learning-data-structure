/*
 * @Description: 直接插入排序（Insertion Sort）
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-09-23 18:04:14
 * @LastEditTime: 2019-09-23 18:07:29
 */

#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *, int);

int main(int argc, char *argv[]) {
  int raw[] = {-15, 2, 6, 3, 8, 25, 108, 35, 919, 503};
  int length = sizeof(raw) / sizeof(int);
  int *work = (int *)malloc(length + 1);
  work[0] = 0;
  for (int i = 1; i <= length; i++) {
    work[i] = raw[i - 1];
  }
  InsertSort(work, length);
  for (int i = 1; i <= length; i++) {
    printf("%d", work[i]);
    if (i != length) {
      printf(" ");
    }
  }
  free(work);
}

void InsertSort(int *work, int length) {
  int i, j;
  for (i = 2; i <= length; i++) {
    if (work[i] < work[i - 1]) {
      work[0] = work[i];
      for (j = i - 1; work[0] < work[j]; j--) {
        work[j + 1] = work[j];
      }
      work[j + 1] = work[0];
    }
  }
}