#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS_
int space(char symbol)
{
	char space_symbols[3] = { '\n', ' ' , '\t' };
	for (int i = 0; i < 3; i++)
	{
		if (symbol == space_symbols[i])
			return 1;
	}
	return 0;
}
int digit(char symbol)
{
	char digits[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	for (int i = 0; i < 10; i++)
		if (symbol == digits[i])
			return 1;
	return 0;
}
int CtoD(char* string)
{
	int n = 0; int i = 0;
	for (int i = 0; space(string[i]); i++) // если вдруг придется вводить строки от руки, а не рандомить, то с помощью этого цикла мы пропускаем все пробелы(функция isspace)
		i++; 
	for (n = 0; digit(string[i]); i++)
		n = 10 * n + (string[i] - '0'); 
		
	return n; 
}
int main()
{
	char** txt = NULL; 
	int* dtxt = NULL; 
	int n, m; // переменная n - количество строк в массиве символов, m - количество символов в каждой строке массива
	printf("enter the number of lines: ");//введите количество строк 
	scanf_s("%d", &n);
	printf("\n enter the number of characters in each line: ");//количество символов в каждой строке 
	scanf_s("%d", &m);
	system("CLS"); 

	txt = (char**)malloc(n * m * sizeof(char)); 
	dtxt = (int*)malloc(n * sizeof(int)); 
	
	

	for (int i = 0; i < n; i++) 
		txt[i] = (char*)calloc(m, sizeof(char));

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			txt[i][j] = ('1' + rand() % ('9' - '1')); 

			
	printf("\n original array:\n");//изначальный массив 
	for (int i = 0; i < n; i++, putchar('\n'))
		for (int j = 0; j < m; j++)
			printf("%c", txt[i][j]);

	putchar('\n'); 

	
	int k = 0; 
	for (int i = 0; i < n; i++) 
	{
		dtxt[k] = CtoD(txt[i]);
		k++; 
	}
	
	printf("\n before sorting:\n");
	for (int i = 0; i < n; i++)
		printf("%d\n", dtxt[i]);

	
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			
			if (dtxt[j] < dtxt[j + 1])
			{
				int tmp = dtxt[j]; 
				dtxt[j] = dtxt[j + 1]; 
				dtxt[j + 1] = tmp; 
			}
		}
	}

	putchar('\n');

	
	printf("\n after sorting:\n"); // выводим массив после сортировки
	for (int i = 0; i < n; i++)
		printf("%d\n", dtxt[i]);

	
	for (int i = 0; i < n; i++)
		free(txt[i]);
	free(txt);
	free(dtxt);
	return 0;
}