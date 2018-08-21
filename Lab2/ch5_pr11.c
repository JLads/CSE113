/*
 * @file ch5_pr11.c
 * @brief this will take in an area code and output the corresponding city
 * @details this uses a switch to determine the city given area code.
 *
 * @author Joseph Ladino
 * @date fall 2016
 * @bug none
 * @todo none
 **/
#include <stdio.h>

int main()
{
	int area_code;
	printf("enter area code.\n");
	scanf("%d", &area_code);

	switch (area_code) {
		case 229 : 
			printf("the city with area code 229 is Albany.\n");
		break;
		case 404 :
			printf("the city with area code 404 is Atlanta.\n");
		break;
		case 470 :
			printf("the city with area code 470 is Atlanta.\n");
		break;
		case 478 :
			printf("the city with area code 478 is Macon.\n");
		break;
		case 678 :
			printf("the city with area code 678 is Atlanta.\n");
		break;
		case 706 :
			printf("the city with area code 706 is Columbus.\n");
		break;
		case 762 :
			printf("the city with area code 762 is Columbus.\n");
		break;
		case 770:
			printf("the city with area code 770 is Atlanta.\n");
		break;
		case 912 :
			printf("the city with area code 912 is Savannah.\n");
		break;
		default: 
			printf("area code not recognized.\n");
		}
	return 0;
}
