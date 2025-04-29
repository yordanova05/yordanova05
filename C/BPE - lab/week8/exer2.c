#include<stdio.h>
int main(){
    //izvedete elementite nad glaviq diagonal
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            printf("arr[%d][%d] = ",row,col);
            scanf("%d", &arr[row][col]);
        }
    }
    //nad glavniq diagonal
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(row < col){
                printf("%d", arr[row][col]);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("-----------------");
    // pod glavniq diagonal
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(row > col){
                printf("%d", arr[row][col]);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
