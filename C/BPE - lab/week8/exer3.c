//4 na 5 masiv, zapulvame go s celi chisla, izchislqvame sumite ot elementite po redove, namirame
// minimalnata sred tezi sumi i printirame rezultata v tablica

#include<stdio.h>
int main(){
    int arr[4][5];
    int sums [5] = {0,0,0,0,0};

    for (int row = 0; row < 4; row++){
        for(int col = 0; col < 5; col++){
            printf("arr[%d][%d] = ", row,col);
            scanf("%d", &arr[row][col]);
        }
    }

    for (int row = 0; row < 4; row++){
        for(int col = 0; col < 5; col++){
            sums[row] += arr[row][col];
            printf("%d ",arr[row][col]);
        }
        printf("sum = %d", sums[row]);
        printf("\n");
    }
    int min = sums[0];
    for(int i = 1; i < 4; i++){
       if(sums[i]< min){
        min = sums[i];
       }
    }
    printf("min sum = %d",min);
}
