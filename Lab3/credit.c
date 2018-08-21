/*
 * @file credit.c
 * @author Joseph Ladino
 * @date fall 2016
 * @brief determine if a credit card is valid using Luhn's algorithm.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1

void convert_card(int card[], char num[], int num_digits);
void print_card(int card[], int size);
int validity(int sum);
void print_validity(int valid);
int sum_digits(int card[], int num_digits);
void double_digits(int num_digits, int card[]);

int main(void)
{
	int valid;
	int sum;
	int card[16];
	char visa[] = "4012888888881881"; /* valid card */
	/*char visa[] = "4012888888881882";*/  /*invalid card */
	convert_card(card, visa, 16);
	double_digits(16, card);
	sum = sum_digits(card, 16);
	print_card(card, 16);
	valid = validity(sum);
	print_validity(valid);
	return 0;

}

/*
 *@param card, the card number size
 *@param num, the card number itself
 *@param num_digits the number of digits in card number
 */
void convert_card(int card[], char num[], int num_digits)
{
	int i;

	for(i = 0; i < num_digits; i++)			
		card[i] = num[i] - '0';
	
}

/*
 *doubles every other digit starting in the 10s place.
 *@param num_digits, size of array
 *@param card, the array of the card number
 *@return void
 **/
void double_digits(int num_digits, int card[])
{
	int i;
	for (i = 0 ; i < num_digits + 2 ; i++) {
		if (i % 2 == 0) {
			card[i] = 2 * card[i];
		}
	}
}

/*
 * prints card number
 *@param card, the array holding the card number
 *@param size, the size of the array holding the card number
 *@return void
 **/
void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

/*
 *takes sum of digits
 *any value over 10 is converted to digits and summed
 *ie. 17 = 7 + 1 = 8
 *@param visa, the array containing the card number
 *@param num_digits, the number of values in the array
 *@return sum
 **/
int sum_digits(int visa[], int num_digits)
{
	int i;
	int sum = 0;
	for (i = 0 ; i < 16 ; i++) {
		if (visa[i] > 10 ) {
			visa[i] = (visa[i] % 10 + (visa[i] / 10) % 10);
		}
		sum = sum + visa[i];
	}
	return sum;
}

/*
 *determines if card is valid using % 10
 *@param sum, the sum of the digits of the array
 *@reutrn valid
 **/
int validity(int sum)
{
	int valid;
	if (sum % 10 == 0) {
		valid = 1;
	}
	else {
		valid = 0;
	}
	return valid;

}

/*
 *prints validity
 *@param valid, yes or no for validity.
 *@return void
 **/
void print_validity(int valid)
{
	switch (valid) {
	case 1: 
		printf("this card is valid\n");
	break;
	case 0: 
		printf("this card is invalid.\n");
	break;
	default: 
		printf("error\n");
	}
}
