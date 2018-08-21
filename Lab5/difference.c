/*
 *@file difference.c
 *@brief finds difference between sum of numbers squared and the sum of squared numbers
 *@detail takes numbers 1-100 and sums them, then squares that sum. Then takes the numbers 1-100 and squares each of them, then sums them. Then takes the difference between the two.
 *
 *
 *
 *
 *
 *
 *
 *@author Joseph Ladino
 *@date OCT 13 2016
 *@bug none
 *@todo none
 */ 



#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int sum_squared(void);
int sum_of_squared(void);

int main(void)
{
	int a;
	int b;
	int c;
	a = sum_squared();
	b = sum_of_squared();
	c = abs(a-b);
	printf("the difference between the sum of the numbers 0-100 squared and the sum of the square of all whole numbers 1-100 is %d\n", c);
}

/*
 *takes sum of numbers 1-100 and then squares them
 *@param void no parameters need to be passed in
 */
int sum_squared(void)
{
	int sum = 0;
	int i = 0;
	int flag = 0;
	while (flag == 0) {
		sum = sum + 1 + i;
		i++;
		if (i == 100) {
			flag = 1;
		
		}
	}	
	sum = sum * sum;
	printf("the sum(1-100)^2 is %d\n", sum);
	return sum;
}

/*
 *takes the numbers 1-100 and squares them, then adds all of those values
 *@param void  no parametern need to be passed in
 */
int sum_of_squared(void)
{
	int a[100];
	int sum;
	int i = 0;
	for (i = 0 ; i < 100 ; i ++) { /*writes array of 1-100*/
		a[i] = i + 1;
	}
	for (i = 0 ; i < 100 ; i++) { /*squares each term of array*/
		a[i] = pow(a[i], 2);
	}
	for (i = 0 ; i < 100 ; i++) { /*adds each term of array together*/
		sum = sum + a[i];
	}
	printf("the sum(1^2 - 100^2) = %d\n", sum);
	return sum;
}

