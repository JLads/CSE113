#include <stdio.h>

/*
 * @remark initialize main function.
 * */
int main()
{
/*
 * @remark sets "input" to 0 by default
 * @remark recieve user input for the value of "input")
 * */
	int input = 0 ;
	printf("enter and integer: \n");
	scanf("%d", &input);
/*
 * @remark if "input == 1" is true. execute the folowing.
 **/
	if (input == 1) {
		printf("first is the worst.\n");
/*
 * @remark if "input == 1" is false test "input == 2"
 * @remark if "input == 2" is true execute following
 * */
	} else if (input == 2) {
		printf("second is the best ");
		printf("beacuse the second mouse gets the cheese\n");
		printf("and it is the first prime number. ");
/*
 * @remark if "input == 2 " is false test "input == 5"
 * @remark if "input == 5" is true execute following
 * */
	} else if (input == 5) {
		printf("you know, 5 of 6 doctors agree russian roulette is harmless. \n");
/*
 * @remark if "input == 5" is false test "input == 69"
 * @remark if "input == 69" is true execute the following
 * */
	} else if (input == 69) {
		printf("giggity giggity \n");
		printf("Who else but Quagmire? \n");
		printf("He's Quagmire, Quagmire.\n");
		printf("You never really know what he's gonna do next\n");
		printf("He's Quagmire, Quagmire.\n");
		printf("giggity giggity giggity, let's have sex.\n");

/*
 * @remark if "input == 69" is false execute the following
 * */
	} else {
		printf("insert witty condesending message here \n");
	}

	return 0;
}
