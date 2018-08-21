/*
 *@file array_struct.c
 *@brief holds functions for an array of structures
 *@details takes an array of structures and finds which struct has the max and min of each variable.
 *
 *
 *
 *
 *@author Joseph Ladino
 *@date Oct 6 2016
 *@bug none
 *@todo none
 */




#include "array_struct.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//size_t size;
	struct data_t data[5];

	/* data initialization calls */
	init_array(data, 0, 'A', 23, 74);
	init_array(data, 1, 'B', 22, 64);
	init_array(data, 2, 'C', 19, 68);
	init_array(data, 3, 'D', 20, 76);
	init_array(data, 4, 'E', 22, 62);

	printf("the data array is as follows;\n");
	print_index_returns(data, SIZE);

	print_avg(data, SIZE); 
	
	printf("\n minimum age\n");
	print_indiv_struct(data[age_min(data, SIZE)]);

	printf("\n maximum age\n");
	print_indiv_struct(data[age_max(data, SIZE)]);

	printf("\n minimum height\n");
	print_indiv_struct(data[height_min(data, SIZE)]);

	printf("\n maximum height\n");
	print_indiv_struct(data[height_max(data, SIZE)]);

	return 0;
}

/*
 *initializes the array of structures' individual variable set 
 *@param data[], array holding data structures
 *@param index, the index of the data used for selecting a struct
 *@param id, the id of each subject
 *@param years, the age
 *@param inches, heights of subjects
 */
void init_array(struct data_t data[], int index, char id, int years, int inches)
{
	data[index].height = inches;
	data[index].age = years;
	data[index].subject = id;
}	

/*
 *finds which struct contains the age min
 *@param data[], the array of data structures
 *@param size, the size of arrays
 *@return index of strut that has the age min
 */
int age_min(struct data_t data[], size_t size)
{
	int min = data[0].age;
	int i;
	int age_index = 0;
	for (i = 0 ; i < size ; i++) {
		if(data[i].age < min) {
			min = data[i].age;
			age_index = i;
		}
	}
	return age_index;
}

/*
 *finds which struct contains the age max
 *@param data[] the array of data structures
 *@param size, the size of the array
 *@return index of structure containing the age max
 */
int age_max(struct data_t data[], size_t size)
{
	int max = data[0].age;
	int i;
	int age_index = 0;
	for (i = 0 ; i < size ; i++) {
		if(data[i].age > max) {
			max = data[i].age;
			age_index = i;
		}
	}
	return age_index;
}

/*
 *finds the struct that has the size min
 *@param data[] the array of data structures
 *@param size, the size of the array
 *@return index of structure that contains the height min
 */
int height_min(struct data_t data[], size_t size)
{
	int min = data[0].height;
	int i;
	int height_index;
	for (i = 0 ; i < size ; i++) {
		if (data[i].height < min) {
			min = data[i].height;
			height_index = i;
		}
	}
	return height_index;
}

/*
 *finds stucture that contains the size max
 *@param data[] the array of data structures
 *@param size, the size of the array
 *@return index of structure that contains the height max
 */
int height_max(struct data_t data[], size_t size)
{
	int max = data[0].height;
	int i;
	int height_index;
	for (i = 0 ; i < size ; i++) {
		if (data[i].height > max) {
			max = data[i].height;
			height_index = i;
		}
	}
	return height_index;
}

/*
 *finds the average of the ages
 *@param data[] the array of data structures
 *@param size, the size of the array
 *@return average age
 */
int age_avg(struct data_t data[], size_t size)
{
	int sum_age = 0;
	int i;
	int age_avg;
	for (i = 0 ; i < size ; i++) {
		sum_age = sum_age + data[i].age;
	}
	age_avg = (sum_age / 5);
	return age_avg;
}

/*
 *finds the average of the heights
 *@param data[] the array of data structures
 *@param size, the size of the array
 *@return the average of the heights
 */
int height_avg(struct data_t data[], size_t size)
{
	int sum_height = 0;
	int i;
	int height_avg;
	for (i = 0 ; i < size ; i++) {
		sum_height = sum_height + data[i].height;
	}
	height_avg = (sum_height / 5);
	return height_avg;
}

/*
 *prints a single structure from the array
 *@param data[] the array of structures of data
 */
void print_indiv_struct(struct data_t data)
{
	printf("id: %d, age: %d years, height: %d inches\n", data.subject, data.age, data.height);

}

/*
 *prints the array of structures
 *@param data[] the array of data structures
 *@param size, the size of the array
 */
void print_index_returns(struct data_t data[], size_t size)
{
	int i;
	for (i = 0 ; i < size ; i ++) {
		print_indiv_struct(data[i]);
	}

}

/*
 *prints the results of the average functions
 *@param data[] the array of data structures
 *@param size, the size of the array
 */
void print_avg(struct data_t data[], size_t size)
{
	int avgh;
	int avga;
	avgh = height_avg(data, size);
	avga = age_avg(data, size);
	printf("average age is %d years\n", avga);
	printf("the average height is %d inches\n", avgh);

}



