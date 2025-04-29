#include<stdio.h>
int main(){
    int arr [10] = {6,1,9,10,5,2,4,7,3,8};

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
        if (swapped == 0){
            break;
        }
    }

    for(int k = 0; k < 10; k++){
        printf("%d ", arr[k]);
    }
}
// 5 1 7 8
