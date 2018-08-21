/**
 * @file Lab1.c
 * @brief this is the first lab for cse 113. it is a simple geometric calculator.
 * @details This declares functions and uses variables to calculate geometic values.
 * */


#include <stdio.h>
#include <math.h>

/**
 * @remark declration of functions
 * @remark declration of variables per funcion
 * */
double polygon_area(double n, double s);
double int_angle(double n);
double ext_angle(double n);
double triangle_perimeter(double e, double f, double g);
float hypotenuse(float i, float j);
double triangle_area(double e, double h);
float circumference(float d);
float circle_area(float d);
float rectangle_diagonal(float i, float j);
int rectangle_perimeter(int a, int b);
int rectangle_area(int a, int b);


/**
 * @remark initiaize main function
 * @remark declare variables
 **/
int main(void)
{
	int a;
	int b;
	float d;
	float i;
	float j;
	double e;
	double f;
	double g;
	double h;
	double n;
	double s;
	int z;

/**
 * @remark print welcom and directions
 * @remark print menu
 * */
	printf("welcome to the cse113 lab 1: a simple geometry calculator. Please enter a number between from 1 to 12 based on the desired function.\n");
	printf("enter 1 for rectangle area *integers*\n");
	printf("enter 2 for rectangle perimerter\n");
	printf("enter 3 for rectangle diagonal\n");
	printf("enter 4 for circle area\n");
	printf("enter 5 for circle circumfrence\n");
	printf("enter 6 for triangle area\n");
	printf("enter 7 for right triangle hypotenuse\n");
	printf("enter 8 for perimeter of a triangle\n");
	printf("enter 9 for exterior angles\n");
	printf("enter 10 for interior angles\n");
	printf("enter 11 for regular polygon calculation\n");
	printf("enter 12 to exit\n");
	scanf("%d", &z);

	
	if (z==1) {
	
		printf("input rectangle length");
		scanf("%d", &a);
		printf("input rectangle height");
		scanf("%d", &b);

		printf("the area of this rectangle is %d\n", rectangle_area(a, b));
	} else 
	if (z==2) {

		printf("input rectangle length");
		scanf("%d", &a);
		printf("input rectangle height");
		scanf("%d", &b);

		printf("the perimeter of the rectangle is %d\n", rectangle_perimeter(a, b));
	} else 

	if (z==3) {

		printf("enter side 1");
		scanf("%f", &i);
		printf("enter side 2");
		scanf("%f", &j);

		printf("the diagonal is %f", rectangle_diagonal(i, j));
	} else 

	if (z==4) {
		printf("enter diameter of circle");
		scanf("%f", &d);

		printf("the area of the circle is %f\n", circle_area(d));
	} else 

 	if (z==5) {

		printf("enter circle diameter.");
		scanf("%f", &d);

		printf("the perimeter of the circle is %f\n", circumference(d));
	} else 

	if (z==6) {

		printf("enter base length");
		scanf("%lf", &e);
		printf("enter height");
		scanf("%lf", &h);
		printf("the area of the triangle is %lf\n", triangle_area(e, h));
	} else 

	if (z==7) {

		
		printf("enter side 1");
		scanf("%f", &i);
		printf("enter side 2");
		scanf("%f", &j);
		printf("the hypotenuse is %f\n", hypotenuse(i, j));
	} else 

	if (z==8) {

		printf("enter first side");
		scanf("%lf", &e);
		printf("enter second side");
		scanf("%lf", &f);
		printf("enter third side");
		scanf("%lf", &g);

		printf("the perimeter of the triange is %f\n", triangle_perimeter(e, f, g));
	} else 

	if (z==9) {

		printf("enter number of sides");
		scanf("%lf", &n);

		printf("the exterior angle measure is %lf degrees\n", ext_angle(n));


	} else 
	if (z==10) {

		printf("enter number of sides");
		scanf("%lf", &n);

		printf("the sum of the interior angles is %lf degrees\n", int_angle(n));


	} else 

	if (z==11) {
		printf("enter length of a side");
		scanf("%lf", &s);
		printf("enter number of sides");
		scanf("%lf", &n);

		printf("the area of a regular polygon with %lf sides, each %lf long, is %lf\n", n, s, polygon_area(n, s));

	} else 
	if (z==12) {
		printf("I see how it is. Can do the work yourself eh?\n");
		return (0);
	} else {
		printf("Please follow directons and try again.\n");
		return (0);
	}




}

/**
 * @peram a the first side
 * @peram b the second side
 * @return a*b the formula for area of rectangle
 * */
int rectangle_area(int a, int b)
{
	return (a*b);
}

/**
 * @peram a, side one
 * @peram b, side two
 * @return 2a + 2b for perimeter
 * */
int rectangle_perimeter(int a, int b)
{
	return (a+a+b+b);
}

/**
 * @peram a, one side
 * @peram b, side 2
 * @return square root of a^2 + b^2
 * */
float rectangle_diagonal(float i, float j)
{
	return (sqrt(pow(i, 2)+pow(j, 2)));
		
}

/**
 * @ peram d, circle diameter
 * @return pi * (d/2)^2
 * */
float circle_area(float d)
{
	return (3.14159265389*pow(d/2, 2));
}

/**
 * @peram d, diameter of circle
 * @return pi * diameter
 * */
float circumference(float d)
{
	return (d*3.14159265389);
}

/**
 * @peram e, base of triangle 
 * @peram h, height of triangle
 * @return 1/2 * e * h
 * */
double triangle_area(double e, double h)
{
	return (0.5*e*h);
}

/**
 * @peram i, one leg of right triangle
 * @peram j, other leg of right triangle
 * @return square root of i^2 + j^2
 * */
float hypotenuse(float i, float j)
{
	return (sqrt(pow(i, 2)+pow(j, 2)));
}	

/**
 * @peram e, one side of triangle
 * @peram f, second side of triangle
 * @peram g, third side of triangle
 * @return sum of e, f and g
 * */
double triangle_perimeter(double e, double f, double g)
{
	return (e+f+g);
}

/**
 * @peram n, number of sides in polygon
 * @return 360/n, formula for ext angle measure
 * */
double ext_angle(double n)
{
	return (360/n);
}

/**
 * @peram n, number of sides of polygon
 * @return 180*(n-2) quantity divided by n
 * */
double int_angle(double n)
{
	return ((180*(n-2)/n));
}

/**
 * @peram n, number of sides in polygon
 * @peram s, length of a side of polygon
 * @return (S^2) * n quantity divided by 4* tan(pi/n)
 * */
double polygon_area(double n, double s)
{
	return((pow(s, 2)*n)/(4*tan(3.14159265389/n)));
}
