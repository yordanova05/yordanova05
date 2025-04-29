
#include<stdio.h>
int main(){
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
            printf("%d", arr[row][col]);
        }
        printf("\n");
    }

    int max_minus = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(arr[row][col] < 0 && arr[row][col] < max_minus){
                max_minus = arr[row][col];
            }
        }
        printf("\n");
    }

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if ((row + col == n - 1) && max_minus != 0){
                printf("%d", max_minus);
            }
            else{
                printf("%d", arr[row][col]);
            }
        }
        printf("\n");
    }

}
