/**
 * @file life.h
 * @brief header file with prototypes for the game of life
 * 
 *
 * @author Joseph Ladino       
 * @date Dec 1 2016
 * @todo none
 * @bug none
 **/
#include <stdio.h>
#ifndef LIFE_H_
#define LIFE_H_

unsigned char **init_matrix(int rows, int cols);
void read_file(FILE *pattern, unsigned char **array, int rows, int cols);
void life(unsigned char **array, unsigned char **array2, int rows, int cols);
void torus(unsigned char** array, unsigned char** array2, int rows, int cols);
unsigned char get_tor(int rows, int cols, int i, int j, unsigned char** array);
void kill_with_fire(unsigned char** matrix, int rows, int cols);
void klein(unsigned char** array, unsigned char** array2, int rows, int cols);
unsigned char get_klein(int rows, int cols, int i, int j, unsigned char** array);
#endif
