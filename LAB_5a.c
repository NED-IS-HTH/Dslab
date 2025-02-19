//write a function for an optimised bubble sort which stops execution if array is sorted
#include <stdio.h>

void bub_sort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int swap = 0;
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = 1;
            }
        }
        if(swap == 0)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bub_sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}