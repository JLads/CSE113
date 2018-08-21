#include<stdio.h>


int main() 
{
	int *p;
	int a, b;
	a = 0;
	b = 1;

//corrected joseph ladino Oct 17 2016
	p = &a;
//p = a;
	printf("%d\n", *p); 

//corrected joseph ladino oct 17 2016
//	b = &p;
//	redundant declration
	
	printf("%d\n", b); 

 	return 0;
}
