/*
 *@file lab4_q3.c
 *@brief holds functions of distance and input of points
 *@details takes two cartesian points as input and then calculates the manhattan distance between them and the euclidean distance. 
 *
 *
 *
 *
 *
 *@author Joseph Ladino
 *@date Oct 10 2016
 *@bug none
 *@todo none
 */




#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct point_t {
	double x;
	double y;

	double a;
	double b;
};

void get_input(struct point_t *point);
void print_function(double distance);
void print_results(struct point_t point);
double euclidean(struct point_t point);
double manhattan(struct point_t point);



int main()
{
	struct point_t point;
	
		
	get_input(&point);
	printf("%lf %lf; %lf, %lf\n", point.x, point.y, point.a, point.b);
	print_results(point);
	return 0;
}

/*
 *gets two points as input
 *@param point acts as a pointer to the structure of points
 */
void get_input(struct point_t *point)
{
	printf(" enter a point x y\n");
	scanf("%lf %lf", &(point->x), &(point->y));
	
	printf(" enter a point x y\n");
	scanf("%lf %lf", &(point->a), &(point->b));
}

/*
 *prints the result of a distance function
 *@param distance, the distance caclulated
 */
void print_function(double distance)
{
	printf("%lf.\n", distance);
}

/*
 *prints the results of the distance functions
 *@param point, structure of points to pass to the print functions
 */
void print_results(struct point_t point)
{
	printf("the euclidean distance is\n");
	print_function(euclidean(point));
	printf("\n the manhattan distance is\n");
	print_function(manhattan(point));
}

/*
 *calculates the euclidean distance
 *@param point, the array of points to use in the formula
 *@return euclidean distance
 */
double euclidean(struct point_t point)
{
	double distance;
	distance = sqrt((pow(point.x - point.a, 2)) + (pow(point.y - point.b, 2)));
	return distance;
}

/*
 *calculates the manhattan distance
 *@param point the structure of points for distance calculations
 *@return manhattan distance
 */
double manhattan(struct point_t point)
{
	double distance;
	distance = (abs(point.x - point.a) + abs(point.y - point.b));
	return distance;
}
