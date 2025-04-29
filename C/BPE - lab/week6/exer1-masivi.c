// <tip> <ime> [<razmer>]= {0}; vsichki stoinosti sa 0;
// <ime na masiv> [<index];
//*(array + i) - ukazatelna aritmetika
// p = &array[0] = array[i]
// <tip><ime>(<tip><ime na masiv>[<razmer>]){}
// <tip><ime>(<tip><ime na masiv>[]){}
// <tip><ime>(<tip>*<ukazatel>){}
// pri izvikvane na funkciq -> <ime na funkciq>(<ime na masiv>);

// scanf("%d",&array[0]);

// definirame edin celochislen masiv s 5 elementa, sled koeto chetem elementite na masiva, shte printirame masiva v obraten red
#include<stdio.h>

int main(){
    int arr[5];
    int x;
    for (int i = 0; i <= 4; i++){
        scanf("%d", &x);
        arr[i] = x;
    }
    for (int y = 4; y >=0; y--){
        printf("%d\n", arr[y]);
    }
}


