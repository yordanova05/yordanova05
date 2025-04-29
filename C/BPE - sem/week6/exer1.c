#include <stdio.h>
int max_number(int x, int y);
int min_number(int x, int y);

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    int result = max_number(a,b);
    int result1 = min_number(a,b);
    if (result != result1){
        printf("Maximalno chislo: %d",result);
        printf("\nMinimalno chislo: %d",result1);
    }

}

int max_number(int x, int y){
    if (x > y){
        return x;
    }
    else if (x < y){
        return y;
    }
    else{
        printf("I dvete chisla sa ednakvi!");
    }
}
int min_number(int x, int y){
    if (x < y){
        return x;
    }
    else if (x > y){
        return y;
    }
    else{
        printf("\nI dvete chisla sa ednakvi!");
    }
}

