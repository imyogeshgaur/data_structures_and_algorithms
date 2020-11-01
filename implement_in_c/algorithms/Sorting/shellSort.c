#include <stdio.h>
#include <stdlib.h>

void shellSort(int array[], int n)
{

    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int *a, size, i;
    printf("Enter the number of elements in array\n");
    scanf("%d", &size);

    a = (int *)malloc(sizeof(size));

    printf("Enter %d numbers\n", size);

    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);

    printf("Initial array: \n");
    printArray(a, size);

    shellSort(a, size);

    printf("Sorted array: \n");
    printArray(a, size);
    return 0;
}