#include <stdio.h>

void arr_create(int n,int a[])
{
    for (int i = 0; i < n ; i++)
    {
        printf("Enter elements: ");
        scanf("%d ", &a[i]);
    }
}


int main()
{
    int n, arr[100];

    printf("Enter no. of elements in array: ");
    scanf("%d ",&n);

    arr_create(n,arr);

    int av , C_arr[100];
    printf("enter moving average pointer: ");
    scanf("%d ",&av);

    for(int i=0; i < n-av+1; i++)
    {
        for(int j=i; j <= i+av; j++)
        {
            C_arr[i] += arr[j];
        }
        C_arr[i]= C_arr[i]/av;
    }

    
    return 0;
}