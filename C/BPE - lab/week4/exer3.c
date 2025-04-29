// vuvejda cqlo chislo na konzolata shte se printira suobshtenie kogato ostatukut ot delenie s 8 na tova chislo > 4;
#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    if (x % 8 > 4 ){
        printf("Ostatukut e raven na %d!\n", x%8);
    }
    else{
        printf("Error");
    }

// vuvejda 4 chisla i printira nai-malkoto;
    int y,u,i,o;
    scanf("%d %d %d %d", &y,&u,&i,&o);
    if (y < u && y < o && y < i){
        printf("Nai-malkoto chislo e: %d", y);
    }
    else if (u < y && u < o && u < i){
        printf("Nai-malkoto chislo e: %d", u);
    }
    else if (i < y && i < u && i < o){
        printf("Nai-malkoto chislo e: %d", i);
    }
    else{
        printf("Nai-malkoto chislo e: %d", o);
    }
}
