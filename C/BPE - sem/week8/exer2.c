#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr [n];
    int result;

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (int j = 0; j < n-2; j++){
        if( arr[j] < arr[j+1] && arr[j+1] > arr[j+2]){
            result = 1;
        }
        else{
            result = 0;
        }

    }

    printf("%d", result);
}
