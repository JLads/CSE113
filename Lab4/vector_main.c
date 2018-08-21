#include<stdio.h>
#include "vector.h"

int main(void)
{
	int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};        
	int a2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	int a3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3}; 
	int copya3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3}; 
	int b4[] = {10, 10, 10, 10, 10, 10, 10, 10 ,10 ,10};
	int c4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3}; 
	int b5[] = {10, 10, 10, 10, 10, 10, 10, 10 ,10 ,10};
	int c5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	int b6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	int c6[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3};
	int a8[10];
     
	size_t size = sizeof(a1) / sizeof(int);
	srandom(time(NULL));
	multiply_constant(a1, size);
	add3(a2, size);
	copy_array(a3, size, copya3);
	add_array(a4, size, b4, c4);
	multiply_array(a5, b5, c5, size);
	multiply_reverse(a6, b6, c6, size);
	reverse_array(size, a7);
	generate_array_8(a8, size);
	print_array_all(a1, a2, copya3, c4, c5, c6, a7, a8, size);
	
	
}
