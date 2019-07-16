#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int *, int);
void swap(int *, int *);

int main(int argc, char *argv[]) {
  // Test 1
  int arr_1[] = {1, 2, 0};

  // Test 2
  int arr_2[] = {3, 4, -1, 1};

  // Test 3
  int arr_3[] = {9, 4, -1, 1};

  // CalculateArrayElementNumber
  int elemNum_1 = sizeof(arr_1) / sizeof(int);
  int elemNum_2 = sizeof(arr_2) / sizeof(int);
  int elemNum_3 = sizeof(arr_3) / sizeof(int);

  // Call function & Output
  printf("Test 1 - FirstMissingPositive: %d\n",
         firstMissingPositive(arr_1, elemNum_1));
  printf("Test 2 - FirstMissingPositive: %d\n",
         firstMissingPositive(arr_2, elemNum_2));
  printf("Test 3 - FirstMissingPositive: %d\n",
         firstMissingPositive(arr_3, elemNum_3));

  return 0;
}

int firstMissingPositive(int *arr, int elemNum) {
  for (int i = 0; i < elemNum; i++) {
    while (arr[i] > 0 && arr[i] <= elemNum && arr[i] != arr[arr[i] - 1]) {
      swap(&arr[i], &arr[arr[i] - 1]);
    }
  }
  for (int i = 0; i < elemNum; i++) {
    if (arr[i] != i + 1) {
      return (i + 1);
    }
  }
  return elemNum + 1;
}

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}