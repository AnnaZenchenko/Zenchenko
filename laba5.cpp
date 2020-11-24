#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int *mr, n;
    scanf_s("%d", &n);//вводим кол-во элементов в матрице
    mr = (int*)calloc(n * n, sizeof(int)); //calloc-выделяется блок памяти для массива 
    printf("\n enter array elements\n"); //"введите элементы массива"
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", mr + i);// ввод массива с экрана 
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (j == n - 1) { *(mr + i * n + j) = *(mr + n * (i - 1)); 
            }

            else { *(mr + i * n + j) = *(mr + (i - 1) * n + j + 1); }
        }

    }
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n; j++)
            printf("%d ", *(mr + i*n + j));
    }
    return 0;
}