#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= n/2; i++){
        arr[i-1] = arr[i-1] + arr[n-i];
        arr[n-i] = arr[i-1] - arr[n-i];
        arr[i-1] = arr[i-1] - arr[n-i];
    }

    for(int i = 0; i<n; i++){
        printf("%d", arr[i]);
    }
}
//{1,2,3,4,5}
// x = x + y
// y = x - y
// x = x - y

