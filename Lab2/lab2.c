/**
 * @file Lab2.c
 * @brief this is the second lab for cse 113. it is a simple geometric calculator.
 * @details This declares functions and uses variables to calculate geometic values.
 * @details the funcion choice here is set up by a swich statement with nested switches
 * @details that determin function to apply for a given polygon.
 * 
 * @author Joseph ladino
 * @date 19 Sept, 2016
 * */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double polygon_area(double n_sides, double side_length);
double int_angle(double n_sides);
double ext_angle(double n_sides);
double triangle_perimeter(double base, double side, double side1);
float hypotenuse(float leg1, float leg2);
double triangle_area(double base, double height);
float circumference(float diameter);
float circle_area(float diameter);
float rectangle_diagonal(float leg1, float leg2);
int rectangle_perimeter(int length, int height);
int rectangle_area(int length, int height);


int main(void)
{
	int length;
	int height;
	float diameter;
	float leg1;
	float leg2;
	double base;
	double side;
	double side1;
	double heighttri;
	double n_sides;
	double side_length;
	int z;
	int shape;
	int tmp;
	char buf[1024];


	printf("welcome to the cse113 lab 1: a simple geometry calculator. Please enter a number between from 1 to 12 based on the desired function.\n");
	

	printf("please enter a character: \n");
	printf("enter r for rectangles \n");
	printf("enter t for triangles \n");
	printf("enter c for circles \n");
	printf("enter p for regular polygons \n");
	while ((tmp = getchar()) != '\n')
		shape = tmp;


	/*
	 * @remark switch statement to chose which polygon to assess.
	 * */
	switch(shape)
	{
		case 'r':
		case 'R':
			printf("enter an integer from 1 to 3\n");
			printf("enter 1 for area.\n");
			printf("enter 2 for perimeter.\n");
			printf("enter 3 for diagonal.\n");
			fgets(buf, 1024, stdin);

			z = atoi(buf);
			/*
			 * @remark this if statement closes the program should an invalid input be entered
			 * */
			if(z < 1 || z > 3) {
					printf("error. calculator shutting down.\n");
					return 0;
			} else{
				/*
				 * @remark switch in switch to determine which function to evaluate
				 * */
				switch(z) {
				case 1 : 
			
					printf("input rectangle length\n");
					scanf("%d", &length);
					printf("input rectangle height\n");
					scanf("%d", &height);
		
					printf("the area of this rectangle is %d\n", rectangle_area(length, height));
				break;
				case 2 : 
	
					printf("input rectangle length\n");
					scanf("%d", &length);
					printf("input rectangle height\n");
					scanf("%d", &height);
	
					printf("the perimeter of the rectangle is %d\n", rectangle_perimeter(length, height));
				break;
	
				case 3: 
	
					printf("enter side 1\n");
					scanf("%f", &leg1);
					printf("enter side 2\n");
					scanf("%f", &leg2);
	
					printf("the diagonal is %f\n", rectangle_diagonal(leg1, leg2));
				break;
				}	
			}
		break;

		case 'C':
		case 'c':
			printf("enter an integer from 1 to 3\n");
			printf("enter 1 for circumference.\n");
			printf("enter 2 for area.\n");
			fgets(buf, 1024, stdin);
			z = atoi(buf);
			switch(z) {
			/*
			 * @remark switch in switch to determine which function to evaluate
			 * */
				case 1:
					printf("enter diameter of circle\n");
					scanf("%f", &diameter);
					printf("the area of the circle is %f\n", circle_area(diameter));
				break;
				case 2:
					printf("enter circle diameter.\n");
					scanf("%f", &diameter);
					printf("the perimeter of the circle is %f\n", circumference(diameter));
				break;
				default:
					printf("error. calculator shutting down.\n");
				return 0;
			}
		break;
		
		case 't':
		case 'T':
			printf("enter an integer from 1 to 3\n");
			printf("enter 1 for area.\n");
			printf("enter 2 for right triangle hypotenuse.\n");
			printf("enter 3 for perimeter.\n");
			scanf("%d", &z);
			switch(z) {
				/*
				 * @remark switch in switch to determine which function to evaluate
				 * */
				case 1:
	
					printf("enter base length\n");
					scanf("%lf", &base);
					printf("enter height\n");
					scanf("%lf", &heighttri);
					printf("the area of the triangle is %lf\n", triangle_area(base, heighttri));
				break;
				case 2:
	
			
					printf("enter side 1\n");
					scanf("%f", &leg1);
					printf("enter side 2\n");
					scanf("%f", &leg2);
					printf("the hypotenuse is %f\n", hypotenuse(leg1, leg2));
				break;
				case 3:
	
					printf("enter first side\n");
					scanf("%lf", &base);
					printf("enter second side\n");
					scanf("%lf", &side);
					printf("enter third side\n");
					scanf("%lf", &side1);
		
					printf("the perimeter of the triange is %f\n", triangle_perimeter(base, side, side1));
				break;
				default:
					printf("error. calculator shutting down.\n");
				return 0;
			}
		break;

		case 'P':
		case 'p':
			printf("enter an integer from 1 to 3\n");
			printf("enter 1 for exterior angle measure.\n");
			printf("enter 2 for sum of interior angles.\n");
			printf("enter 3 for area.\n");
			scanf("%d", &z);

			switch(z) {
				/*
				 * @remark switch in switch to determine which function to evaluate
				 * */			
				case 1:
					printf("enter number of sides\n");
					scanf("%lf", &n_sides);
		
					printf("the exterior angle measure is %lf degrees\n", ext_angle(n_sides));
				break;
				case 2 :
					
					printf("enter number of sides\n");
					scanf("%lf", &n_sides);
	
					printf("the sum of the interior angles is %lf degrees\n", int_angle(n_sides));
				break;
				case 3 :
					printf("enter length of a side\n");
					scanf("%lf", &side_length);
					printf("enter number of sides\n");
					scanf("%lf", &n_sides);
			
					printf("the area of a regular polygon with %lf sides, each %lf long, is %lf\n", n_sides, side_length, polygon_area(n_sides, side_length));
				break;
				default:
					printf("error. calculator shutting down\n");
				return 0;
				
			}
		break;
		default:
			printf("the char you entered does not correspond to a function \n");
			printf("calculator shutting down\n");
			return 0;

	}




}

