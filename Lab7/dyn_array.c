/*
 * @file dyn_array.c
 * @brief pinter version of array functions
 * @detail sets an array into a malloc pointer and then finds the min, max, avg, sorts, and finds median.
 *
 *
 *
 *
 *
 * @author joseph ladino
 * @date oct 28 2016
 * @bug none
 * @todo have functions send data values to a structure
 * */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MALLOC_FAILED 1000
void print_array(int *a, size_t len);
void get_input(int *a, size_t len);
void print_element(int index, int *a);
void find_max(int *a, size_t len);
void find_min(int *a, size_t len);
void array_avg(int *a, size_t len);
void print_avg(double avg);
void sort(int *a, size_t len);
void median(int *s, size_t len);
void print_median(float median);
             
                
/*
 * @remark the lines commentd out wtih // are there to take input from a user. 
 * @remark when commenting them back in comment out line 44, 45, 50, 61.
 * */
int main(void)
{
        size_t len;
        int *a;
//        char buff[1024]; 
        int b[] = {4, 6, 2, 4, 9, 11, 14, 16, 1, 15, 3};
        int i;

//        printf("input number of ints you wish to analyze.\n");
//        fgets(buff, 1024, stdin);
//        sscanf(buff, "%zu", &len);
        len = sizeof(b)/sizeof(int);
        a = malloc(len*sizeof(int));
        if (a == NULL) {
                printf("no space left. Malloc failed. Exiting... \n");
                exit(MALLOC_FAILED);  /*sets malloc of space and tests it*/
        }       
        for (i=0; i < len; i++) {
                *(a+i) = *(b+i);
        }

//        get_input(a, len)i;
        print_array(a, len);
        find_max(a, len);
        find_min(a, len);
        array_avg(a, len);
        sort(a, len);
        median(a, len);

        free(a);

}


/*
 * gets input from user.
 * @remark did this for fun. as submitted it is not used.
 * @param *a, the malloced pointer with the array
 * @param len, size of the array
 * @return void
 * */
void get_input(int *a, size_t len)
{
        int i;
        char buff[1024];
        printf("please enter each integer followed by the return key. (int, return, int, return)\n");
        for (i = 0; i < len; i++) {
                fgets(buff, 1024, stdin);
                sscanf(buff, "%d", (a+i)); /*take input, scan to *(a+i), repeat*/
        }
}
        
/*
 * prints the entire array
 * @param *a, the pointer to the array
 * @param len, the size of the array.
 * */
void print_array(int *a, size_t len)
{
        int i;
        printf("the array is:\n");
        for (i=0; i<len; i++) {
                printf("%d\n", *(a+i));
        }
}

/*
 * finds max of array
 * @param *a, pointer to array
 * @param len, size of the array
 * @return void
 * */
void find_max(int *a, size_t len)
{
        int index = 0; /*set an index = 0*/
        int max;
        int max_index = 0; /*index of the current max*/
        max = *(a+index);

        for(index = 0; index < len; index++) {
                if (max < *(a+index)) {
                        max = *(a+index); 
                        max_index = index; /*reccords index of the max*/
                }
        }

        printf("the max of this data set is: ");
        print_element(max_index, a);
}

/*
 * finds the minimum
 * @param *a, the array to be analyzed
 * @param len, the length of the array
 * */
void find_min(int *a, size_t len)
{
        int index = 0;
        int min;
        int min_index = 0; /*the index of the current minimum*/
        min = *(a+index);

        for(index = 0; index < len; index++) {
                if (*(a+index) < min) {
                        min = *(a+index);
                        min_index = index; /*keeps track of the index of the minimum*/
                }
        }

        printf("the min of this data set is: ");
        print_element(min_index, a);
}      

/*
 * finds average of array
 * @param *a, the array to average
 * @param len, length of the array
 * */
void array_avg(int *a, size_t len)
{
        double sum_array = 0;
        int i;
        double avg;

        for (i = 0; i < len; i++) {
                sum_array += *(a+i); /*takes sum of all elements in array*/
        }

        avg = (sum_array/len); /*avg = sum of elements - #of elements*/
        print_avg(avg);
}

/*
 * prints the average 
 * @param avg, the calculated avg of the array
 * */
void print_avg(double avg)
{
        printf("the average of this data is %f\n", avg);
}

/*
 * sorts array from lowest to highest for median
 * @param *a, the array to be sorted
 * @param len, the length of the array
 * */
void sort(int *a, size_t len)
{
        int i, j, k;
        for (i = 0; i < len; i++) { index = 0, /*incriment index to len-1*/
                k = *(a+i); /*key is a[i]*/
                j = i-1; /*index to test against key*/
                while (j >= 0 && *(a+j) > k) {
                        *(a+(j+1)) = *(a+j); /*if a[j] > key swap a[j] and key*/
                        j--;
                }
                *(a+(j+1)) = k;
        }
        print_array(a, len);
}

/*
 * finds median
 * @param *a, the array to be analyzed
 * @param len, the lengthg of the array
 * */
void median(int *a, size_t len)
{
        float median;
        if (len % 2 == 0) {
                median = (a[len/2] + a[(len/2) -1]) / 2.0;
        }
        else {
                median = a[len/2];
        }
        print_median(median);
}

/*
 * prints median
 * @param median, the calculated median of the array
 * */
void print_median(float median)
{
        printf("the median is %f\n", median);
}

/*
 * prints individual element of array
 * @param index, index of the element to be printed
 * @param *a, the array in which the element is found
 * */
void print_element(int index, int *a)
{
        printf("%d\n", *(a+index));
}
