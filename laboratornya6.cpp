#include<stdlib.h>
#include<stdio.h>

int main()
{
    int n, kol = 0; 
    printf(" n:\n");
    scanf_s("%d", &n);

    int** matr;  

    matr = (int**)malloc(n * sizeof(int*)); 
    for (int i = 0; i < n; i++)
        matr[i] = (int*)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++)   
        for (int j = 0; j < n; j++)
            scanf_s("%d", &matr[i][j]);

    int k, l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (matr[i][j] == 1) 
            {
                kol++;
                k = i; 
                while (matr[k][j] == 1) 
                {
                    l = j;
                    while (matr[k][l] == 1) 
                    {
                        matr[k][l] = 0;
                        l++;
                        if (l == n)break;  
                    }
                    k++;
                    if (k == n)break; 
                }
            }

        }
    printf("%d", kol);
    return 0;
}