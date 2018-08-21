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
 * @remark I do not wish to have an entire 1474 size array in the code here so I have linked it as a header file.
 * */
#include "test_array.h"

/*
 * structure to use for summary
 * @remark lot better than having 13 params for a function.
 * */
struct summary_t {
	size_t size; 
	int max;
	int min; 
	int mid;
	int count;
	int count1;
	int search;
	int search_stat; 
	double sum; 
	double avg;
	int ctevens; 
	int ctodds; 
	int lesst7;
	float median;
	int divby;
};
void print_summary(struct summary_t summary);
void get_summary(size_t size, int a[]);


int main(void)
{
	//int a[] = {9, 7, 5, 3, 2, 77, 8, 12, 4, 5, 11};
	//int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//int a[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	//int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//int a[] = {5, 7, 8, 4, 3, 10, 1, 4, 4, 5};

	size_t size = sizeof(a) / sizeof(int);
	get_summary (size, a);

	return 0;
}

/*
 * gets the summary struct and passes variables into functions
 * @param size, size of the array defined in main
 * @param a, the array
 * @return void
 * */
void get_summary(size_t size, int a[])
{
	struct summary_t summary;
	summary.size = size;
	summary.max = find_max(size, a);
	summary.min = find_min(summary.size, a);
	summary.mid = find_mid(summary.min, summary.max);
	summary.lesst7 = get_countlesst7(a, size, LT);
	summary.count = get_count(a, size, GT, summary.mid);
	summary.count1 = get_count(a, size, LT, summary.mid);
	summary.search = summary.mid;
	summary.search_stat = linear_search(summary.search, a, size, summary.search_stat);
	summary.sum = find_sum(a, size);
	summary.ctevens = find_evens(a, size, summary.ctevens);
	summary.ctodds = find_odds(a, size, summary.ctodds);
	bubble_sort(a, size);
	insertion_sort(a, size);
	swaptime(a, size);
	summary.divby = div_by(a, size);
	summary.avg = find_avg(size, summary.sum);
	summary.median = find_median(a, size);
	summary.divby = div_by(a, size);
	print_array(a, size);
	print_summary(summary);
}

/*
 * print size of array (25 Sept 2016)
 * @param summary, a structure containing all the parameters for the functions
 * @return void
 * */
void print_summary(struct summary_t summary)
{
	printf("size of the array = %zu\n", summary.size);
	printf("the max of the array = %d\n", summary.max);
	printf("the min of the array = %d\n", summary.min);
	printf("the mid of the array = %d\n", summary.mid);
	printf("the number of components greater than mid is %d\n", summary.count);
	printf("the number of components less than mid is %d\n", summary.count1);
	printf("the number of components less than 7 is %d\n", summary.lesst7);
	if (summary.search_stat == 1) {
		printf("the mid point is found in the data\n");
	} else {
		printf("the mid point is not found in the data\n");
	}
	printf("the sum of all values in array is %f\n", summary.sum);
	printf("the average of the values is %f\n", summary.avg);
	printf("the median of all values is %f\n", summary.median);
	printf("there are %d even numbers in the array.\n", summary.ctevens);
	printf("there are %d odd numbers in the array.\n", summary.ctodds);
	printf("there are %d numbers divisible by 6.\n", summary.divby);
}

