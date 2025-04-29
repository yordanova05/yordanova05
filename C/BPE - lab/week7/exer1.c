#include <stdio.h>
#include <string.h>

int main(){
    char string[30];
    scanf("%s",string);
    scanf("%[^\n]",string); // chete vsichki simvoli osven \n - noviq red
    fgets(<ime na stringa>, <golemina na stringa>,stdin);// pri rabota s failove, no moje da chete i ot standartniq vhod
    // stdin - chete ot standartniq vhod, a inache e za texxstovi failove
    char string2[30] = "Obicham palachinki";
    char string3 = {'a', 'b', 'c','\0'};

    //strcpy(<niz1>,<niz2); // kopira se vtoriq masiv vuv purviq niz
    //strcat(<niz1>, <niz2>); // dolepq niz2 do niz1 (trqbva niz1 da moje da pobere niz2)
    //strcmp(<niz1>, <niz2>) // sravnqva nizovete ako niz1 e po-golqm ot niz2 vrushta 1, ako e po-maluk -1, ako e raven 0
    //strlen(<niz1>) // vrushta duljina na niza kolko simvola ima
    //sizeof(<niz>) // vrushta goleminata na bufera na niza [20]

    char *p = string2;
    char *p = string2;

}
