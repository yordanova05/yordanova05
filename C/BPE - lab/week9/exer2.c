#include<stdio.h>
#include<stdlib.h>

int main(){
    // koqto zadelq dinamichno masiv ot celi chisla, s golemina n-chisla, n se vuvejda ot potrebitela
    // zapulvame masiva sus stoinosti ot potrebitelq, namirame sumata na dvucifrenite chisla i q printirame

    int *array;
    int i;
    int n;
    int sum = 0;

    scanf("%d", &n);

    array = (int*)malloc(n*sizeof(int));
    if(array == NULL){
        exit(1);
    }

    for( i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    for( i = 0; i < n; i++){
        if((array[i] > 9 && array[i] < 100) || (array[i] < -9 && array[i] > -100)){
            sum += array[i];
        }
    }

    for( i = 0; i < n; i++){
        printf("%d, ", array[i]);
    }

    printf("\nSUM = %d", sum);


}
