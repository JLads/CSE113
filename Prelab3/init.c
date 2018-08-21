/**
 * @file init.c
 * @brief prints 1 - 1000 from an array in main
 * @details none more to give
 *
 * @author Joseph Ladino
 * @Date fall 2016
 * @bug none
 * */



#include <stdio.h>


int main()
{
	int i;
	int a[1000];
	size_t size = (sizeof a/ sizeof a[0]);
	for (i = 0 ; i < size ; i++) {
		a[i] = i + 1;
		printf("%d\n", a[i]);
	}
	return 0;
}
