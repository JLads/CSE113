/*
 *@file vector.c
 *@brief executes functions that alter arrays
 *@details 8 different functions for arrays. first multiplies the array by 5. the second adds 3 to each term of the array. The third copies the original array. The fourth adds two arrays together. The fith multiplies two arrays. The sixth multiplies by the inverse array. The seventh inverts the origianl array. The eighth writes a 10 term array of randomly generated numbers.
 *
 *
 *@author Joseph Ladino
 *@date 1, Oct 2016
 *@bug none
 *@todo put the array declarations in a struct
 **/



#include<stdio.h>
#include "vector.h"
/* Place all of your functions here for your Array Problems */

/*
 *prints the array problem answers
 *@param a1, the first array post modifications
 *@param a2, the second array after modification
 *@param copya3, the copy of array 3
 *@param c4, the array resulting from fucntion for problem four
 *@param c5, the array resulting from function for problem 5
 *@param c6, array resulting from function for problem 6
 *@param a7, reversed array
 *@param a8 array of randomly generated numbers
 */
void print_array_all(int a1[], int a2[], int copya3[], int c4[], int c5[], int c6[], int a7[], int a8[], size_t size)
{
	printf("problem 1\n");
	print_array(a1, size);
	printf("\n\nproblem 2\n");
	print_array(a2, size);
	printf("\n\nproblem 3\n");
	print_array(copya3, size);
	printf("\n\nproblem 4\n");
	print_array(c4, size);
	printf("\n\nproblem 5\n");
	print_array(c5, size);
	printf("\n\nproblem 6\n");
	print_array(c6,size);
	printf("\n\nproblem 7\n");
	print_array(a7, size);
	printf("\n\nproblem 8\n");
	print_array(a8, size);
	printf("\n");
}

/*
 *prints arrays
 *@param array the array to be printed
 *@param size, the size of the arrays
 */
void print_array(int array[], size_t size)
{
	int i;
	for (i = 0 ; i < size ; i++) {
		printf("%d, ", array[i]);
	}
}

/*
 *multiplies array by a constant
 *@param a1, the initial array
 *@param size, the size of the array
 */
void multiply_constant(int a1[], size_t size)
{
	int i;
	for (i = 0 ; i < size ; i++) {
		a1[i] = 5 * a1[i];
	}
}

/*
 *adds 3 to each term of array
 *@param a2, the initial array
 *@param size, the size of the array
 */
void add3(int a2[], size_t size)
{
	int i;
	for (i = 0 ; i < size ; i++) {
		a2[i] = a2[i] + 3;
	}
}

/*
 *copies an array
 *@param a3, the initial array
 *@param size the size of the arrays
 *@param copya3 the copy of a3
 */
void copy_array(int a3[], size_t size, int copya3[])
{
	int i;
	for (i = 0 ; i < size ; i++) {
		copya3[i] = a3[i];
	}
}

/*
 *adds arrays
 *@param a4 the initial array
 *@param size the size of the arrays
 *@param b4 the array to be added to a4
 *@param c4 the sum of a4 and b4
 */
void add_array(int a4[], size_t size, int b4[], int c4[])
{
	int i;
	for (i = 0 ; i < size ; i++) {
		c4[i] = a4[i] + b4[i];
	}
}

/*
 *multiplies an array by another array
 *@param a5 initial array
 *@param b5 array to be multiplied by
 *@param c5 product of a and b
 *@param size the size of the arrays
 */
void multiply_array(int a5[], int b5 [], int c5[], size_t size)
{
	int i;
	for (i = 0 ; i < size ; i++) {
		c5[i] = a5[i] * b5[i];
	}
}

/*
 *multiplies an array by its reverse
 *@param a6 the initial array
 *@param b6 the array to be multiplied by
 *@param c6 the product of a and b
 *@param size, the size of the arrays
 */
void multiply_reverse(int a6[], int b6[], int c6[], size_t size)
{
	int i; 
	for (i = 0 ; i < size ; i++) {
		c6[i] = b6[size - 1 - i] * a6[i];
	}
}

/*
 *reverses an array with a swap function
 *@param size, size of array
 *@param a7, array to be reversed 
 */
void reverse_array(size_t size, int a7[])
{  
	int start = 0; 
        int tmp;
        while (start < size) {
		tmp = a7[start-1];
		a7[start-1] = a7[size];
		a7[size] = tmp;
		start ++; 
		size --;
	}
}

/*
 *generates array of random numbers
 *@param a8, the empty array to fill
 *@param size, the size of the array
 */
void generate_array_8(int a8[], size_t size)
{
	int i;
	for (i = 0 ; i < size ; i++) {
		a8[i] = get_random_int(50);
	}
}

/*
 *generates random ints
 *@param n, some random int
 *@return random int
 */
int get_random_int(int n)
{
	return random() %n;
}
