/*
 *@file smallest.c
 *@brief finds the lowest number divisible by all whole numbers 1-20
 *@details starts number at 2050, which is divisible by all numbers 1-10. tests number against mod 11 - mod 20  and increments number if any of the mods fail. Does this till a value that satisfies the conditions are found in which case a flag is set to 1 to stop the while loop and it breaks from the if.
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

int main()
{
	int num = 2050;
	int flag = 0;
	while(flag == 0) {
		if ((num%11) ==0 && (num%12) == 0 && (num%13) ==0 && (num%14) == 0 && (num%15) == 0 && (num%16) == 0 && (num%17) == 0 && (num%18) == 0 && (num%19) == 0 && (num%20) == 0)
		{
			flag = 1;
			printf("%d\n", num);
			break;
		}
	num ++;
	}
	return 0;
}
