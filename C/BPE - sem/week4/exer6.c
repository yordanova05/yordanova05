#include <stdio.h>
#include <math.h>

int main() {
    float gr;
    scanf("%f", &gr);
    printf("Farenheit: %.3fF\n", (gr*9/5)+32);

    float grd;
    scanf("%f", &grd);
    printf("Radiants: %.3f\n", (M_PI / 180)*grd);

    return 0;
}
