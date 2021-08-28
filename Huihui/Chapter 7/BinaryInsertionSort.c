/*
 * @Description: 折半插入排序（Binary Insertion Sort）
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-10-05 20:40:42
 * @LastEditTime: 2019-10-06 00:58:17
 */

#include <stdio.h>
#include <stdlib.h>

void BinaryInsertionSort(int *, int);

int main(int argc, char *argv[]) {
  int raw[] = {-15, 2, 6, 3, 8, 25, 108, 35, 919, 503};
  int length = sizeof(raw) / sizeof(int);
  int *work = (int *)malloc(length);
  work[0] = 0;
  for (int i = 1; i <= length; i++) {
    work[i] = raw[i - 1];
  }
  BinaryInsertionSort(work, length);
  for (int i = 1; i <= length; i++) {
    printf("%d", work[i]);
    if (i != length) {
      printf(" ");
    }
  }
  free(work);
}

void BinaryInsertionSort(int work[], int length) {
  int i, j, low, high, mid;
  for (i = 2; i <= length; i++) {
    low = 1;
    high = i - 1;
    work[0] = work[i];
    while (low <= high) {
      mid = (low + high) / 2;
      if (work[mid] < work[0]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    for (j = i - 1; j >= high + 1; j--) {
      work[j + 1] = work[j];
    }
    work[j + 1] = work[0];
  }
}