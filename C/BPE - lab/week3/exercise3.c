#include <stdio.h>;

int main()  {
    int a,b;
    scanf("%d%d", &a, &b);
    printf("a = %d, b = %d\n", a,b);
    /* 10 5 */
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d, b = %d\n", a,b);
    return 0;

}
