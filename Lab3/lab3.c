/*
 * @file lab3.c
 * 
 * @author Scott Chadde (main function base)
 *
 * @author Joseph Ladino (modification to lab specs)
 *
 * @date 1/1/2013
 *  
 * Assignment: Lab 3 
 *
 * @brief a program that tests the functions in array.c
 *
 * @details 
 *  
 * @bugs
 *
 * @todo 
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"
/* 
 * @remark I really do not want to have a 1473 size array in my code thankyou very much. So i linked it as a header file. Just comment the include out for the other test arrays.
 * */
#include "test_array.h" 

void print_summary(size_t size, int max, int min, int mid, int count, int count1, int search_stat, double sum, double avg, int ctevens, int ctodds, int lesst7, float median, int divby);

int main(void)
{
	/*
	 * @remark the following comments are some test arrays.
	 * */
	//int a[] = {9, 7, 5, 3, 2, 77, 8, 12, 4, 5, 11};
	//int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//int a[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	//int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//int a[] = {5, 7, 8, 4, 3, 10, 1, 4, 4, 5};
	int count = 0;
	int count1 = 0;
	int lesst7 = 0;
	int divby;
	int max = 0;
	int min = 0;
	int mid = 0;
	int median;
	int search;
	int search_stat = 0;
	double sum;
	double avg;
	int ctevens = 0;
	int ctodds = 0;
	size_t size = sizeof(a) / sizeof(int);
	max = find_max(size, a);
	min = find_min(size, a);
	mid = find_mid(min, max);
	lesst7 = get_countlesst7(a, size, LT);
	count = get_count(a, size, GT, mid);
	count1 = get_count(a, size, LT, mid);
	search = mid;
	search_stat = linear_search(search, a, size, search_stat);
	sum = find_sum(a, size);
	ctevens = find_evens(a, size, ctevens);
	ctodds = find_odds(a, size, ctodds);
	bubble_sort(a, size);
	insertion_sort(a, size);
	swaptime(a, size);
	divby = div_by(a, size);
	avg = find_avg(size, sum);
	median = find_median(a, size);
	print_array(a, size);
	print_summary(size, max, min, mid, count, count1, search_stat, sum, avg, ctevens, ctodds, lesst7, median, divby);

	return 0;
}

/*
 * print size of array (25 Sept 2016)
 * @param size, the size of the given array
 * @param max, the max of given array
 * @param min, the min of given array
 * @param mid, the average of the min and max
 * @param count, the count of values greater than midpoint
 * @param count1, count of values less than midpoint
 * @param search_stat, the yes or no for a point being in the array
 * @param sum, sum of all values in array
 * @param avg, the average of all values in array
 * @param ctevens, count of even numbers in array
 * @param ctodds, count of odd numbers in array
 * @param lesst7, count of values less than 7 in array
 * @param median, the median of the array
 * @return void
 * */
void print_summary(size_t size, int max, int min, int mid, int count, int count1, int search_stat, double sum, double avg, int ctevens, int ctodds, int lesst7, float median, int divby)
{
	printf("size of the array = %zu\n", size);
	printf("the max of the array = %d\n", max);
	printf("the min of the array = %d\n", min);
	printf("the mid of the array = %d\n", mid);
	printf("the number of components greater than mid is %d\n", count);
	printf("the number of components less than mid is %d\n", count1);
	printf("the number of components less than 7 is %d\n", lesst7);
	if (search_stat == 1) {
		printf("the mid point is found in the data\n");
	} else {
		printf("the mid point is not found in the data\n");
	}
	printf("the sum of all values in array is %f\n", sum);
	printf("the average of the values is %f\n", avg);
	printf("the median of all values is %f\n", median);
	printf("there are %d even numbers in the array.\n", ctevens);
	printf("there are %d odd numbers in the array.\n", ctodds);
	printf("there are %d numbers divisible by 6 in the array.\n", divby);
}

