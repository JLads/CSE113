#ifndef ARRAY_STRUCT_H_
#define ARRAY_STRUCT_H_

#include <stdlib.h>
#define SIZE 5

struct data_t {

	int age;  /* age of the subject */
	int height;  /* height of subject in inches */
	char subject; 	/* one capital letter id for subject */
	
};

void init_array(struct data_t data[], int index, char id, int years, int inches);
int age_min(struct data_t data[], size_t size);
int age_max(struct data_t data[], size_t size);
int height_min(struct data_t data[], size_t size);
int height_max(struct data_t data[], size_t size);
int age_avg(struct data_t data[], size_t size);
int height_avg(struct data_t data[], size_t size);
void print_indiv_struct(struct data_t data);
void print_index_returns(struct data_t data[], size_t size);
void print_avg(struct data_t data[], size_t size);

#endif
