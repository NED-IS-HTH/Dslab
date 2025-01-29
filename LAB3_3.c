// Median filter
#include <stdio.h>

void merge_sort(int size, int a[], int start_ele, int end_ele);
void merge(int size, int a[], int start_ele, int mid, int end_ele);
int median(int size, int a[]);
void copy_part_arr(int part_size, int a[][7], int b[], int i, int j);

int main()
{
    int arr[7][7] = 
    {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28},
        {29, 30, 31, 32, 33, 34, 35},
        {36, 37, 38, 39, 40, 41, 42},
        {43, 44, 45, 46, 47, 48, 49}
    };
    int n = sizeof(arr) / sizeof(arr[0][0]);

    int b[n];
    for (int i = 0; i < 7 - 3 + 1; i++)
    {
        for (int j = 0; j < 7 - 3 + 1; j++)
        {
            copy_part_arr(3, arr, b, i, j);
        }
    }
    
    merge_sort(n, b, 0, n - 1);
    printf("Median: %d\n", median(n, b));

    return 0;
}



void merge_sort(int size, int a[], int start_ele, int end_ele)
{
    if(start_ele < end_ele)
    {
        int mid = (start_ele + end_ele) / 2;
        merge_sort(size, a, start_ele, mid);
        merge_sort(size, a, mid + 1, end_ele);
        merge(size, a, start_ele, mid, end_ele);
    }
}

void merge(int size, int a[], int start_ele, int mid, int end_ele)
{
    int left_size = mid - start_ele + 1;
    int right_size = end_ele - mid;

    int left[left_size], right[right_size];

    for(int i = 0; i < left_size; i++)
        left[i] = a[start_ele + i];
    for(int j = 0; j < right_size; j++)
        right[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = start_ele;
    while(i < left_size && j < right_size)
    {
        if(left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < left_size)
    {
        a[k] = left[i];
        i++;
        k++;
    }

    while(j < right_size)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

int median(int size, int a[])
{
    merge_sort(size, a, 0, size - 1);
    if (size % 2 != 0)
    {
        return a[size / 2];
    }
    else
    {
        return (a[(size - 1) / 2] + a[size / 2]) / 2;
    }
}

void copy_part_arr(int part_size, int a[][7], int b[], int i, int j)
{
    int k = 0;
    for(int x = i; x < i + part_size; x++)
    {
        for(int y = j; y < j + part_size; y++)
        {
            b[k] = a[x][y];
            k++;
        }
    }
}