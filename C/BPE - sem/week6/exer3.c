#include<stdio.h>
int equal(int x, int y, int z);

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    char result = equal(a,b,c);
    if (result == 1){
        printf("YES!");
    }
    else {
        printf("NO!");
    }
}
int equal(int x, int y, int z){
    if (x == y && y == z && z == x){
        return 1;
    }
    else{
        return 0;
    }
}
