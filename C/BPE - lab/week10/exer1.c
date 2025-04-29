// structura po nash izbor, promenliva ot tozi tip, shte prochetem stoinosti za tazi promenliva ot klaviaturata,
// printirame informaciq za tazi promenliva

// def masiv ot tip structura masiv, sled tova zapulvame stoinostite s elementite ot masiva ot conzolata, shte izvedem
// stoinostite ot edno ot poletata na masiva zapochvaiko ot kraq na masiva


#include<stdio.h>
typedef struct Animal{
    char animalNames[30];
    char breed[20];
    int age;
}animal;

int main(){

    struct Animal animal1;
    printf("Names: ");
    scanf("%[^\n]",&animal1.animalNames);
    int countNames = sizeof(animal1.animalNames)/sizeof(animal1.animalNames[0]);

    printf("Breed: ");
    scanf("%s",&animal1.breed);

    printf("Age: ");
    scanf("%d",&animal1.age);

    //printf("Animal name: %s, breed: %s, age: %d",animal1.animalNames, animal1.breed, animal1.age);

    printf("Animal name in reverse order: ");
    for (int i = countNames - 1; i >= 0; i--) {
        printf("%c", animal1.animalNames[i]);
    }
    printf("\n");
}
