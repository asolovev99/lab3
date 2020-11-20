#define _CRT_SECURE_NO_WARNINGS
#define lenght_of_array 8

#include<time.h>
#include<stdlib.h>

void swap(double* numbers, int first_index, int second_index);

int main()
{
	double numbers[lenght_of_array];
	int index_working_with = -1;
	int was_changed = 1;

	srand(time(0));
	for (int i = 0; i < lenght_of_array; i++)
	{
		numbers[i] = (double)rand() + (double)rand() / 10e5;
	}

	for (int j = 0; j < lenght_of_array; j++)
	{
		for (int i = lenght_of_array / 2 - 1 - j / 2; i > -1; i--)
		{
			index_working_with = i;
			was_changed = 1;

			while (was_changed)
			{
				was_changed = 0;

				if (2 * index_working_with + 2 <= lenght_of_array - 1 - j)
				{
					if (numbers[2 * index_working_with + 1] > numbers[2 * index_working_with + 2])
					{
						if (numbers[index_working_with] < numbers[2 * index_working_with + 1])
						{
							swap(numbers, index_working_with, 2 * index_working_with + 1);
							was_changed = 1;
							index_working_with = 2 * index_working_with + 1;
						}
					}
					else if (numbers[index_working_with] < numbers[2 * index_working_with + 2])
					{
						swap(numbers, index_working_with, 2 * index_working_with + 2);
						was_changed = 1;
						index_working_with = 2 * index_working_with + 2;
					}

				}
				else if (2 * index_working_with + 1 <= lenght_of_array - 1 - j)
				{
					if (numbers[index_working_with] < numbers[2 * index_working_with + 1])
					{
						swap(numbers, index_working_with, 2 * index_working_with + 1);
						was_changed = 1;
						index_working_with = 2 * index_working_with + 1;
					}
				}
			}
		}

		swap(numbers, 0, lenght_of_array - 1 - j);
	}

	return 0;
}

void swap(double* numbers, int first_index, int second_index) 
{
	double tmp = numbers[first_index];

	numbers[first_index] = numbers[second_index];
	numbers[second_index] = tmp;
}