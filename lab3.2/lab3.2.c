#define _CRT_SECURE_NO_WARNINGS
#define lenght_of_array 8

#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	double numbers[lenght_of_array];
	int was_changed = 1;

	srand(time(0));
	printf("Before sort:\n"); // Для наглядности вывод элементов массива до сортировки
	for (int i = 0; i < lenght_of_array; i++)
	{
		numbers[i] = (double)rand() + (double)rand() / 10e5;
		printf("%d: %lf\n", i, numbers[i]); // Для наглядности вывод элементов массива до сортировки
	}

	was_changed = 1;
	for (int i = 0; (i <= lenght_of_array - 2) && (was_changed); i++)
	{
		was_changed = 0;
		for (int j = 0; j <= lenght_of_array - 2 - i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				numbers[j] += numbers[j + 1];
				numbers[j + 1] = numbers[j] - numbers[j + 1];
				numbers[j] -= numbers[j + 1];

				was_changed = 1;
			}
		}
	}

	printf("\nAfter sort:\n"); // Для наглядности вывод элементов массива после сортировки
	for (int i = 0; i < lenght_of_array; i++) // Для наглядности вывод элементов массива до сортировки
	{
		printf("%d: %lf\n", i, numbers[i]);
	}

	return 0;
}