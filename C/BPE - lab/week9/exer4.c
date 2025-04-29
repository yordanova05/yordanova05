#include<stdio.h>
#include<stdlib.h>

int main(){
    // dinamichen masiv ot int chisla, zadelqme i copirame chisla > 0 kratni na 5 ot purviq masiv
    // i printirame noviq masiv

    int i;
    int n;
    int count = 0;
    printf("n = ");
    scanf("%d", &n);

    int *array = (int*)calloc(n, sizeof(int));

    for ( i = 0; i < n; i++){
        scanf("%d", &array[i]);
        if( array[i] % 5 == 0 ){
            count++;
        }
    }

    int *newarray = (int*)malloc(count*sizeof(int));
    int new_i = 0;
    for ( i = 0; i < n; i++){
        if( array[i] % 5 == 0 ){
            newarray[new_i] = array[i];
            new_i++;
        }
    }

    for( i = 0; i < count; i++){
        printf("%d, ", newarray[i]);
    }

    free(array);
}
