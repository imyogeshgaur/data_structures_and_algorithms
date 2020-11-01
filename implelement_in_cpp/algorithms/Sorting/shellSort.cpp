#include <iostream>
using namespace std;

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
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int n, *a, i;
    cout << "Enter the Size of the Array : " << endl;
    cin >> n;
    a = new int[n];
    cout << "Enter the Array : ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "Initial array: " << endl;
    printArray(a, n);

    shellSort(a, n);
    cout << "Sorted array: \n";
    printArray(a, n);
}