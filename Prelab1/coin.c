#include <stdio.h>

int sum_coins(int a, int b, int c, int d);

int main()
{
	int a;
	int b;
	int c;
	int x;

	printf("number of pennies?");
	scanf("%d", &a);
	printf("number of nickels?");
	scanf("%d", &b);
	printf("number of dimes?");
	scanf("%d", &c);
	printf("number of quarters ?");
	scanf("%d", &x);

	printf("the value of this change is %d cents \n", sum_coins(a, b, c, x));
	return(0);

}

int sum_coins(int a, int b, int c, int x)
{
	return((a*1) + (b*5) + (c*10) + (x*25));
}
