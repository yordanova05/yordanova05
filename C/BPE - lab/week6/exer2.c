// 7 chisla ,da se napishe vasiv koito se pulni s chisla ot intervala -5000 do 5000 v , da izvede sumata na vuvedentie chisla koito sa nechetni
#include<stdio.h>

int main(){
    int arr[7];
    int x;
    int sum = 0;
    for (int i = 0; i <= 6;){
        scanf("%d",&x);
        if( x <= 5000 && x >= -5000){
            arr[i]=x;
            i++;
        }
    }
    for (int i = 0; i <= 6; i++){
        if ( arr[i]%2 == 1 ){
            sum += arr[i];
        }
    }
    printf("sum = %d",sum);
}
