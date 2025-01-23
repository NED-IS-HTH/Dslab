#include <stdio.h>              

void arr2d_create(int n, int a[][]);
void copy_part_arr(int size, int a[][], int start_ele ,int b[][]) ;
int moving_average(int size, int c[][]);

int main()
{
    int arr[7][7];
    arr_create(7, arr);
    
    int B[5][5];
    for (int i = 0; i < 7 - 3 + 1; i++)
    {
        for (int j = 0; j < 7 - 3 + 1; j++)
        {
            int C[3][3];
            copy_part_arr(3, arr, i, C);
            int avg = moving_average(3, C);
            B[i][j] = avg;
        }
    }
    
    return 0;
}

void arr2d_create(int n, int a[][])
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

void copy_part_arr(int size, int a[][], int start_ele ,int b[][]) 
{
    int k = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i >= start_ele && j >= start_ele)
            {
                b[k] = a[i][j];
                k++;
            }
        }
    }
}

int moving_average(int size, int c[][])
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
}