//sort odd loc with selection and even loc with insertion sort
#include <stdio.h>

void swap(int a, int b);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int arr[15] = {12, 11, 13, 5, 6, 7, 1, 2, 3, 4, 8, 9, 10, 14, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    int evenArr[n/2];
    for (int i = 0; i < n ; i+=2)
    {
        evenArr[i/2] = arr[i];
    }

    int oddArr[n/2];
    for (int i = 1; i < n ; i+=2)
    {
        oddArr[i/2] = arr[i];
    }

    selectionSort(oddArr, n/2);
    insertionSort(evenArr, n/2);

    int sortedArr[n];
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        if ((i % 2 != 0) || (i == 1))
        {
            sortedArr[i] = oddArr[i/2];
        }
        else 
        {
            sortedArr[i] = evenArr[i];
        }
        
        
        printf("%d ", sortedArr[i]);
    }

    return 0;
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n)
{
    for(int i=0; i < n; i++)
    {
        int min = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

