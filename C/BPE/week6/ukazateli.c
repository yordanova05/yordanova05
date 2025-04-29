#include <stdio.h>

int main(){
    short int a;
    char *x;
    x = (char*)&a;
    a = 512;
    x[0] = 1;
    x[1] = 2;
    printf("%d",a);


int my_arr[10];
int *my_arr1 = &my_arr;
printf("%d", (void*)my_arr1);
}
