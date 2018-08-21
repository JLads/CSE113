/**
 * @file multiply.c
 * @brief takes a start and stop point and multiplies all values between them
 * @details start and stop are recorded. The values from start to stop
 * @details are multiplied together
 *
 * @author Joseph Ladino
 * @date fall 2016
 * @bug none
 * */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define S 10
int multiply_range(int start, int stop);
int input();

int main()
{
	int start;
	int stop;
	char s[S];
	printf("please enter starting point and end point. (start_stop)\n");
	fgets(s , S , stdin);
	sscanf(s, "%d %d", &start, &stop);
	multiply_range(start, stop);
	printf("%d\n", multiply_range(start, stop));

	return 0;
}


/**
 * multiplies the values between start and stop on a regualr number line
 * @param start, the value to start multiplying at
 * @param stop, the value to stop multiplying at
 * @return product start to stop
 * */
int multiply_range(int start, int stop)
{
	int tmp;
	if (start > stop){
		tmp = start;
		start = stop;
		stop = tmp;
	}
	int product = 1;
	for(; start <= stop ; start ++) {
		product = start * product;	
	}
	return product;

}
