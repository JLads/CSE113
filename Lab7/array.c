/*
 * @file array.c
 * @brief File was given to me. I just make pointer versions of functions and used malloc
 * @detail see above
 *
 * @author joseph ladino       
 * @date Oct 26 2016
 * @bug none
 * @todo none
 * */


#include <stdio.h>
#include <stdlib.h>

/*
 * @todo fix malloc stuff
 **/


/*
void print_array(int a[], size_t len)
{
	int i = 0;
            
	for ( ;i < len;i++)
		printf(i == len - 1 ? "%d\n" : "%d ", a[i]);
			
}
*/

/* pointer arthimetic version of print_array */

/*
 * Prints array using string notation
 * @param *a, the pointer to print from
 * @param len, the length of the string
 * @return void
 * */
void print_parray(int *a, size_t len)
{ 
        int i=0;
        for ( ; i<len; i++) /*incriment through array*/
            printf(i==len-1? "%d\n" : "%d ", *(a+i)); /*print value*/
			
}

/*
void inc_array(int a[], size_t len)
{
	int i = 0;
 
	for ( ; i < len; i++)
		a[i]++; 
		
}
*/

/* pointer based version */


/*
 * incriments each value in array using pointers
 * @param *a, pointer to address of array
 * @param len, size of string/array to print
 * @return void
 * */
void inc_parray(int *a, size_t len) 
{ 
 	int *p = a; 
        int i;
        for (i = 0; i < len; i++) { /*incriment through array*/
            *(p+i) = *(p+i) + 1; /*add one to each elemtent*/
        }
}

/*
 a = a + b 
void add_arrays(int *a, int *b, size_t len)
{
	int i = 0;
	
	for (; i < len; i++) 
		a[i] += b[i];
	
}
*/


/* pointer version of add_arrays a = a + b */

/*
 * adds array a and b with pointer math. YAY!
 * @param *a, pointer to dataset a
 * @param *b pointer to dataaset b
 * @param len, length of strings a and b
 * @return void
 * */
void add_parrays(int *a, int *b, size_t len)
{
        int i = 0;
        for (; i < len; i++) { /* incriments through array*/
            *(a+i) += *(b+i); /* adds each element in a to corresponding elemtn in b*/
        }
	
}


int main() 
{
        int *a = malloc(10*sizeof(int)); /*sets pointer a to memory allocated equal to number of inputs * size of input type*/
	int b[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
       
        if (a==NULL) {
            printf("memory error\n"); /*checks for memory space*/
        }
        int i;
	size_t len_a = 10;
        printf("%zu is len_a\n", len_a); /*checks to make sure len is set right*/
	size_t len_b = sizeof(b)/sizeof(int);

        for (i = 0; i < len_a; i++) {
            *(a+i) = (i+1); /* sets a[i] in the malloc using pointer math*/
        }
	
	printf("a = ");
//	print_array(a, len_a);
	print_parray(a, len_a);

	printf("\nb = ");
//	print_array(b, len_b);
	print_parray(b, len_b); 

//	inc_array(a, len_a);
	printf("\nafter incrementing\na = ");
//	print_array(a, len_a);
        inc_parray(a, len_a);
        print_parray(a, len_a); 

	print_parray(a, len_a);
	if (len_a != len_b) 	/* assume arrays are of the same length */
		exit(EXIT_FAILURE);
	else
		//add_arrays(a, b, len_a);
		add_parrays(a, b, len_a);
	
	printf("\na = a + b\na = ");
//	print_array(a, len_a);
	print_parray(a, len_a);
	printf("\nb remains unchanged\nb = ");
//	print_array(b, len_b);
	print_parray(b, len_b);
        
        free(a);
	return 0;
}
