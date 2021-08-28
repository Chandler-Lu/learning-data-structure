/*
 * @Description: 快速排序（Quick Sort）
 * @version: 1.0
 * @Author: Chandler Lu
 * @Date: 2019-11-20 17:03:36
 * @LastEditTime: 2019-11-20 19:43:14
 */

#include <stdio.h>
#include <stdlib.h>

void Quicksort(int *, int, int);

int main(int argc, char *argv[]) {
  int raw[] = {-15, 2, 6, 3, 8, 25, 108, 35, 919, 503};
  int length = sizeof(raw) / sizeof(int);
  int *work = (int *)malloc(length);
  for (int i = 0; i < length; i++) {
    work[i] = raw[i];
  }
  Quicksort(work, 0, length - 1);
  for (int i = 0; i < length; i++) {
    printf("%d", work[i]);
    if (i != length - 1) {
      printf(" ");
    }
  }
  free(work);
}

int Partition(int *work, int low, int high) {
  int pivot = work[low];
  while (low < high) {
    while (low < high && work[high] >= pivot) {
      --high;
    }
    work[low] = work[high];
    while (low < high && work[low] <= pivot) {
      ++low;
    }
    work[high] = work[low];
  }
  work[low] = pivot;
  return low;
}

void Quicksort(int *work, int low, int high) {
  if (low < high) {
    int pivotpos = Partition(work, low, high);
    Quicksort(work, low, pivotpos - 1);
    Quicksort(work, pivotpos + 1, high);
  }
}