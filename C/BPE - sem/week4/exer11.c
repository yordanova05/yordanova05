#include <stdio.h>
#include <math.h>

int main()  {
    int ax = 5;
    int ay = 3;
    int bx = 4;
    int by = 3;
    int cx = 6;
    int cy = 1;
    double a = hypot(ax+bx,ay+by);
    double b = hypot(ax+cx,ay+cy);
    double c = hypot(cx+bx,cy+by);
    printf("a = %f, b = %f, c = %f\n", a, b, c);
    double p = a + b + c;
    double s = p*(p-a)*(p-b)*(p-c);
    double result = sqrt(s);
    printf("%f",s);

    return 0;
}
