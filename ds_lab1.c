#include <stdio.h>

void Crt_arr(int n, int a[]);
void Trav_arr(int n, int a[]);
void Del_el(int n, int a[], int index);
void Insert(int n, int a[], int index);
void reverse(int n, int a[]);
void left_shift(int n, int a[]);
void right_shift(int n, int a[]);
void Bub_sort(int n, int a[]);
void sort_odd_pos(int n, int a[]);
void sort_even_pos(int n, int a[]);

int main()
{
    int n, arr[100];

    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    
    Crt_arr(n, arr);
    Trav_arr(n, arr);
    
    int del_indx, ins_indx;
    printf ("Enter the index to delete: ");
    scanf("%d",&del_indx);
    Del_el(n, arr, del_indx);

    printf("Enter the index to insert: ");
    scanf("%d",&ins_indx);
    Insert(n, arr,ins_indx);
    
    reverse(n, arr);
    left_shift(n, arr);
    right_shift(n, arr);
    Bub_sort(n, arr);
    sort_odd_pos(n, arr);
    sort_even_pos(n, arr);

    return 0;
}

void Crt_arr(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d ", &a[i]);
    }
}

void Trav_arr(int n, int a[])
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void Del_el(int size, int a[], int index)
{
    for(int i= index; i < size; i++)
    {
        a[i]=a[i+1];
    }
    size--;
}

void Insert(int size, int a[], int index)
{
    int new_element;
    printf("Enter new element: ");
    scanf("%d", &new_element);
    
    for(int i = size; i > index; i--)
    {
        a[i] = a[i - 1];
    }
    a[index] = new_element;
    size++;
}

void reverse(int size, int a[])
{
    int temp;
    for(int i = 0; i < size / 2; i++)
    {
        temp = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = temp;
    }
}

void left_shift(int size, int a[])
{
    int temp =a[0];
    for(int i = 0; i < size - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[size - 1] = temp;
}

void right_shift(int size, int a[])
{
    for(int i = size-1; i >= 0; i--)
    {
        a[i+1]=a[i];
    }
    a[0]=0;
}

void Bub_sort(int size, int a[])
{
    int i, j, temp;
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j+1]=temp;
            }
        }
    }
}

void sort_odd_pos(int size, int a[])        
{
    int i, j, temp;
    for(i = 0; i < size/2 - 1; i++)
    {
        for(j = 1; j < size/2 - i - 1; j+=2)
        {
            if(a[j] > a[j + 2])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j+1]=temp;
            }
        }
    }
}

void sort_even_pos(int size, int a[])
{
    int i, j, temp;
    for(i = 0; i < size/2 - 1; i++)
    {
        for(j = 0; j < size/2 - i - 1; j+=2)
        {
            if(a[j] > a[j + 2])
            {
                temp = a[j];
                a[j] = a[j + 2];
                a[j+2]=temp;
            }
        }
    }
}
