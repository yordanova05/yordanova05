#include<stdio.h>

int main(){
    int n;
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    scanf("%d",&n);

    for (int i = 0; i < 2; i++){
        printf("/");
        for (int y = 0; y < n/2; y++){
            printf("^");
        }
        printf("\\");
        count++;
        if((n > 3 && n%2 == 1) && count == 1){
            printf("_");
        }
    }

    printf("\n");
    for (int z = 0; z < n/2; z++){
        printf("|");
        for (int y = 0; y < (n*2)-3; y++){
            printf(" ");
        }
        printf("|\n");
    }
    if ( n%2 == 1 && n > 3){
        printf("|");
        for (int y = 0; y < (n*2)-4; y++){
            printf(" ");
            if((n > 3 && n%2 == 1) && count2 == n-3){
            printf("-");
            }
            count2++;
        }
        printf("|\n");
    }

    for (int i = 0; i < 2; i++){
        printf("\\");
        for (int y = 0; y < n/2; y++){
            printf("_");
        }
        printf("/");
        count++;
        if((n > 3 && n%2 == 1) && count3 == 1){
            printf(" ");
        }
    }
}
