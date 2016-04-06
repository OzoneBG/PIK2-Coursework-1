/* Define CRT SECURE NO WARNINGS for Visual Studio compiler to escape secure warnings */
#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int main()
{
	//This is the option the user chooses when asked to, to navigate the program
	char option;

	//Flag for exiting program
	int should_run = 1;

	//Current elements in array
	int elements = 0;

	//This is the array variable to use inside the program
	int* arr = 0;


	while (should_run)
	{
		print_menu();
		
		scanf("%c", &option);

		cons_clear();

		if (option != '\n')
		{
			if (option == '1')
			{
				if (arr != NULL)
					free(arr);

				n_printf("How much elements do you want to input?");
				scanf("%d", &elements);

				init(&arr, elements);
				
				fill_array(arr, elements);

				system("pause");
			}
			else if (option == '2')
			{
				int num;
				printf("Enter number: ");
				scanf("%d", &num);

				find_number(arr, elements, num);

				system("pause");
			}
			else if (option == '3')
			{
				print_array(arr, elements);

				system("pause");
			}
			else if (option == '4')
			{
				float avg = average(arr, elements);

				int val = find_closest(arr, elements, avg);

				printf("Closest element is %d to %.2f\n", val, avg);

				system("pause");
			}
			else if (option == '5')
			{
				free(arr);

				printf("Specify file name: ");
				char file_name[100];
				scanf("%s", file_name);

				printf("How much elements do you want to read: ");
				scanf("%d", &elements);

				init(&arr, elements);

				load_array(arr, elements, file_name);

				n_printf("Array loaded!");

				system("pause");
			}
			else if (option == '6')
			{
				printf("Specify file name: ");
				char file_name[100];
				scanf("%s", file_name);

				save_array(arr, elements, file_name);

				system("pause");
			}
			else if (option == '7')
			{
				free(arr);
				should_run = 0;
			}
		}
	}

	return 0;
}