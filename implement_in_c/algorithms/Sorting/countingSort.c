#include <stdio.h>
#include<stdlib.h>
void countingSort(int array[], int size) {
  int output[10];

  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  int count[10];

  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() 
{
    int *a,size,i;
    printf("Enter the number of elements in array\n");
    scanf("%d", &size);

    a = (int *)malloc(sizeof(size));

    printf("Enter %d numbers\n", size);

    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
  countingSort(a, size);
  printf("The Sorted Array is  : \n");
  printArray(a,size);
}