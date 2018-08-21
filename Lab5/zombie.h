/*
 *@file zombie.h
 *@brief holds prototypes of functions and preprocessing information
 *@detail pretty much same as brief
 *
 *
 *
 *
 *@author Joseph Ladino
 *@date Oct 7 2016
 *@bug tbd
 *@todo tbd
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_
#include <stdio.h>
#include <stdlib.h>
/* function prototypes here*/

struct zombie_t{
	enum { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} day;
	float blood;
	int toes;
	int hour;
	int min;
	int sec;
	char dead;
};
void zombie_input(struct zombie_t *zombie, int index);
void print_zombie(struct zombie_t *zombie);
void death(struct zombie_t *zombie, int index);
void get_blood(struct zombie_t *zombie, int index);
void get_toes(struct zombie_t *zombie, int index);
void get_day(struct zombie_t *zombie, int index);
void get_time(struct zombie_t *zombie, int index);





#endif
