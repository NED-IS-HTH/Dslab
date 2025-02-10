//quick Sorted
#include <stdio.h>

int count = 0;

int Partition_exchange(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void printArray(int arr[], int n);

int main()
{
    int arr[16] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8, 13, 11, 15, 12, 10, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    printf("After sorting: ");
    printArray(arr, n);
    
    count =0;
    quicksort(arr, 0, n - 1);
    printf("After applying quicksort on sorted array no. of basic operations = %d\n", count);
    
    return 0;
}

int Partition_exchange(int arr[], int low, int high)
{
    int si = low, ei = high;
    int pivot = arr[low];
    
    while(si < ei)
    {
        while(arr[si] <= pivot)
        {
            si++;
        }
        while(arr[ei] > pivot)
        {
            ei--;
        }
        if(si < ei)
        {
            int temp = arr[si];
            arr[si] = arr[ei];
            arr[ei] = temp;
        }
        
    }
    int temp = arr[ei];
    arr[ei] = arr[low];
    arr[low] = temp;

    return ei;
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pos = Partition_exchange(arr, low, high);
        count += 1;
        quicksort(arr, low, pos - 1);
        quicksort(arr, pos + 1, high);
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
