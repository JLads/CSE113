/*
 *@file multiples.c
 *@brief finds the sum of all numbers that are multiples of 3 and 5 
 *@details finds all numbers 1-999 that are multiples of 3 or 5 and then sums them
 *
 *
 *
 *
 *@author Joseph ladino
 *@date oct 13 2016
 *@bug none
 *@todo none
 */



#include <stdio.h>
#include <stdlib.h>


int main()
{
	int sum = 0;
	int i;
	int array[1000];
//	size_t size = (sizeof array)/(sizeof array[0]);
	for (i = 0 ; i < 1000 ; i++) {
		array[i] = i + 1;
		printf("%d\n", array[i]);
	}
	for (i = 0 ; i < 999 ; i++){
		if (array[i] % 5 == 0 || array[i] % 3 == 0) {
			sum = array[i] + sum;
		}
	}
	printf(" the sum of numbers between 1 and 1000 divisible by three or five is %d\n", sum);

	return 0;
}
