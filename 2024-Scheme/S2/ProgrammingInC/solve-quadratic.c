#include <stdio.h>
#include <math.h>

int main()
{
	int a, b ,c;

	printf("The equation is of the form: ax^2 + bx + c\n");
	printf("Enter Values for a, b and c:\n");

	scanf("%d %d %d", &a, &b, &c);
	printf("The resultant equation is: %dx^2 + %dx + %d \n", a, b, c);

	int discriminant = (pow(b, 2))-(4*a*c);

	if (discriminant < 0)
	{
		printf("No real roots are present!\n");

		int x = -discriminant;

		float realPart = (-b)/(2*a);
		float imaginary1 = sqrt(x)/(2*a);
		float imaginary2 = -sqrt(x)/(2*a);

		printf("The roots are %.2f + %.2fi and %.2f + %.2fi \n", realPart, imaginary1, realPart, imaginary2);

	} else if (discriminant == 0) {

		printf("Both roots are same!\n");
		float root = (-b)/(2*a);
		printf("The root of the function is %.2f \n", root);

	} else {
		float root1 = (-b + sqrt(discriminant))/(2*a);
		float root2 = (-b - sqrt(discriminant))/(2*a);

		printf("The roots are %.2f and %.2f \n", root1, root2);
	}

	return 0;
}
