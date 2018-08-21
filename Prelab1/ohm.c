#include <stdio.h>

float volts(float a, float o);
float amps(float v, float o);
float ohms(float v, float a);

int main(void)
{
	float v;
	float a;
	float o;

	printf("if value is unknown enter 0\n");
	printf("enter volts");
	scanf("%f", &v);
	printf("enter amps");
	scanf("%f", &a);
	printf("enter resistance");
	scanf("%f", &o);

	if (v==0) {
		printf("volts equals %f\n", volts(a, o));
	} else 
	
		if (a==0) {
			printf("amps equals %f\n", amps(v, o));
			
	} else 
		if (o==0) {
		printf("ohms of resistance equals %f\n", ohms(v, a));
		
	} else {
		return (0);
	}

}

float volts(float a, float o)
{
	return(a*o);
}

float amps(float v, float o)
{
	return(v/o);
}

float ohms(float v, float a)
{
	return(v/a);
}
