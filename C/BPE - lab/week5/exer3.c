#include <stdio.h>

// vuvejda se cqlo chislo koeto predstavlqva kod na geometrichna figura 1- kvadrat - 2 pravougulnik, 3 - prav triugulnik, sled
// tova se vivejdat razmeri, trqbva da izvede tipa na geometrichnata figura i neinoto lice, za presmqtane na liceto da se napishat potrebitelski funkcii

float kvadrat(float x);
float pravougulnik(float x, float y);
float triugulnik (float x, float y);

int main()
{
    int number;
    float a,b;
    printf("Vuvdedi 1- kvadrat - 2 pravougulnik, 3 - prav triugulnik: ");
    scanf("%d", &number);
    if (number == 1){
        printf("Vuvedi stoinost za a: ");
        scanf("%f", &a);

        printf("Area (kvadrat): %.2f",kvadrat(a));
    }

    else if (number == 2){
        printf("Vuvedi stoinost za a i b: ");
        scanf("%f %f",&a, &b);

        printf("Area (pravougulnik): %.2f",pravougulnik(a,b));

    }
    else if (number == 3){
        printf("Vuvedi stoinost za a i b: ");
        scanf("%f %f",&a, &b);
        //int c = kvadrat(a,b);
        printf("Area (triugulnik): %.2f",triugulnik(a,b));
    }

}

float kvadrat(float x){
    float c = x*x;
    return c;
}
float pravougulnik(float x, float y){
    float c = x*y;
    return c;
}
float triugulnik(float x, float y){
    float c = x*y/2;
    return c;
}
