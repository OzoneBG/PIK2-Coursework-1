#include "functions.h"

void init(int** p, int size)
{
	int max_size = _MAX_ARRAY_SIZE;

	if (size <= max_size)
	{
		*p = calloc(size, sizeof(int));
	}
	else
	{
		printf("Failed to allocate array because size is more than 100. Try again.\n");
	}
}	

void print_menu()
{
	printf("1. Fill array with numbers\n");
	printf("2. Find number in array\n");
	printf("3. Print array\n");
	printf("4. Find element closest to the average sum\n");
	printf("5. Load array from file\n");
	printf("6. Save array to file\n");
	printf("7. Exit\n");
}

void cons_clear()
{
	system("cls");
}

void n_printf(char* str)
{
	printf(str);
	printf("\n");
}

void fill_array(int* p, int size)
{
	int max_size = _MAX_ARRAY_SIZE;

	if (size <= max_size)
	{
		int n;
		for (int i = 0; i < size; i++)
		{
			printf("[%d]: ", i+1);
			scanf("%d", &n);

			*(p + i) = n;
		}
	}
}

void print_array(int* p, int size)
{
	int max_size = _MAX_ARRAY_SIZE;

	if (size <= max_size && size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			printf("[%d]: %d\n", i+1, *(p + i));
		}
	}
	else
	{
		printf("Array is empty!\n");
	}
}

void flush_array(int* p, int size)
{
	for (int i = 0; i < size; i++)
		*(p + i) = 0;
}

float average(int* p, int size)
{
	int sum = 0, count = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(p + i);
		count++;
	}

	float avg = (float)sum / count;

	return avg;
}

int find_closest(int* p, int size, float avg)
{
	int closest = *(p + 0);

	for (int i = 0; i < size; i++)
	{
		if (abs(*(p + i) - avg) < abs(closest - avg))
			closest = *(p + i);
	}

	return closest;
}

void save_array(int* p, int size, char* fn)
{
	FILE* fp;

	fp = fopen(fn, "w");

	if (fp != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(fp, "%d\n", *(p + i));
		}

		fclose(fp);
	}	
}

void load_array(int* p, int size, char* fn)
{
	FILE* fp;

	fp = fopen(fn, "r");

	int max_size = _MAX_ARRAY_SIZE;

	if (size <= max_size)
	{
		if (fp != NULL)
		{
			for (int i = 0; i < size; i++)
			{
				fscanf(fp, "%d", (p + i));
			}

			fclose(fp);
		}
	}
	else
		printf("Size cannot be more than 100!\n");	
}

void find_number(int* p, int size, int target)
{
	int found = 0;
	int i = 0;


	for (i; i < size; i++)
	{
		if (*(p + i) == target)
		{
			found = 1;
			break;
		}
	}

	if (found)
		printf("Number %d exist in position %d\n", target, i);
	else
		printf("Number not found!\n");
}