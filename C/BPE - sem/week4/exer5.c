#include <stdio.h>

int main(){
    float inch;
    scanf("%f", &inch);
    printf("mm: %.4f\n",inch*25.4);
    printf("sm: %.4f\n",inch*25.4/10);
    printf("dm: %.4f\n",inch*25.4/100);
    printf("m: %.4f\n",inch*25.4/1000);

    return 0;
}
