//cross correlation
#include <stdio.h>

void arr2d_create(int n, int a[n][n]);
void cross_correlation(int n, int a[n][n], int b[3][3], int c[n-2][n-2]);

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n][n];             //main matrix for the operation to be applied on
    arr2d_create(n, arr);

    int b[3][3];          //3x3 matrix to be multiplied
    int c[n-2][n-2];         // resultant matrix
    
    arr2d_create(3,b);
    cross_correlation(n, arr, b, c);

    return 0;
}

void arr2d_create(int n, int a[n][n])         //function to enter entries
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

void cross_correlation(int n, int a[n][n], int b[3][3], int c[n-2][n-2])
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum = 0;
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    sum += a[i+k][j+l] * b[k][l];
                }
            }
            c[i][j] = sum/9;
        }
    }
}