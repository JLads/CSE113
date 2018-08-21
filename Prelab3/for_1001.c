/**
 * @file for_1000.c
 * @brief prints value 1 - 1000
 * @details simple. sets parameter and prints the values
 *
 * @author Joseph Ladino
 * @date fall 2016
 * @bug none
 * @todo none
 * */



#include <stdio.h>
#define size 1000



int main()
{
	int i;
	for (i = 0 ; i < 1001 ; i++)
		printf("%d\n", i);
	return 0;
}
