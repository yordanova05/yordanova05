#include<stdio.h>

int main(){
    // stdlib.h - vrushtat VOID

    //malloc (broi baitove) -- ako neuspeshno e zadelena pametta vrushta NULL

    int *p;
    p = malloc(3*sizeof(int));  // shte vurne blok s pamet 12byta

    //calloc (broi na elementite, razmer v bytove za 1 element) - zadelq broq elementi pootdelno a ne kato malloc edin cql
    // ELEMENTITE SHTE BUDAT ZANULIRANI - 0, ako ne se zapulnqt vrushta NULL

    // realloc (stariq adres, noviq razmer v bytove) -- vrushta pointer -- (pravi copie na masiva i osvobojdava stariq masiv)

    // free (adresa/imeto na blocka pamet) -- osvobojdava cqlata pamet koqto e bila zadelenq predi tova s drugite funkcii

}
