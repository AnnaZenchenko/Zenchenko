#include<stdio.h>
#include<conio.h>
int main()
{
	int mr[5][5];

	printf("\n enter array elements\n"); //"введите элементы массива"
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf_s(" %d", &mr[i][j]);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("\n");
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", mr[i][j]);
		}
	}

	return 0;
}