/**
 * @peram a the first side
 * @peram b the second side
 * @return a*b the formula for area of rectangle
 * */
int rectangle_area(int length, int height)
{
	return (length*height);
}

/**
 * @peram a, side one
 * @peram b, side two
 * @return 2a + 2b for perimeter
 * */
int rectangle_perimeter(int length, int height)
{
	return (length+length+height+height);
}

/**
 * @peram a, one side
 * @peram b, side 2
 * @return square root of legs of rectangle
 * */
float rectangle_diagonal(float leg1, float leg2)
{
	return (sqrt(pow(leg1, 2)+pow(leg2, 2)));
		
}

/**
 * @ peram d, circle diameter
 * @return pi * (d/2)^2
 * */
float circle_area(float diameter)
{
	return (3.1415926538979*pow(diameter/2, 2));
}

/**
 * @peram d, diameter of circle
 * @return pi * diameter
 * */
float circumference(float diameter)
{
	return (diameter*3.1415926538979);
}

/**
 * @peram e, base of triangle 
 * @peram h, height of triangle
 * @return 1/2 * base * height
 * */
double triangle_area(double base, double heighttri)
{
	return (0.5*base*heighttri);
}

/**
 * @peram i, one leg of right triangle
 * @peram j, other leg of right triangle
 * @return square root of leg1^2 + leg2^2
 * */
float hypotenuse(float leg1, float leg2)
{
	return (sqrt(pow(leg1, 2)+pow(leg2, 2)));
}	

/**
 * @peram e, one side of triangle
 * @peram f, second side of triangle
 * @peram g, third side of triangle
 * @return sum of base and sides
 * */
double triangle_perimeter(double base, double side, double side1)
{
	return (base+side+side1);
}

/**
 * @peram n, number of sides in polygon
 * @return 360/n, formula for ext angle measure
 * */
double ext_angle(double n_sides)
{
	return (360/n_sides);
}

/**
 * @peram n, number of sides of polygon
 * @return 180*(n-2) quantity divided by n
 * */
double int_angle(double n_sides)
{
	return ((180*(n_sides-2)/n_sides));
}

/**
 * @peram n, number of sides in polygon
 * @peram s, length of a side of polygon
 * @return (S^2) * n quantity divided by 4* tan(pi/n)
 * */
double polygon_area(double n_sides, double side_length)
{
	return((pow(side_length, 2)*n_sides)/(4*tan(3.1415926538979/n_sides)));
}
