#include<stdio.h>>
float bonus( int x );

int main(){
    int n;
    scanf("%d", &n);
    float result = bonus(n);
    printf("Bonus tochki: %.2f\n", result);
    printf("Obsht broi tochki: %.2f", n + result);
}

float bonus(int x){
    float bonus = 0;
    if ( x <= 100 ){
        bonus += 5;
    }
    else if ( x > 100 && x < 1000 ){
        bonus += x*20.0/100;
    }
    else{
        bonus += x*10.0/100;
    }
    if ( x % 2 == 0 ){
        bonus += 1;
    }
    if ( x == 5 || x % 10 == 5 ){
        bonus += 2;
    }
    return bonus;
}
