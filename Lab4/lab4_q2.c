/*
 *@file lab4_q2.c
 *@brief enumerates on colors and prints
 *@details sets and enumeration on some colors and the prints the values.
 *
 *
 *
 *@author Joseph Ladino
 *@date Oct 6 2016
 *@bug none
 *@todo none
 */



#include <stdio.h>
#include <stdlib.h>

/*
 *enumerates on colors
 */
enum color
{
	RED = 18, ORANGE, YELLOW = 5, GREEN, BLUE, INDIGO = 14, VIOLET
};

int main()
{
	printf("RED = %d, Oarnge = %d, Yellow = %d, Green = %d, Blue = %d, Indigo = %d, Violet = %d\n", RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET);

	return 0;
}

