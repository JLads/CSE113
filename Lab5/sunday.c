/*
 *@file sunday.c
 *@brief finds the number of months that start on a sunday from 1901 till 2000
 *@detail incriments through months and days to set a flag for a new month starting. Also calculates a julian date. Tests for if julian date % 7 = 0 and if new month. If so sundays incriment
 *
 *
 *
 *
 *@author Joseph Ladino
 *@date OCT 13 2016
 *@bug none
 *@todo figure out why count_day is set at one not 2.  stupid crypitc one off error
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	enum month{ JAN = 1, FEB, MAR, APR, MAY, JUNE, JUL, AUG, SEPT, OCT, NOV, DEC, PLACE};
	int year = 1901;
	int month = 1;
	int sundays = 0;
	int day = 1;
	int leap = 0;
	int flag = 0;
	int count_day = 1;
	
	while (1) {
		
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
			leap = 1;
		}
		switch (month) {
			case JAN :
			case MAR :
			case MAY :
			case JUL :
			case AUG :
			case OCT :
			case DEC :
				if (day == 31) {
					flag = 1;
					day = 1;
					month++; /*when month ends, marks new month, resets day, incriments month */
					if (month == 13) {
						month = 1;
						year ++;
						leap = 0; /*when year ends, incriment year, reset month, set leap year to false */
					}
				}
				break;
			case APR :
			case JUNE :
			case SEPT :
			case NOV :
				if (day == 30) {
					flag = 1;
					day = 1;
					month ++; /*if month ends, flag new month, reset day incriment month */
				}
			break;	
		}

		if (month == FEB) {
			if ((leap == 0 && day == 28) || (leap == 1 && day == 29)) 
			{
				flag = 1;
				day = 1;
				month++; /* when month ends flags new month and resets day. increment month */
			}
		}
		if (count_day % 7 == 0 && flag == 1) {
			sundays++;
			flag = 0;
		}
		count_day++;
		day++;
		flag = 0;
		if (year == 2001) {
			break;
		}
	}
	printf(" the number of months that start on a sunday since long ago in 1901 is %d\n", sundays);
}			
