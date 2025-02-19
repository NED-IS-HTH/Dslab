//apply quicksort to an array while pivot is (a.at begining, b.at end)
#include <stdio.h>

int partition_exchange(int A[],int l,int h)
{
    int si = l, ei = h;
    int pivot = A[l];  //pivot = A[h] for last element
    while (si <= ei)
    {
        while (A[si] <= pivot)
            si++;
        while (A[ei] > pivot)
            ei--;
        if (si < ei)
        {
            int temp = A[si];
            A[si] = A[ei];
            A[ei] = temp;
        }
    }
    int temp = A[ei];
    A[ei] = A[l];   //A[ei] = A[h] for last element
    A[l] = temp;
    return ei;
}



void quick_sort(int A[],int l,int h)
{
    if (l < h)
    {
        int pos = partition_exchange(A,l,h);
        quick_sort(A,l,pos);
        quick_sort(A,pos+1,h);
    }
}

int main()
{
    int A[] = {5, 2, 9, 1, 7, 6, 8, 3, 4};
    int n = sizeof(A) / sizeof(A[0]);
    quick_sort(A,0,n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}