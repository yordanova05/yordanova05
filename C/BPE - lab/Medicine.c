#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine{
    char name[31];
    char date[8];
    char code[14];//long long code;
    float price;
    int quantity;
};



struct Medicine* BeforeDate(struct Medicine *medicines,int count, char date1[8]);
int WrittenValues(struct Medicine *medicines, int count, float minimum, float maximum);
void DeleteMedicine(struct Medicine **medicines, int *count, char name1[50], char date1[8]);

// 1 - zadacha

int main(){
    FILE *fp;

    fp = fopen("medicines.bin", "rb");
    if ( fp == NULL ){
        printf("ERROR!");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int medicinesCount = ftell(fp);
    rewind(fp);

    int count = medicinesCount/sizeof(struct Medicine);
    struct Medicine* medicines = (struct Medicine*)malloc(count*sizeof(struct Medicine));
    if ( medicines == NULL ){
        printf("ERROR!");
        return 2;
    }

    fread(medicines, sizeof(struct Medicine), count, fp);

    for ( int i = 0; i < count; i++ ){
        printf("%s", medicines[i].name);
        printf("%s", medicines[i].date);
        printf("%s", medicines[i].code);
        printf("%f", medicines[i].price);
        printf("%d", medicines[i].quantity);
    }

    struct Medicine* resultfordate = BeforeDate(medicines, count, "12.2025");
    WrittenValues(medicines, count, 15.00, 50.00);
    DeleteMedicine(&medicines, &count, "Analgin", "12.2026");

    fclose(fp);
    free(medicines);


}

// 2 - zadacha

struct Medicine* BeforeDate(struct Medicine* medicines, int count, char date1[8]){
    int month, year,newmonth, newyear;

    sscanf(date1, "%d.%d", &newmonth, &newyear);
    struct Medicine *result = (struct Medicine*)malloc(count*sizeof(struct Medicine));

    if ( result == NULL ){
        printf("DIDN'T SET DINAMIC MEMORY!");
        exit(3);
    }

    int resultcount = 0;

    for ( int i = 0; i < count; i++ ){
        sscanf(medicines[i].date, "%d.%d",&month, &year);
        if ( newyear > year || (newyear == year && newmonth > month)){
            result[resultcount++] = medicines[i];
        }
    }

    struct Medicine *medicinesnew = (struct Medicine*)realloc(result,resultcount*sizeof(struct Medicine));

    if ( medicinesnew == NULL ){
        printf("DIDN'T SET DINAMIC MEMORY!");
        exit(4);
    }

    if ( resultcount == 0){
        free(result);
        free(medicinesnew);
        return NULL;
    }
    else{
        return medicinesnew;
    }

}

// 3 - zadacha

int WrittenValues(struct Medicine *medicines, int count, float minimum, float maximum){
    FILE *file;

    file = fopen("offer.txt","w");
    if ( file == NULL ){
        printf("ERROR!");
        exit(3);
    }

    int values = 0;
    for ( int i = 0; i < count; i++ ){
        if ( medicines[i].price <= maximum && medicines[i].price >= minimum ){
            values++;
                fprintf(file, "%s\n", medicines[i].name);
                fprintf(file, "%s\n", medicines[i].date);
                fprintf(file, "%s\n", medicines[i].code);
                fprintf(file, "%.2fleva\n", medicines[i].price);
                fprintf(file, "%d\n", medicines[i].quantity);
        }
    }

    fclose(file);
    return values;
}

// 4 - zadacha

void DeleteMedicine(struct Medicine **medicines,int *count, char name1[50], char date1[8]){
    int newcount = *count;
    for ( int i = 0; i < *count; i++ ){
        if (strcmp((*medicines)[i].name, name1) == 0 && strcmp((*medicines)[i].date, date1) == 0){
            for ( int y = i; y < *count-1; y++){
                (*medicines)[y] = (*medicines)[y + 1];
            }
            newcount--;
            break;
        }
    }
    if ( newcount < *count ){
        struct Medicine *temp = realloc(*medicines,(newcount)*sizeof(struct Medicine));
        if ( temp == NULL ){
            printf("DIDN'T SET DINAMIC MEMORY!");
            return ;
        }
        printf("Succesfully deleted medicine!");
        *medicines = temp;
        *count = newcount;
    }
    else{
        printf("Medicine not found!");
    }
}


