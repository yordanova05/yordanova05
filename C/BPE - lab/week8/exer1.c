#include<stdio.h>
int main(){
    // za kvadraten masiv: definirame s razmernost n na n i go populnete s celi chisla. Printira se na konzolata elementite ot glavniq diagonal
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            printf("arr[%d][%d] = ",row,col);
            scanf("%d", &arr[row][col]);
        }
    }

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(col == row){
                printf("%d", arr[row][col]);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if((col + row) == n-1){
                printf("%d", arr[row][col]);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
