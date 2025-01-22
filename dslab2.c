#include <stdio.h>

void arr_create(int n,int a[]);
void wo_sort_freq(int n,int a[]);
void with_sort_freq(int size, int a[]);
void Bub_sort(int size, int a[]);
void Insertion_sort(int size, int a[]);
void remove_duplication(int size, int a[]);
void Kth_largest(int size, int a[], int k);

int main()
{
    int n, arr[100];

    printf("Enter no. of elements in array: ");
    scanf("%d ",&n);

    arr_create(n,arr);

    int av , C_arr[100];
    printf("enter moving average pointer: ");
    scanf("%d ",&av);

    printf("og_array | moving average\n");
    for(int i=0; i < n-av+1; i++)
    {
        for(int j=i; j <= i+av; j++)
        {
            C_arr[i] += arr[j];
        }
        C_arr[i]= C_arr[i]/av;
        printf(" %3d | %3d\n",arr[i],C_arr[i]);
    }
    
    return 0;
}

void arr_create(int n,int a[])
{
    for (int i = 0; i < n ; i++)
    {
        printf("Enter elements: ");
        scanf("%d ", &a[i]);
    }
}

void wo_sort_freq(int n,int a[])
{
    int freq[100];                  //creating frequency table(Assuming values are between 0 and 99)
    for (int i = 0; i < n ; i++)    
    {
        freq[a[i]]++;
    }

    printf("Elements | Frequency\n");
    printf("_________|___________\n");
    for (int i = 0; i < n ; i++)
    {
        printf(" %5d | %5d\n",a[i],freq[a[i]]);
    }

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

void with_sort_freq(int size, int a[])
{
    int freq[100] ={0};     //Assuming values are between 0 and 99

    for (int i = 0; i < size ; i++)
    {
        freq[a[i]]++;
    }

    printf("Element | Frequency\n");
    printf("_________|___________\n");
    for (int i = 0; i < 100; i++) 
    {
        if (freq[i] > 0)
        {
            printf("%5d | %9d\n", i, freq[i]);
        }
    }
}

void Insertion_sort(int size, int a[])
{
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        int key = a[i];
        int j = i - 1;

        while(j>=0 && key<a[j])
        {
            a[j+1] = a[j];
            j--;
            count ++;
        }

        a[j+1] = key;
    }

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\nNumber of comparisons: %d\n", count);
}

void remove_duplication(int size, int a[])
{
    Insertion_sort(size, a);
    for (int i = 0; i < size; i++)
    {
        if(i > 0 && a[i] == a[i-1])
        {
            for (int j = i; j < size - 1; j++)
            {
                a[j] = a[j + 1];
            }
        }
    }   
}

void Kth_largest(int size, int a[], int k)
{
    int b [size];
    for (int i = 0; i < k; i++)
    {
        if (a[i]>a[i+1])
        {
            b[i] = a[i+1];
            b[i+1] = a[i];
        }
    }

    printf("The kth largest element is: %d\n", b[k-1]);
}
