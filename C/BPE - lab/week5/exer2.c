#include <stdio.h>
void func1(int *x, int *y);

int main() {
    // funkciq za razmqna na dve chisla, poluchava dva argumenta dvete chilla, izvikvate funkciqta i demonstrirame rabotata i
    int a,b;
    scanf("%d %d", &a, &b);
    printf("a = %d, b = %d\n", a,b);
    func1(&a,&b);
    printf("a = %d, b = %d\n", a,b);

}

void func1(int *x, int *y){
    int temp = *y;
    *y = *x;
    *x = temp;

    /*x = x + y;
    y = x - y;
    x = x - y;
    */

    //printf("a = %d, b = %d\n", x,y);
}
