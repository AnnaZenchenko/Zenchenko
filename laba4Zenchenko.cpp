#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
	if (n == 0) 
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else 
	{
		return n * fact(n - 1);
	}
}

int main()
{

	int *a, n, m = 0;
	printf("enter the size of the array: "); //"вводится размер массива"
	scanf_s("%d", &n);
	a = (int*)malloc(n * sizeof(int)); //создание динамического массива через указатель а
	for (int i = 0; i < n; i++) //цикл от 0,пока i меньше n, цикл будет продолжаться 
	{
		printf("a[%d]: ", i);
		scanf_s("%d", (a + i)); //ввод чисел с клавиатуры
	}
	for (int i = 0; i < n; i++) 
	{
		if (*(a + i) < 0) 
		{
			*(a + i) = 0;
			m++;
		}
	}
	for (int i = 0; i < n; i++) 
	{
		printf("%3d", *(a + i));
	}
	printf("\n factorial: %d", fact(m)); //вывод факториала
	return 0;
}
