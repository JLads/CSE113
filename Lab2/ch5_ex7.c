/*
 * @file ch5_ex7.c
 * @breif this function finds the max and min of four numbers.
 * @details after taking input this code uses comparative if else blocks to determine the min and max and return them

 *
 * @author Joseph ladino
 * @date fall 2016
 * @bug none
 * @todo none
 * */



#include <stdio.h>

int max(int a, int b, int c, int d);
int min(int a, int b, int c, int d);
int main(void)
{
	int a;
	int b;
	int c;
	int d;
	printf("Please enter four integers seperated by a single space\n");
	scanf("%d" "%d" "%d" "%d", &a, &b, &c, &d);

	printf("the max of the four numbers is %d\n", max(a, b, c, d));
	printf("the minimum of the four numbers is %d\n", min(a, b ,c, d));
	return 0;

}


/*
 * find the max of a, b, c, and d
 * @param int a
 * @param int b
 * @param int c
 * @param int d
 * @return max(a, b, c, d)
 * */
int max(int a, int b, int c, int d)
{
	if(a > b && a > c && a > d){
		return a;
	} else if(b > a && b > c && b > d){
		return b;
	} else if(c > a && c > b && c > d){
		return c;
	} else if(d > a && d > b && d > c){
		return d;
	} else {
		return 0;
	}
}

/*
 * find min of a, b, c, d
 * @param int a
 * @param int b
 * @param int c
 * @param int d
 * @return min(a, b, c, d)
 * */
int min(int a, int b, int c, int d)
{
	if(a < b && a < c && a < d){
		return a;
	} else if(b < a && b < c && b < d){
		return b;
	} else if(c < a && c < b && c < d){
		return c;
	} else if(d < a && d < b && d < c){
		return d;
	} else {
		return 0;
	}
}
