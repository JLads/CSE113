/*
 * @file array.c
 * 
 * @author joseph Ladino
 *
 * @date Fall 2016
 *  
 * Assignment: Lab 3 
 *
 * @brief Functions for fundamental array algorithms. 
 *
 * @details The functions implemented include basic counting, 
 * summing, searching, and basic statistical methods (average,
 * median, the max, the min). Sorting is implemented via
 * bubble sort, a not very efficient sort, and insertion sort.
 *  
 * @bugs none
 *
 * @todo implement floating point versions of the functions
 */


#include "array.h"
#include <stdio.h>


/* prints out the elements of an array, one element per line
 * @param a[] the array to print
 * @param size the size or length of the array
 */
void print_array(int a[], size_t size)
{
	int i;
	
	for(i = 0; i < size; i++)
		printf("a[%d] = %d\n", i, a[i]);
}


/*
 * finds max of array
 * @param max, max of array
 * @param size, size of array
 * @param a[] the array
 * @return max of array
 * */
int find_max(size_t size, int a[])
{
	int i;
	int max;
	max = a[0];
	for (i = 0 ; i < size ; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

/*
 * find min of array
 * @param min the min of array
 * @param size_t size the size of array
 * @param a[] the array
 * @return min of array
 * */
int find_min(size_t size, int a[])
{
	int i;
	int min;
	min = a[0];
	for (i = 0 ; i < size ; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

/*
 * find avg of min and max
 * @param max, max of array
 * @param min, min of array
 * @param mid, mid of array
 * @return mid
 * */
int find_mid(int min, int max)
{
	int mid;
	mid = (min + max) / 2;
	return mid;
}

/*
 * counts terms less than or greater than 7
 * @param a, the array
 * @param size, the size of the array
 * @param type the greater than or less then to be performed
 * @remark, type is declared in the declaration of function in main.
 * @return lesst7
 * */
int get_countlesst7(int a[], size_t size, int type)
{
	int i;
	int lesst7 = 0;
	switch (type) {
		case LT: 
			for (i = 0 ; i < size ; i++) {
				if (a[i] < 7) {
					lesst7 = lesst7 + 1;
				}
			}
		break;
		case GT:
			for (i = 0 ; i < size ; i++) {
				if (a[i] > 7) {
					lesst7 = lesst7 + 1;
				}
			}
		break;
		case GE:
			for (i = 0 ; i < size ; i++) {
				if (a[i] >= 7) {
					lesst7 = lesst7 + 1;
				}
			}
		break;
		case LE: 
			for (i = 0 ; i < size ; i++) {
				if (a[i] <= 7) {
					lesst7 = lesst7 + 1;
				}
			}
		break;
		case EQ:
			for (i = 0 ; i < size ; i++) {
				if (a[i] == 0) { 
					lesst7 = lesst7 + 1;
				}
			}
		break;

	}
	return lesst7;
}

/*
 * counts terms greater than midpoint or less than mid.
 * @param a, the array
 * @param size, the size of the array
 * @param type. GT or LT for greater than or less than
 * @remark, above param declared in function declartaion in main
 * @param mid, the avg of min and max
 * @return count
 * */

int get_count(int a[], size_t size, int type, int mid)
{
	int i;
	int count = 0;
	switch (type) {
		case GT: 
			for (i = 0 ; i < size ; i++) {
				if (a[i] > mid) {
					count = count + 1;
				}
			}
		break;
		
		case LT:
			for(i = 0 ; i < size ; i++) {
				if (a[i] < mid) {
					count = count + 1;
				}
			}
		break;
		case GE:
			for (i = 0 ; i < size ; i++) {
				if (a[i] >= mid) {
					count = count + 1;
				}
			}
		break;
		case LE:
			for (i = 0 ; i < size ; i++) {
				if (a[i] <= mid) {
					count = count + 1;
				}
			}
		case EQ:
			for (i = 0 ; i < size ; i++) {
				if (a[i] == mid) {
					count = count + 1;
				}
			}
		break;
		default: 
			printf("ok then.\n");
			return 0;
	}
	return count;
}

/*
 * find if a value is in the array via linear logic
 * @param search, value to find
 * @param a, the array to test
 * @param size, size of array
 * @param search_stat, yes or no to be returned
 * @return search_stat
 * */
int linear_search(int search, int a[], size_t size, int search_stat)
{
	int i = 0;
	while (i <= size && search != a[i]) {
		i = i + 1;
	}
	if (i <= size) {
		search_stat = 1;
	} else {
		search_stat = 0;
	}
	return search_stat;
}

/*
 * finds sum of all values in array
 * @param a, the array
 * @param size, size of array
 * @param sum, the sum of all values in array
 * @return sum
 * */
double find_sum(int a[], size_t size)
{
	int i;
	double sum = 0;
	for (i = 0 ; i < size ; i++) {
		sum = sum + a[i];
	}
	return sum;
}

/*
 * find avg of array
 * @param size, size of array
 * @param sum sum of all values in array
 * @return avg
 * */
double find_avg(size_t size, double sum)
{
	
	double avg = (sum / (double)size);
	return avg;

}

/*
 * sorts array into numerical order via a forward - backward analysis
 * @param a the array to be sorted
 * @param size , size of array
 * @return void
 * */
void bubble_sort(int a[], size_t size)
{
	int i;
	int j;
	int tmp;
	for (i = 0 ; i < size ; i++) {
		for (j = size - 1 ; j >= i + 1 ; j--) {
			if (a[j-1] > a[j]) {
				tmp = a[j-1];
				a[j-1] = a [j];
				a[j] = tmp;
			}
		}
	}
}


/*
 * uses insertion method to sort array
 * @param a the array
 * @param size, the size of the array
 * @return void
 * */
void insertion_sort(int a[], size_t size)
{ 
	int k;
	int x;
	int j;
	for (k = 0 ; k < size ; k++) {
		x = a[k];
		j = k - 1;
		while (j > 0 && a[j] > x) {
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j + 1] = x;
	}
}

/*
 * reorder array from greatest to least
 * @param a, the array
 * @param size, the size of the array
 * @return void
 * */
void swaptime(int a[], size_t size)
{
	int start = 0;
	int tmp;
	while (start < size) {
		tmp = a[start-1];
		a[start-1] = a[size];
		a[size] = tmp;
		start ++;
		size --;
	}
}


/*
 * finds median of array
 * @param a, the array
 * @param size, size of array
 * @return median
 * */
float find_median(int a[], size_t size)
{
	int median;
	if (size % 2 == 0 ) {
		median = (a[size/2] + a[(size/2) -1]) / 2.0;
	}
	else {
		median = a[size/2];
	}
	return median;
}

/*
 * finds the number of terms that are even
 * @param a, the array to test
 * @param size, size of array
 * @param ctevens, the number of even terms
 * @return ctevens
 * */
int find_evens(int a[], size_t size, int ctevens)
{
	int i;
	ctevens = 0;
	for (i = 0 ; i < size ; i++) {
		if (a[i] % 2 == 0) {
			ctevens = ctevens + 1;
		}
	}
	return ctevens;
}

/*
 * find the number of odd terms in the array
 * @param a, the array to be tested
 * @param size, the size of the array
 * @param ctodds the number of odds in array
 * @return ctodds
 * */
int find_odds(int a[], size_t size, int ctodds)
{
	int i;
	ctodds = 0;
	for (i = 0 ; i < size ; i++) {
		if (a[i] % 2 != 0) {
			ctodds = ctodds + 1;
		}
	}
	return ctodds;
}

int div_by(int a[], size_t size)
{
	int i;
	int ctdivby;
	ctdivby = 0;
	for (i = 0 ; i < size ; i++) {
		if ((a[i] % 6) == 0) {
			ctdivby = ctdivby + 1;
		}
	}
	return ctdivby;
}
