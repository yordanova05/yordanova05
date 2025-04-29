// ukazatel - adres
// <tip> *<ime na promenliva>;
// int *p,*s, *l;
// referencirane & - vzema adresa
// dereferencirane * - izvleche stoinostta na ukazatelq
// int m = 6;
// int *p;
// p = &m;
//*p++;

//definirame ukazatel kum char edin int i edin double s tri promenrlivi i sushtite promenlivi i nasochvame pointeri kum
//suotvetnite promenlivi, posredstvom ukazateli da zapishem stoinosti na promenlivite i printirame stoinostite na pointerite i adresite na promenlivite

#include <stdio.h>

int main(){
    char *c;
    int *i;
    double *d;
    int in ;
    char ch ;
    double db;

    scanf("%c %d %lf",&ch, &in, &db);

    c = &ch;
    i = &in;
    d = &db;

    printf("adres: %p\n",c);
    printf("adres: %p\n",(int*)i);
    printf("adres: %p\n",(void*)d);

    printf("stoinost: %c\n",ch);
    printf("stoinost: %d\n",in);
    printf("stoinost: %lf\n",db);

    printf("stoinost: %c\n",*c);
    printf("stoinost: %d\n",*i);
    printf("stoinost: %lf\n",*d);

    printf("adres: %p\n",&c);
    printf("adres: %p\n",&i);
    printf("adres: %p\n",&d);

}

