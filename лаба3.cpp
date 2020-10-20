#include <stdio.h>
#include <locale.h>
#include <iostream>
#define n 4
int main()
{
	int a = 0, b = 0, i, ms[n];
	printf("fill the array\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &ms[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (ms[i] % 5 == 0 && ms[i] % 7 != 0)
		{
			a += 1;
			b = b + ms[i];
		}
	}
	printf("number of numbers needed %d\n", a);
	printf("the sum of numbers needed %d\n", b);
	return(0);
}