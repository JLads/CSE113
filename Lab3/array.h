/*
 * @file array.h
 * 
 * @author Scott Chadde
 * @author Joseph Ladino
 *
 * @date fall 2016 modified
 *  
 * Assignment: Lab 3 
 *
 * @brief header file for array.c
 *
 * @details see array.c for details
 *  
 * @bugs none
 *
 * @todo none
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#define LT 10
#define GT 11
#define GE 12
#define LE 13
#define EQ 14
#include <stdlib.h> 		/* for size_t declaration */

/* function declarations go here */
void print_array(int a[], size_t size);

int find_max(size_t size, int a[]);
int find_min(size_t, int a[]);
int find_mid(int min, int max);
int get_countlesst7(int a[], size_t size, int type);
int get_count(int a[], size_t size, int type, int mid);
int linear_search(int search, int a[], size_t size, int search_stat);
double find_sum(int a[], size_t size);
double find_avg(size_t size, double sum);
void bubble_sort(int a[], size_t size);
void swaptime(int a[], size_t size);
void insertion_sort(int a[], size_t size);
int find_evens(int a[], size_t size, int ctevens);
int find_odds(int a[], size_t size, int ctodds);
float find_median(int a[], size_t size);
int div_by(int a[], size_t size);
#endif

