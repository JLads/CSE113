/*
 * @file divisor.c
 * @brief Takes two arrays, divides the values in one by a divisor 
 * @brief and prints the results in second array
 * @details two arrays are initialized. A divisor is set. 
 * @details the values in array a are tested for % divisor = 0.
 * @details if the above statemet is true array b will print a 1.
 * @details if false it will display a 0.
 *
 * @author Joseph ladino
 * @date fall 2016
 * @bug none
 * @todo none
 * */





#include <stdio.h>
#include <stdlib.h>

int div_by(int a[], int b[], size_t size, int divisor);
void print_array(int a[], int b[], int size);



int main()
{
	int divisor = 4;
	int a[] = {13, 44, 85, 23, 72, 99, 100, 108, 222, 1084};
	int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t size = (sizeof a/sizeof a[0]);
	div_by(a, b, size, divisor);
	print_array(a, b, size);
	return 0;
}

/**
 * prints array a and array b
 * @param a, the array a set in main
 * @param b, the array b set in main and written to in div_by
 * @param size, size of array a
 * @return printed arrays one beside the other
 * */
void print_array(int a[], int b[], int size)
{
	int i = 0;
	for (i = 0 ; i < size ; i++) {
		printf("%d %d\n", a[i], b[i]);
	}

} 


/**
 * tests if array a % divisor = 0 and writes results to array b
 * @param a, the array a declared in main
 * @param b, the array b to be written to declared in main
 * @param size, the size of array a 
 * @param divisor, the value to have array a tested against for % = 0
 * @return 0
 * */
int div_by(int a[], int b[], size_t size, int divisor )
{
	int i;

	for (i = 0 ; i < size ; i++) {
		if ((a[i] % divisor) == 0) {
			b[i] = 1;
		}
	}
	return 0;
}
