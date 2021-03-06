/*
 * @file swap.c
 * @brief. I didnt write this. I just implemented pointers for everything to make it work
 * @detail see above
 *
 *
 * @author Joseph Ladino
 * @date Oct 26 2016
 * @todo none
 * @bug none
 * */



#include <stdio.h>

void print_vars(int *a, int *b)
{
	printf("a = %d\tb = %d\n", *a, *b);
}

/* a first try at writing a swap function */
/* swap the contents a with b and b with a */
void swap(int *a, int *b)
{
	int tmp; 
        tmp = *a;
	*a = *b;
	*b = tmp;

	printf("in function swap: ");
	print_vars(a,b);
}

int main(void)
{
	int a;
        a = 6;
	int b; 
        b = 9;
	printf("before swap: ");
	print_vars(&a,&b);
	
	swap(&a, &b);

	printf("after swap: ");
	print_vars(&a,&b);

	return 0;
}
