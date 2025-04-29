#include <stdio.h>

int main(){
    float n, m, v, f;
    scanf("%f\n%f\n\n%f\n%f", &n, &m, &v, &f);
    float result = (n*v + m*f)*1.95;
    printf("Result = %.2f", result);

}
