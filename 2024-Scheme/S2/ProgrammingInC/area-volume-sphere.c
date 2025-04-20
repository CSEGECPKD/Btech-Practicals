#include <stdio.h>

int main()
{
    int r;

    printf("Enter the radius of the sphere: ");
    scanf("%d", &r);

    float area = 4 * 3.14 * r * r;
    float volume = (4 * 3.14 * r * r * r)/3;
    printf("\nSurface area of the sphere is: %.2f cm^2\n", area);
    printf("Volume of the sphere is: %.2f cm^3\n", volume);

    return 0;
}
