#define _CRT_SECURE_NO_WARNINGS
#define lenght_of_array 10

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

double find_median(double* numbers);

int main()
{
	double numbers[lenght_of_array];
	double min = 0;
	double max = 0;
	double average = 0;
	double median = 0;
	int is_random = 1;
	FILE* file = fopen("Input.txt", "r");

	for (int i = 0; i < lenght_of_array; i++)
	{
		fscanf(file, "%lf", &numbers[i]);
	}
	fclose(file);

	min = numbers[0];
	max = numbers[0];
	average = numbers[0];
	for (int i = 1; i < lenght_of_array; i++)
	{
		if (min > numbers[i])
		{
			min = numbers[i];
		}
		if (max < numbers[i])
		{
			max = numbers[i];
		}
		average += numbers[i];
	}
	average = average / lenght_of_array;
	median = find_median(numbers);

	fopen("Output.txt", "w");
	fprintf(file, "%lf\n%lf\n%lf\n%lf", min, max, average, median);
	fclose(file);

	return 0;
}

double find_median(double* numbers)
{
	double copy_numbers[lenght_of_array];
	int index_of_max = -1;

	for (int i = 0; i < lenght_of_array; i++)
	{
		copy_numbers[i] = numbers[i];
	}

	for (int i = 0; i < lenght_of_array - 1; i++)
	{
		index_of_max = i;

		for (int j = i + 1; j < lenght_of_array; j++)
		{
			if (copy_numbers[index_of_max] < copy_numbers[j])
			{
				index_of_max = j;
			}
		}

		if (index_of_max != i)
		{
			copy_numbers[i] += copy_numbers[index_of_max];
			copy_numbers[index_of_max] = copy_numbers[i] - copy_numbers[index_of_max];
			copy_numbers[i] -= copy_numbers[index_of_max];
		}
	}
	if (lenght_of_array % 2 == 1)
	{
		return copy_numbers[lenght_of_array / 2];
	}
	else
	{
		return (copy_numbers[lenght_of_array / 2 - 1] + copy_numbers[lenght_of_array / 2]) / 2;
	}
}