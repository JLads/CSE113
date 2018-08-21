#include <stdio.h>


float function(float a);

int main(void)
{
	float a;

	printf("enter value to eval");
	scanf("%f", &a);


	printf("the result is %f\n", function(a));
	return(0);
}



float function(float a)
{
	return((a+2)/3);
}
