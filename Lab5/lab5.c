/*
 *@file lab5.c
 *@brief holds the main menu for zombie database
 *@details initializes the zombie structure and then allows user to write a data set or print the existing data set for zombies.
 *
 *
 *
 *
 *
 *
 *
 *@author Joseph Ladino
 *@date oct 10 2016
 *@bug none
 *@todo find food, find survivors, kill zombies
 */

#include <stdio.h>
#include <stdlib.h>
#include "zombie.h"


int main()
{
	int index = 0;
	struct zombie_t zombie[5];                                             
	char choice[10];
	while (1) {
		printf("What to do? \nn, enter new zombie\np, print zombie info\nf, fight the zombie behind you. (exit)\n");
		fgets (choice, 10, stdin);
		switch (choice[0]) {
			case 'n' :

				zombie_input(zombie, index);
				printf("index = %d\n", index);
				index++;
/*@remark resets index*/	if (index == 5) {
					index = 0;
				}
			break;
			case 'p' :
				for (index = 0 ; index < 5 ; index++) {
					printf("zombie %d\n", index);	
					print_zombie(&zombie[index]);
				}
			break;
			case 'f' : 
				printf("You walk outside, you risk your life. You take a drink of water, you risk your life. Nowadays you breath and you risk your life. You don't have a choice. The only thing you can choose is what you're risking it for.\nstay alert and watch for zombies. \ngoodluck out there. goodbye.\n");
				return 0;
			break;
			default:
			printf("were you eaten by a zombie?\n");
			continue;
		}
	}
	return 0;
}
