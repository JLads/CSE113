/*
 *@file fundamental.c
 *@brief swaps a value of a double
 *@details using a pointer changes the value of a double
 *
 *
 *
 * @author Joseph ladino
 * @date OCT 23 2016
 * @bug none
 * @todo none
 * 
 **/

#include <stdio.h>
#include <stdlib.h>

void swap(double *p, double q);

int main(void)
{
    double *p;
    double a = 3.14159;
    double q = 0.271828;
    p = &a;
    printf("p is equal to %f\n", *p);

    swap(p, q);
    printf("p is now equal to %f\n", *p);



}

/*
 * swaps the value at p with the value q
 * @param double *p, pointer to the double a
 * @param double q, the double holding the value to swap p to.
 * @return void
 * */
void swap(double *p, double q)
{
    *p = q;
}
