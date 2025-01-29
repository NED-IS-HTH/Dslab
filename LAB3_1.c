#include <stdio.h>              

void arr2d_create(int n, int a[][n]);
void moving_average(int size, int a[][7],int i,int j,int B[][5]);
void Print_arr(int n, int a[][n]);

int main()
{
    int arr[7][7];
    arr2d_create(7, arr);
    Print_arr(7, arr);
    int B[5][5];
    for (int i = 0; i < 7 - 3 + 1; i++)
    {
        for (int j = 0; j < 7 - 3 + 1; j++)
        {
            moving_average(3, arr, i, j, B)
        }
    }
    Print_arr(5,B);
    return 0;
}

void arr2d_create(int n, int a[][n])
{
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d ",&a[i][j]);
        }
        scanf("\n");
    }
}

void moving_average(int size, int a[][7],int i,int j,int B[][5])
{
    int sum = 0;
    for(int k = 0; k < size; k++)
    {
        for(int l = 0; l < size; l++)
        {
            sum += a[i+k][j+l];
        }
    }
    B[i][j] = sum/9;
}

/*void copy_part_arr(int size, int a[][7], int start_ele,int b[][size]) 
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            b[i][j] = a[start_ele + i][start_ele + j];
        }
    }
}

int moving_average(int size, int c[][size])
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            sum += c[i][j];
        }
    }
    return sum/(size*size);
}*/

void Print_arr(int n, int a[][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
