#include <stdio.h>
int main()
{
	int r;
	printf("Enter the radius of the circle: ");
	scanf("%d", &r);


	float area = 3.14 * r * r;
	printf("The area of the circle is: %.2f cm^2 \n", area);
	
	return 0;
}
