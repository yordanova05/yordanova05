#include <stdio.h>
#include<math.h>

int main() {
    int grd;

    scanf("%d", &grd);
    float rad = grd*(M_PI / 180 );
    float sin_i = sin(rad);
    float cos_i = cos(rad);
    float tg_i = tan(rad);
    float cotg_i = 1/tan(rad);
    printf("sin(%d) = %f\n",grd, sin_i);
    printf("cos(%d) = %f\n",grd, cos_i);
    printf("tg(%d) = %f\n",grd, tg_i);
    printf("cotg(%d) = %f",grd, cotg_i);

    return 0;

}
