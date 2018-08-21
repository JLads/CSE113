/*
 *@file lab4_q4.c
 *@brief takes a date and determines the zodiac associated with it.
 *@details takes a date, converts it to julian date, and compares it against an array to find the julian date index to switch on, returning the zodiac.
 *
 *
 *
 *
 *
 *
 *@author Joseph ladino
 *@date Oct 6 2016
 *@bug none
 *@todo none
 */



#include <stdio.h>
#include <stdlib.h>
/* todo make leap year an int function and set if else to run the jd calc*/
struct date_t {
	short s_month;
	short s_day;
	short s_year;
// use %hu for print statements
};

void print_date(struct date_t date);
void get_input(struct date_t *date);
enum month;
int leap_year(struct date_t date);
int julian(struct date_t date);
int julian_leap(struct date_t date);
int julian_index(int julian_date);
void print_zodiac(int j_index);

int main(void)
{
	while (1) {
		int again;
		struct date_t date;
		int julian_date;
		int j_index;
		get_input(&date);
		julian_date = leap_year(date);	
		j_index = julian_index(julian_date);
		print_date(date);
		print_zodiac(j_index);

		printf("would you like to do it again?\n1 for yes\n2 for no \n");
		scanf("%d", &again);
		if (again == 2) {
			break; 
		}
		else if (again > 2) {
			printf("I told you to enter 2 to quit.?\n");
			break;
		}
	}
}

/*
 *gets input of date
 *@param *date pointer to write date into data at given address
 */
void get_input(struct date_t *date)
{
	printf("enter a date (mm dd yyyy)\n");
	scanf("%hu %hu %hu", &date->s_month, &date->s_day, &date->s_year);
}

/*
 *enmumerates months for use later
 */
enum month
{
	JAN = 1, FEB, MAR, APR, MAY, JUNE, JUL, AUG, SEPT, OCT, NOV, DEC
};

/*
 *determines if leap year and choses conversion to use
 *@param date, structure with date information
 */
int leap_year(struct date_t date)
{
	int conversion;
	if ((date.s_year % 4 == 0 && date.s_year % 100 != 0) || date.s_year % 400 == 0) {
		conversion = julian_leap(date);
		
	}
	else {
		conversion = julian(date);
	}
	return conversion;
}

/*
 *determines julian date
 *@param date, date structure from input
 *@return julian date
 */
int julian(struct date_t date)
{
	int num_days[] = {0, 31, 28, 31 ,30, 31, 30, 31, 31, 30, 31, 30, 31};
	int jd = 0;
	size_t size = date.s_month;
	int i;
	for (i = 0 ; i < size ; i++) {
		jd = jd + num_days[i];
	}
	jd = jd + date.s_day;
	return jd;
}

/*
 *determines the julian date for leap years
 *@param date, date structure from input
 *@return julian date
 */
int julian_leap(struct date_t date)
{
	int leap_num_days[] = {0, 31, 29, 31 ,30, 31, 30, 31, 31, 30, 31, 30, 31};
	int jd = 0;
	size_t size = date.s_month;
	int i;
	for (i = 0 ; i < size ; i++) {
		jd = jd + leap_num_days[i];
	}
	jd = jd + date.s_day;
	return jd;
}

/*
 *determines the julian index of julian dates
 *@param date, the julian date
 *@retun index of julain date (incremented date for the zodiacs)
 */ 
int julian_index(int julian_date)
{
	int i;
	int julian_index = 0;
	int start_date[] = {21, 51, 80, 111, 142, 173, 204, 235, 267, 297, 327, 356};
	for (i = 0 ; i < 12 ; i++) {
		if (julian_date < start_date[i]) {
			julian_index = i-1;
			break;
		}
	}
	if (julian_index < 0) {
		julian_index = 11;
	}
	return julian_index;
}

/*
 *prints the zodiac
 *@param index the index that determines the zodiac division of the year
 */
void print_zodiac(int j_index)
{
	switch (j_index) {
		case 0 :
			printf("You are an Aquarius.\n");
		break;
		case 1 :
			printf("You are a Pisces.\n");
		break;
		case 2 :
			printf("You are an Aries.\n");
		break;
		case 3 :
			printf("You are a Tarus.\n");
		break;
		case 4 :
			printf("you are a Gemini.\n");
		break;
		case 5 :
			printf("you are a Cancer.\n");
		break;
		case 6 :
			printf("You are a Leo.\n");
		break;
		case 7 :	
			printf("you are a Virgo.\n");
		break;
		case 8 :
			printf("you are a Libra.\n");
		break;
		case 9 :
			printf("you are a Scorpio.\n");
		break;
		case 10 :
			printf("you are a Sagittarius.\n");
		break;
		case 11 :
			printf("you are a Capricorn.\n");
		break;
	}
}

/*
 *prints out the date with the month spelled out
 *@param date, the date from the input
 */
void print_date(struct date_t date)
{
	switch(date.s_month) {
		case JAN :
			printf("Januaray %d, %d\n", date.s_day, date.s_year);
		break;
		case FEB :
			printf("Februrary %d, %d\n", date.s_day, date.s_year);
		break;
		case MAR :
			printf("March %d, %d\n", date.s_day, date.s_year);
		break;
		case APR :
			printf("April %d, %d\n", date.s_day, date.s_year);
		break;
		case MAY :
			printf("May %d, %d\n", date.s_day, date.s_year);
		break;
		case JUNE :
			printf("June %d, %d\n", date.s_day, date.s_year);
		break;
		case JUL :
			printf("July %d, %d\n", date.s_day, date.s_year);
		break;
		case AUG :
			printf("August %d, %d\n", date.s_day, date.s_year);
		break;
		case SEPT :
			printf("September %d, %d\n", date.s_day, date.s_year);
		break;
		case OCT :
			printf("October %d, %d\n", date.s_day, date.s_year);
		break;
		case NOV :
			printf("November %d, %d\n", date.s_day, date.s_year);
		break;
		case DEC :
			printf("December %d, %d\n", date.s_day, date.s_year);
		break;
	}
}	





