// prochita se ot klaviaturata edno cqlo shislo i se printira ot conzolata ako chisloto e po-golqmo ot 30 ako e po-malko ot 30 drugo suobshtenie i pri ravno na 30
#include <stdio.h>

int main()  {
    int x;
    scanf("%d", &x);

    if (x > 30){
        printf("Chisloto e %d i po-golqmo ot 30!!!",x);
    }
    else if (x < 30){
        printf("Chisloto e %d i po-malko ot 30!!!",x);
    }
    else {
        printf("Chisloto e 30!!!");
    }
}
