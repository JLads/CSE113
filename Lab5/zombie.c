/*
 *@file zombie.c
 *@brief database of zombies in the apocolypse
 *@detail Database of zombies found. able to take input of zombie information, when it was found, dead or not, and how many toes it had or how much blood there was. This information will be stored to be printed later. 
 *
 *
 *
 *
 *
 *@author Joseph Ladino
 *@date Oct 7 2016, day 33 since zombie outbreak
 *@bug tbd
 *@todo find food, find water, find weapons, find other survivors
 */

#include "zombie.h"
#include <stdio.h>

/*
 *takes input for zombie information
 *@param struct zombie_t, the structure of zombie information to be written to. passes this to other input functions.
 *@param index, the index of the array that tells which zombie info section to write to
 *@return void
 */
void zombie_input(struct zombie_t *zombie, int index)
{
	death(zombie, index);
	get_day(zombie, index);
	get_time(zombie, index);
}

/*
 *takes input for is the Zombie dead. If yes, calls toes input. if no, calls blood input
 *@param zombie_t *zombie a pointer to the zombie structure array to write to the data at the zombie address.
 *@param index index of array that tells which zombie to write to
 */
void death(struct zombie_t *zombie, int index)
{
	char state[1024];
	printf("Is the zombie dead? Y/N\n");
	fgets(state, 1024, stdin);
	sscanf(state, "%c", &zombie[index].dead);
	switch (zombie[index].dead) {
		case 'Y': 
		case 'y' :
			printf("How many toes did this mutant zombie have?\n");
			get_toes(zombie, index);
		break;
		case 'N' :
		case 'n' :
			printf("Assuming you killed it, how much blood did it have? (mL or L please)\n");
			get_blood(zombie, index);
		break;
		default: 
			printf("you entered something wrong. Please try again\n");
	}	
}

/*
 *gets the blood amount
 *@param zombie_t *zombie pointer to the zombie structure array for writing
 *@param index index of array of structure to tell which struct to write to
 */
void get_blood(struct zombie_t *zombie, int index)
{
	char num[1024];
	fgets(num, 1024, stdin);
	sscanf(num, "%f", &zombie[index].blood);
}

/*
 *gets the toes amount
 *@param zombie_t *zombie pointer to the zombie structure array for writing
 *@param index index of array of structure to tell which struct to write to
 */
void get_toes(struct zombie_t *zombie, int index)
{
	char num[1024];
	fgets(num, 1024, stdin);
	sscanf(num, "%d", &zombie[index].toes);
}

/*
 *gets the day input and scans it to day at index
 *@param zombie_t *zombie pointer to the zombie structure array for writing
 *@param index index of array of structure to tell which struct to write to
 */
void get_day(struct zombie_t *zombie, int index)
{
	char week[1024];
	int tmp;
	printf("what day was this zombie found?\n");
	printf("enter:\n1 for monday\n2 for tuesday\n3 for wednesday\n4 for thrusday\n5 for friday\n6 for saturday\n7 for sunday.\n");
	fgets(week, 1024, stdin);
	sscanf(week, "%d", &tmp);
	zombie[index].day = tmp;
	if (tmp > 7) {
		printf("something was entered wrong. Btw zombie behind you.\n");	
	}	
}	

/*
 *gets time and writes it to the structure at time at index
 *@param zombie_t *zombie pointer to the structure to write to
 *@param index, the index of the array which tells which zombie to write to
 */
void get_time(struct zombie_t *zombie, int index)
{
	char time[1024];
	printf("enter the time HH:MM:SS\n");
	fgets(time, 1024, stdin);	
	sscanf(time, "%d:%d:%d", &zombie[index].hour, &zombie[index].min, &zombie[index].sec);

}

/*
 *prints out the data stored in the zombie structure
 *@param struct zombie_t, the structure containing the zombie information to be printed.
 *@return void
 */
void print_zombie(struct zombie_t *zombie)
{
	switch (zombie->dead){
		case 'y' :
		case 'Y' :
			printf("The zombie was found dead.\n");
			printf("the zombie had %d toes.\n", zombie->toes);
		break;
		case 'n' :
		case 'N' :
			printf("the zombie was found ALIVE.\n");	
			printf("%f mL of blood was drained from the corpse.\n", zombie->blood);
		break;
		default:
			printf("%c = zombie dead?\n", zombie->dead);
			break;
	}
	switch (zombie->day) {
		case MONDAY :
			printf("the zombie was found on Monday\n");
		break;
		case TUESDAY :
			printf("the zombie was found on Tuesday\n");
		break;
		case WEDNESDAY :
			printf("the zombie was found on Wednesday\n");
		break;
		case THURSDAY :
			printf("the zombie was found on Thursday\n");
		break;	
		case FRIDAY :
			printf("the zombie was found on Friday\n");
		break;	
		case SATURDAY :
			printf("the zombie was found on Saturday\n");
		break;	
		case SUNDAY :
			printf("the zombie was found on Sunday\n");
		break;
		default :
			break;
	}
	printf("the zombie was found at %d:%d:%d.\n", zombie->hour, zombie->min, zombie->sec);
}

	
