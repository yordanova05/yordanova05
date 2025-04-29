#include<stdio.h>
int main(){
    int arr [10] = {6,1,4,10,5,4,4,7,3,8};
    int k = 5;

    for(int i = 0; i < 9; i++){
        int swapped = 0;
        for (int j = 0; j < 10 - i - 1; j++){
            if(arr[j] > arr[j+1]){
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
                swapped = 1;
            }
        }
        if (!swapped){
            break;
        }
    }
    for(int m = 0; m < 10; m++){
        printf("%d ", arr[m]);
    }

    int count = 0;

    for(int m = 0; m < 10; m++){
        if(arr[m] != arr[m+1]){
            count++;
            if (count == k){
                printf("\n%d ", arr[m]);
            }
        }
    }
}
