#include <stdio.h>

int main(){
    float n,m,dolar;
    printf("Broi dni v meseca: ");
    scanf("%f", &n);
    printf("Dolara na den: ");
    scanf("%f", &m);
    printf("Dolar price: ");
    scanf("%f", &dolar);

    float rabotni_dni_za_godina = n*12;
    float bonus = m*12*2.5;
    float izkarani_dolari = n*m*12;

    float chista_godishna_zaplata = izkarani_dolari+bonus;

    float year_salary_dolar = (chista_godishna_zaplata)*0.75;
    printf("In dolar: %.2f\n", year_salary_dolar);
    printf("In lev: %.2f\n", year_salary_dolar*dolar);
    printf("Income in day: %.2f\n", (year_salary_dolar*dolar)/365);


}
