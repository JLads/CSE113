#include <stdio.h>
/*
 * @remark I have found 5 errors in this code
 * */
void main()
{
	char input;
	printf("Enter a character: \n");
/*
 * @bug should be "char *", not %f
 * */
	scanf("%f", input);
/*
 * @bug missing break after case a for consistancy sake
 * */
	switch (input) {
		case 'a' :
			printf("A is for apple. \n");
/*
 * @bug should be case 'b' :  not semicolon
 * */
		case 'b' ;
/*
 * @bug \n not /n	
 * */
			printf("B is for banana. /n"); 
			break
/*
 * @bug shoudl say letter "char *"  not %d
 * */
		default:
			printf("the letter %d isn't important \n", input);
	}
	return 0
}
