#include <stdio.h>

int triangle(int x, int y);

int main(void)
{
	int x;
	int y;
	printf("enter first angle");
	scanf("%d", &x);
	printf("enter second angle");
	scanf("%d", &y);

	printf("the third angle is %d\n", triangle(x, y));

	return (0);

}

int triangle(int x, int y)
{
	return (180-(x+y));
}
