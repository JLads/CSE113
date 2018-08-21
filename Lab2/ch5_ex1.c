/*
 * @file ch5_ex1
 * @brief this is an exercise in addendum to lab two that reinforces the use of if - else blocks.
 * @details this is a simple exercise that uses an if - else block to print a response based on input conditionals.
 *
 * @author Joseph Ladino
 * @date 19 Sept, 2016
 * */

#include <stdio.h>

int main(void)
{
	int n;
	printf("Please enter a integer.\n");
	scanf("%d", &n);
	if (0 < n && n < 10) {
		printf("the number %d has one digit.\n", n);
	} else if (9 < n && n < 100) {
		printf("The number %d has 2 digits\n", n);
	} else if (99 < n && n < 1000) {
		printf("the number %d has 3 digits\n", n);
	} else if (999 < n && n < 10000) {
		printf("the number %d has 4 digits.\n", n);
	} else { printf(" im to lazy to count those digits. do it yourself.");
	return 0;
	}
}
