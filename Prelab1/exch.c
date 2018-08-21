#include <stdio.h>
#include <math.h>


float dollar(float a);
float euro(float b);
int main(void)
{
	float a;
	float b;
	printf("enter dollars.");
	scanf("%f", &a);
	printf("enter euros.");
	scanf("%f", &b);
	
	printf("entered dollars coverts to %f euros\n", dollar(a));
	printf("entered euros converts to $%f\n", euro(b));

	return(0);

}

float dollar(float a)
{
	return(a*0.75);
}

float euro(float b)
{
	return(b/0.75);
}
