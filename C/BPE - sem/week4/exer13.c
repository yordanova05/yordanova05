#include <stdio.h>

int main(){
    float w, h;
    scanf("%f %f", &w, &h);
    float num_desc_per_row = ( w - coridor_area)/0.7;
    float coridor_area = h*1;
    float place = 0.7 * 1.2;
    int result = (area - 3*place - coridor_area)/place;
    printf("result: %d", result);

}
