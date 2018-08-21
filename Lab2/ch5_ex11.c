/*
 * @file ch5_ex11.c
 * @brief this takes a two digit number and prints the number in english
 * @details once the input is taken it is split into its digits and each digit is assessed by switch statemetns. 
 * @details the number is then printed.
 *
 * @author Joseph Ladino
 * @date fall 2016
 * @bug none
 * @todo make this more efficient and set it as an array function instad of whatever the hell this is.
*/


#include <stdio.h>
#include <stdlib.h>
#define S 5
int get_input();
int det_num(char x, char y);
int main()
{
	get_input();


	return 0;
	

}

/*
 * takes input from user and seperates the digits
 * @param char s[S]
 * @param char digit 1
 * @param char digit 2
 * @return 0
 * */
int get_input()
{
	char digit1;
	char digit2;
	char s[S];
	printf("enter a 2 digit number.\n");
	fgets(s, S, stdin);
	digit1 = s[0];
	digit2 = s[1];
	printf("%c, %c\n", digit1, digit2);
	det_num(digit1, digit2);

	return 0;
}


/*
 * uses embedded switch in a swtich to determine the number. Yes this could be done a lot faster.
 * @param char x
 * @param char y
 * @return number based on char input.
 * */
int det_num(char x, char y)
{
	switch(x) {
		case '1' :
			switch(y) {
				case '0' :
					printf("the number is ten\n");
					break;
				case '1' :
					printf("The nuber is eleven       \n");
					break;
				case '2' :
					printf("The number is twelve       \n");
					break;
				case '3' :
					printf("The number is thirteen       \n");
					break;
				case '4':
					printf("The number is fourteen       \n");
					break;
				case '5' :
					printf("The number is fifteen       \n");
					break;
				case '6' :
					printf("The number is sixteen       \n");
					break;
				case '7' :
					printf("The number is seventeen       \n");
					break;
				case '8' :
					printf("The number is eighteen       \n");
					break;
				case '9' :
					printf("the number is nineteen       \n");
					break;
				default:
					return 0;
				
			}
		break;
			
		case '2' :
			switch(y) {
				case '0' : 
					printf("the number is twenty\n");
					break;
				case '1' :
					printf("the number is twenty one       \n");
					break;
				case '2' :
					printf("the number is twenty two       \n");
					break;
				case '3' :
					printf("the number is twenty three       \n");
					break;
				case '4':
					printf("the number is twenty four       \n");
					break;
				case '5' :
					printf("the number is twenty five       \n");
					break;
				case '6' :
					printf("the number is twenty six       \n");
					break;
				case '7' :
					printf("the number is twenty seven       \n");
					break;
				case '8' :
					printf("the number is twenty eight       \n");
					break;
				case '9' :
					printf("the number is twenty nine       \n");
					break;
				default :
					return 0;	
			}
			break;	
		case '3' : 
			switch(y) {
				case '0' :
					printf("the number is thrity\n");
					break;
				case '1' :
					printf("the number is thirty one       \n");
					break;
				case '2' :
					printf("the number is thrity two       \n");
					break;
				case '3' :
					printf("the number is thrity three       \n");
					break;
				case '4':
					printf("the number is thrity four       \n");
					break;
				case '5' :
					printf("the number is thrity five       \n");
					break;
				case '6' :
					printf("the number is thrity six      \n");
					break;
				case '7' :
					printf("the number is thrity seven       \n");
					break;
				case '8' :
					printf("the number is thrity eight       \n");
					break;
				case '9' :
					printf("the number is thrity nine       \n");
					break;
				default :
					return 0;
				
			}



			break;
		case '4' : 
			switch(y) {
				case '0' :
					printf("the number is forty\n");
					break;
				case '1' :
					printf("the number is forty one       \n");
					break;
				case '2' :
					printf("the number is forty two       \n");
					break;
				case '3' :
					printf("the number is forty three       \n");
					break;
				case '4':
					printf("the number is forty four       \n");
					break;
				case '5' :
					printf("the number is forty five       \n");
					break;
				case '6' :
					printf("the number is forty six       \n");
					break;
				case '7' :
					printf("the number is forty seven       \n");
					break;
				case '8' :
					printf("the number is forty eight       \n");
					break;
				case '9' :
					printf("the number is forty nine       \n");
					break;
				default :
					return 0;
				
			}

			break;
		case '5' :
			switch(y) {
				case '0' :
					printf("the number is fifty\n");
					break;
				case '1' :
					printf("the number is fifty one       \n");
					break;
				case '2' :
					printf("the number is fifty two       \n");
					break;
				case '3' :
					printf("the number is fifty three       \n");
					break;
				case '4':
					printf("the number is fifty four       \n");
					break;
				case '5' :
					printf("the number is fifty five       \n");
					break;
				case '6' :
					printf("the number is fifty six       \n");
					break;
				case '7' :
					printf("the number is fifty seven       \n");
					break;
				case '8' :
					printf("the numbere is fifty eight       \n");
					break;
				case '9' :
					printf("the number is fifty nine       \n");
					break;
				default :
					return 0;
				
			}

			break;
		case '6' : 
			switch(y) {
				case '0' :
					printf("the number is sixty\n");
					break;
				case '1' :
					printf("the number is sixty one       \n");
					break;
				case '2' :
					printf("the number is sixty two       \n");
					break;
				case '3' :
					printf("the number is sixty three       \n");
					break;			
				case '4':
					printf("the number is sixty four       \n");
					break;
				case '5' :
					printf("the number is sixty five       \n");
					break;
				case '6' :
					printf("the number is sixty six       \n");
					break;
				case '7' :
					printf("the number is sixty seven       \n");
					break;
				case '8' :
					printf("the number is sixty eight       \n");
					break;
				case '9' :
					printf("the number is sixty nine  *giggity*     \n");
					break;
				default :
					return 0;
				
			}

			break;

		case '7' :
			switch(y) {
				case '0' : 
					printf("the number is seventy\n");
					break;
				case '1' :
					printf("the number is seventy one      \n");
					break;
				case '2' :
					printf("the number is seventy two       \n");
					break;
				case '3' :
					printf("the number is seventy three       \n");
					break;
				case '4':
					printf("the number is seventy four       \n");
					break;
				case '5' :
					printf("the number is seventy five       \n");
					break;
				case '6' :
					printf("the number is seventy six       \n");
					break;
				case '7' :
					printf("the number is seventy seven       \n");
					break;
				case '8' :
					printf("the number is seventy eight        \n");
					break;
				case '9' :
					printf("the number is seventy nine       \n");
					break;
				default :
					return 0;
				
			}
			break;
		case '8' :
			switch(y) {
				case '0' :
					printf("the number is eighty\n");
					break;
				case '1' :
					printf("the number is eighty one       \n");
					break;
				case '2' :
					printf("the number is eighty two       \n");
					break;
				case '3' :
					printf("the number is eighty three       \n");
					break;
				case '4':
					printf("the number is eighty four       \n");
					break;
				case '5' :
					printf("the number is eighty five       \n");
					break;
				case '6' :
					printf("the number is eighty six       \n");
					break;
				case '7' :
					printf("the number is eighty seven       \n");
					break;
				case '8' :
					printf("the number is eighty eight       \n");
					break;
				case '9' :
					printf("the number is eighty nine       \n");
					break;
				default :
					return 0;
				
			}
			break;
		case '9' :
			switch(y) {
				case '0' :
					printf("the number is ninety\n");
					break;
				case '1' :
					printf("the number is ninety one       \n");
					break;
				case '2' :
					printf("the number is ninety two       \n");
					break;
				case '3' :
					printf("the number is ninety three       \n");
					break;
				case '4':
					printf("the number is ninety four       \n");
					break;
				case '5' :
					printf("the number is ninety five       \n");
					break;
				case '6' :
					printf("the number is ninty six       \n");
					break;
				case '7' :
					printf("the number is ninety seven       \n");
					break;
				case '8' :
					printf("the number is ninety eight       \n");
					break;
				case '9' :
					printf("the number is ninety nine       \n");
					break;
				default:
					return 0;
				
			}
			break;
		break;
		default :
			printf("I dont want to tell you what that number is.\n");
			return 0;
		
	}
	return 0;
}





