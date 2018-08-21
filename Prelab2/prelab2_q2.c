#include <stdio.h>

/*
 * @remark initialize main function
 * */
int main()
{
/*
 * @remark initialize input and set to 0 by default
 * @remark recieve user input for "input"
 * */
	int input = 0;

	printf("enter an interger: \n");
	scanf("%d", &input);
/*
 * @remark begin switch
 * @remark test for cases.
 * @remark if case is true execute function
 * @remark if case is false test next case
 * @remark if all other cases false execute default.
 * */
	switch (input) {
		case 1:
			printf("one is a lonely number. \n");
			break;
		case 3:
			printf("But thee is just as bad as one ");
			printf("but actually worse, because it's 3.\n");
			break;
		case 7:
			printf("Ya feeling lucky punk? Cause I ate 9.\n");
			break;
		default:
			printf("I could sing about %d, but I really dont care enough. Im too busy commenting on this code.\n", input);
		}
	return 0;
}
