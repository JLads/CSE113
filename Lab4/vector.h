#ifndef VECTOR_H_
#define VECTOR_H_
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void print_array_all(int a1[], int a2[], int copya3[], int c4[], int c5[], int c6[], int a7[], int a8[], size_t size);
void multiply_constant (int a1[], size_t size);
void add3(int a2[], size_t size);
void copy_array(int a3[], size_t size, int copya3[]);
void add_array(int a4[], size_t size, int b4[], int c4[]);
void multiply_array(int a5[], int b5 [], int c5[], size_t size);
void multiply_reverse(int a6[], int b6[], int c6[], size_t size);
void reverse_array(size_t size, int a7[]);
void generate_array_8(int a8[], size_t size);
int get_random_int(int n);
void print_array(int array[], size_t size);
#endif
