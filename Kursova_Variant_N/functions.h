#pragma once
/* Define CRT SECURE NO WARNINGS for Visual Studio compiler to escape secure warnings */
#define _CRT_SECURE_NO_WARNINGS
#define _MAX_ARRAY_SIZE 100;
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* Initialize array for use manually with memory allocation */
void init(int** p, int size);

/* Print the menu to the console */
void print_menu();

/* Clear the console of letters */
void cons_clear();

/* Custom print function to append new line */
void n_printf(char* str);

/* Fill array with user specified number of elements */
void fill_array(int* p, int size);

/* Print array to the screen */
void print_array(int* p, int size);

/* Flush array. Initialize each array with integer. (Fill with 0) */
void flush_array(int* p, int size);

/* Find average sum in array */
float average(int* p, int size);

/* Find closest element to average sum in array */
int find_closest(int*p, int size, float avg);

/* Save array to file */
void save_array(int* p, int size, char* fn);

/* Load array from file */
void load_array(char* fn, int* size, int** p);

/* Find number in array specified by the user */
void find_number(int* p, int size, int target);

/* Print error that the array is empty */
void err_empty();
