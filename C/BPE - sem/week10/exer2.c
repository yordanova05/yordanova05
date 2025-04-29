#include<stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n][m];

    for(int i = 0; i < n; i++){
        for(int y = 0; y < m; y++){
            printf("arr[%d][%d]:",i,y);
            scanf("%d", &arr[i][y]);
        }
    }

    int maxSum = -10000;
    int bestI =0, bestJ = 0;

    for (int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            int sum = 0;

            for( int dx = -1; dx <= 1; dx++){
                for (int dy = -1; dy <= 1; dy++){
                    if (dx == 0 && dy == 0){
                        continue;
                    }

                    int ni = i + dx;
                    int nj = j + dy;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m){
                        sum += arr[ni][nj];
                    }
                }
            }

            if (sum > maxSum){
                maxSum = sum;
                bestI = i;
                bestJ = j;
            }
        }
    }

    printf("Suma na okolnite chisla na arr[%d][%d] = ", bestI, bestJ, maxSum);


}
