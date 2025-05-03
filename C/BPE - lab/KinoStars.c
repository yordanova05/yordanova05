#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Star{
    char name[51];
    int age;
    char country[31];
    float incomes;
    int oscars;
};

int count = 0;

void AddNewArtist(struct Star **stars);
struct Star* ReturnCertainIncomeArtistArray(struct Star *stars, long int income);
struct Star* WrittenTextfile(char namefile[50]);

int main(){

    struct Star *stars = NULL;

    AddNewArtist(&stars);
    struct Star *startsincomesover = ReturnCertainIncomeArtistArray(stars, 2000000);

    struct Star* values = WrittenTextfile("stars.txt");

}


void AddNewArtist(struct Star **stars){
    count++;

    struct Star *newstars = realloc(*stars,count*sizeof(struct Star));

    if ( newstars == NULL ){
        count--;
        printf("ERROR WHYLE SETTING DINAMIC MEMORY");
        exit(1);
    }

    printf("Name: ");
    fgets(newstars[count-1].name, sizeof(newstars[count-1].name),stdin);

    printf("Age: ");
    scanf("%d", &newstars[count-1].age);
    getchar();

    printf("Country: ");
    fgets(newstars[count-1].country, sizeof(newstars[count-1].country),stdin);

    printf("Incomes: ");
    scanf("%f", &newstars[count-1].incomes);
    getchar();

    printf("Oscars: ");
    scanf("%d", &newstars[count-1].oscars);
    getchar();

    *stars = newstars;
}

struct Star* ReturnCertainIncomeArtistArray(struct Star *stars, long int income){
    int newcount = 0;

    for (int i = 0; i < count; i++ ){
        if ( stars[i].incomes > income ){
            newcount++;
        }
    }

    struct Star *newstars = malloc(newcount*sizeof(struct Star));
    if ( newstars == NULL ){
        printf("ERROR WHYLE SETTING DINAMIC MEMORY!");
        exit(1);
    }
    int j = 0;

    for ( int i = 0; i < count; i++ ){
        if ( stars[i].incomes > income ){
            strcpy( newstars[j].name, stars[i].name);
            strcpy( newstars[j].country, stars[i].country);
            newstars[j].age = stars[i].age;
            newstars[j].incomes = stars[i].incomes;
            newstars[j].oscars = stars[i].oscars;
            j++;
        }
    }

    return newstars;
}

struct Star* WrittenTextfile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int capacity = 10;
    int read_count = 0;

    struct Star *stars = malloc(capacity * sizeof(struct Star));
    if (stars == NULL) {
        printf("ERROR WHYLE SETTING DINAMIC MEMORY!\n");
        fclose(fp);
        exit(2);
    }

    while (fgets(stars[read_count].name, sizeof(stars[read_count].name), fp)) {
        stars[read_count].name[strcspn(stars[read_count].name, "\n")] = 0;

        fscanf(fp, "%d\n", &stars[read_count].age);
        fgets(stars[read_count].country, sizeof(stars[read_count].country), fp);
        stars[read_count].country[strcspn(stars[read_count].country, "\n")] = 0;

        fscanf(fp, "%f\n", &stars[read_count].incomes);
        fscanf(fp, "%d\n", &stars[read_count].oscars);

        (read_count)++;

        if (read_count >= capacity) {
            capacity *= 2;
            stars = realloc(stars, capacity * sizeof(struct Star));
            if (stars == NULL) {
                printf("ERROR WHYLE SETTING DINAMIC MEMORY!\n");
                fclose(fp);
                exit(3);
            }
        }
    }

    fclose(fp);
    return stars;
}
