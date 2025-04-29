//calculator
#include <stdio.h>

int main(){
    char op;
    int x, y, c;
    scanf("%d %d %d", &x, &y, &op);

    switch (op){
        case '+':
        c = x+y;
        printf("%d\n",c);
        break;

        case '-':
        c = x-y;
        printf("%d\n",c);
        break;

        case '*':
        c = x*y;
        printf("%d\n",c);
        break;

        case '/':
        c = x/y;
        if ( y == 0){
            printf("Ne se deli na 0!!!");
        }
        printf("%d\n",c);
        break;
    }
}


