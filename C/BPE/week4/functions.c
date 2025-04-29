#include <stdio.h>

int func(int x)  {
    x++;
}

double fun(double x)  {
    x++;
}

double fu(double x, double y)  {
    x = x + y;
    y = x - y;
    x = x - y;
    printf("%f - %f\n", x, y);
}

int sum( int x, int y){
    return x + y;
}

int fib() {
    int x = 1;
    x++;
    if (x < 10){
        fib();
    } else {
        return x;
    }
}

int main()  {
    int x = 5;
    int y = 8;
    /*func(x);
    printf("%d\n",x);*/
    fu(x,y);
    printf("%d - %d\n", x, y);
    sum(x,y);
    fib(x);
    return 0;
}

