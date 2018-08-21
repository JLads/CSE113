/**
 * @file init_print.c
 * @brief prints 1-1000 from an array
 * @details sets an array and prints it with a function outside main
 *
 * @author Joseph Ladino
 * @date fall 2016
 * @bug none
 * */



#include <stdio.h>
void print_array(int a[], int SIZE);

int main()
{
	int i;
	int a[1000];
	int SIZE = 1000;
	for (i = 0 ; i < SIZE ; i++) {
		a[i] = i + 1;
	}
	print_array(a, SIZE);
	return 0;
}

/**
 * prints array a
 * @param a, the array of values from 1 to 1000
 * @param SIZE, the size of array a
 * @return 0
 **/
void print_array(int a[], int SIZE)
{
	int i;
	for (i = 0 ; i < SIZE ; i++)
		printf("%d\n", a[i]);
}
