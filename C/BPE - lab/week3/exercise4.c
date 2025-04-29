#include <stdio.h>

int main()  {
    int a;
    scanf("%d",&a);
    int l = a%10;
    int k = (a/10)%10;
    int j = (a/100)%10;
    int h = (a/1000)%10;
    printf("%d,%d,%d,%d\n",l,k,j,h);
    l = h + l;
    h = l - h;
    l = l - h;
    int x = l + k + j + h;
    printf("%d,%d,%d,%d",l,k,j,h);
    printf("Sum: %d", x);

    return 0;
}
