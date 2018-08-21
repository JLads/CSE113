/*
 * @file ch5_ex8.c
 * @brief recieve input and output next availible time
 * @details a time is recorded as a string and then converted into hours since mindinght
 * @detail and by doing this compare input time against a set sechedlue to return the next available flight
 *
 * @author Joseph Ladino
 * @date fall 2016
 * @bug none
 * @todo none
 * */




#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int timeconvert(char s[10]);

int main(void)
{
	char s[10];
	printf("enter a 24 hour time (hours:minutes)\n");
	fgets(s, 10, stdin);
	int time = timeconvert(s);
	
	if(time < 480) {
		printf("the next flight departs at 8:00 am and arrives at 10:16 am\n");
	} else if(480 < time && time < 583) {
		printf("the next flight departs at 9:43 am and arrives at 11:52 am.\n");
	} else if(583 < time && time < 679) {
		printf("the next flight departs at 11;19 and and arrives at 1:31 pm.\n");
	} else if( 679 < time && time < 767) {
		printf("the next flight departs at 12:47 pm and arrives at 3:00 pm.\n");
	} else if(767 < time && time < 840) {
		printf("the next flight departs at 2:00 pm and arrives at 4:08 pm.\n");
	} else if(840 < time && time < 940) {
		printf("the next flight departs at 3:45 pm and arrives at 5:55 pm.");
	} else if(940 < time && time < 1140) {
		printf("the next flight departs at 7:00 pm and arrives at 9:20 pm.\n");
	} else if(1140 < time && time < 1305) {
		printf("the next flight departs at 9:45 pm and arrives at 1:58 pm.\n");
	}
		
	return 0;
	

}


/**
 * converts 24 hour time to minutes from 12:00 am
 * @param chars[10] the time input as a string to be divided into its hours and minutes components
 * @return (hours * 60) + minutes
 * */
int timeconvert(char s[10])
{
	int hours;
	int minutes;
	sscanf(s, "%d:%d", &hours, &minutes);
	int x = (hours * 60) + minutes;
	return(x);
}
