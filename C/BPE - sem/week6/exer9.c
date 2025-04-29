#include<stdio.h>
int main(){
    double x, y, z;
    printf("plosht kvadratni metra: ");
    scanf("%lf",&x);
    printf("kilograma grozde na kv. metur: ");
    scanf("%lf",&y);
    printf("jelano kolichestvo vino za prodan: ");
    scanf("%lf",&z);
    printf("broi rabotnici:");
    int n;
    scanf("%d", &n);
    double proizvodstvo_vino = x*0.4;

    double kilograma_grozde_obshto = proizvodstvo_vino*y;
    double litra_proizvedeno_vino = kilograma_grozde_obshto*2.5;
    double final_price = litra_proizvedeno_vino*5;

    if (litra_proizvedeno_vino >= z){
        printf("Imate dostatuchno kilograma vino!\n");
        printf("Proizvedeni litra vino: %.2lf\n", litra_proizvedeno_vino);
        printf("Ostavashto vino sled prodajbata: %.2lf\n",litra_proizvedeno_vino - z);
        printf("Izliza po %.2lf litra na chovek!\n", (litra_proizvedeno_vino - z)/n);
        printf("Izkarani pari: %.2lf",final_price);
    }
    else {
        printf("Nqmate dostatuchno kilograma vino!\n");
        printf("Proizvedeni litra vino: %.2lf, nujni litri vino: %.2lf\n", litra_proizvedeno_vino,z);
    }

}
