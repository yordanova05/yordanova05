// funkciq s masiv s celi chisla i broi elementi na masiva, vrushta kato rezultat srednoaritmetichnoto ot elementite koito sa polojitelni
// vikame funkciqta i printirame rezultata
#include<stdio.h>
float funct(int arr[], int n);

int main(){
    int n,x;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&x);
        arr[i] = x;
    }
    float result = funct(arr,n);
    printf("average = %f", result);
}


float funct(int arr[], int n){
    float sum = 0.0;
    int count = 0.0;
    for ( int i = 0; i < n; i++){
        if ( arr[i] > 0){
            sum += arr[i];
            count++;
        }
    }
    return sum/count;
}
