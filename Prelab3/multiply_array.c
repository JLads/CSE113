/**
 * @file multiply_array.c
 * @brief multiplies the values at certain points of a previously input aray
 * @details an array is preset. entering a range will multiply the 
 * @details values in the array at the specified points.
 *
 * @author Joseph Ladino
 * @date fall 2016
 * @bug none
 * */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define S 20
int array_multiply_range(int start, int stop, int a[], size_t size);
int input();

int main()
{
	int a[] = {6, 3, 5, 2, 3, 2, 4};
	int start;
	int stop;
	char s[S];
	size_t size = 7;
	printf("please enter starting point and end point. (start_stop)\n");
	fgets(s , S , stdin);
	sscanf(s, "%d %d", &start, &stop);
	printf("the integers you entered were %d and %d.\n", start, stop);
	array_multiply_range(start, stop, a, size);
	printf("%d\n", array_multiply_range(start, stop, a, size));

	return 0;
}
 
/**
 * sets start and stop to low to high order and then determines product
 * @param start, the position of the first value in the array
 * @param stop the position of the last value in the array to be used
 * @param a, the array of values to multiply from
 * @param size, the size of array a
 * @return product of specified values in array
 * */
int array_multiply_range(int start, int stop, int a[], size_t size )
{
	int tmp;
	if (start > stop){
		tmp = start;
		start = stop;
		stop = tmp;
	}

	if (start < 0){
		start = 0;
	} else if (start > size) {
		start = size - 1;
	}
	if (stop > size) {
		stop = size - 1;
	} else if (stop < 0) {
		stop = 0;
	}
	int product = 1;
	for(; start <= stop ; start ++) {
		product = a[start] * product;	
	}
	return product;

}
