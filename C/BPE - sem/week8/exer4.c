
#include<stdio.h>
int main(){
    int n, k;
    scanf("%d %d",&n,&k);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    k = k % n;

    for (int r = 0; r < k; r++) {
        int temp = arr[n - 1];
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }


    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    //{1,2,3,4,5,6} k = 3
}
