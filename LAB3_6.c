//Implement merge sort on integer array and character array
#include <stdio.h>

void merge_sort(int size, int a[], int start_ele, int end_ele);
void merge(int size, int a[], int start_ele, int mid, int end_ele);
void merge_sort_char(char size, char a[], int start_ele, int end_ele);
void merge_char(char size, char a[], int start_ele, int mid, int end_ele);

int main()
{
    int arr1[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    char arr2[] = "Fire in the hole";
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int i;
    int j;
    int k;
    int temp;
    char temp2;
    int arr3[size1];
    char arr4[size2];
    //Implement merge sort on integer array
    merge_sort(size1, arr1, 0, size1 - 1);
    printf("Sorted integer array: ");
    for(i = 0; i < size1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    //Implement merge sort on character array
    merge_sort_char(size2, arr2, 0, size2 - 1);
    printf("Sorted character array: ");
    for(j = 0; j < size2; j++)
    {
        printf("%c", arr2[j]);
    }
    printf("\n");
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

void merge_sort_char(char size, char a[], int start_ele, int end_ele)
{
    if(start_ele < end_ele)
    {
        int mid = (start_ele + end_ele) / 2;
        merge_sort_char(size, a, start_ele, mid);
        merge_sort_char(size, a, mid + 1, end_ele);
        merge_char(size, a, start_ele, mid, end_ele);
    }
}

void merge_char(char size, char a[], int start_ele, int mid, int end_ele)
{
    int left_size = mid - start_ele + 1;
    int right_size = end_ele - mid;

    char left[left_size], right[right_size];

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