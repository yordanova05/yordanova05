#include<stdio.h>
#include<stdbool.h>

bool rowssorted(int n, int m, int arr[n][m]){
    int count = 1;
        for (int row = 0; row < n-1; row++){
            for( int column = 0; column < m-1; column++){
                if ( arr[row][column]>arr[row][column+1] ){
                    count = 0;
                    break;
                }
            }
    }
    return count;
}

bool columnssorted(int n, int m, int arr[n][m]){
    int count = 1;
    for( int column = 0; column < m; column++){
        for ( int row = 0; row < n-1; row++){
            if ( arr[row][column]<arr[row+1][column] ){
                count = 0;
                break;
            }
        }
    }
    return count;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n][m];

    for(int i = 0; i < n; i++){
        for(int y = 0; y < m; y++){
            int x;
            printf("arr[%d][%d]:",i,y);
            scanf("%d", &x);
        }
    }

    bool rowsok = rowssorted(n,m,arr);
    bool colsok = columnssorted(n,m,arr);

    if (rowsok == colsok && rowsok == n - 1){
        printf("TRUE!");
    }
    else{
        printf("FALSE");
    }
}
