



#include <stdio.h>
#define size 1001

void int_array(int a[]);
void print_array(int a[]);


int main(void)
{
	int a[1001];
	int_array(a);
	print_array(a);


	return 0;
}

void int_array(int a[])
{
	int i = 1001;
	while (i >0){
	
		a[i] = i - 1;
		i --;
	}
}


void print_array(int a[])
{
	int i = 1001;
	while (i > 0) {
		printf("%d\t", a[i]);
		i--;
	}
}
