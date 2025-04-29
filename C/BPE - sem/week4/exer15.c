#include <stdio.h>

int main(){
    int n,w,l,m,o;
    printf("Razmer na ploshtadkata: ");
    scanf("%d",&n);
    printf("Razmer na plochkata: ");
    scanf("%d %d",&w,&l);
    printf("Razmer na peikata: ");
    scanf("%d %d",&m,&o);

    float peika_plosht = m*o;
    float area = n*n - peika_plosht;
    float broi_plochki = area/(w*l);
    float time = broi_plochki*0.2;
    printf("Shte slojite %f plochki za %f minuti vreme!", broi_plochki, time);

}
