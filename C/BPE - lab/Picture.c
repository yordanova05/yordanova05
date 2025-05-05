#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Picture{
    short int code;
    char author[31];
    char name[31];
    float price;
};

float AveragePrice(struct Picture *pictures, int n, float newprice);
int WrittenValues(struct Picture *pictures, int n, char a);
void PrintAuthoMatching(char authornew[31]);

int main(){
    int n;

    while (1){
        scanf("%d",&n);
        if ( n > 3 && n < 30){
            break;
        }
    }

    struct Picture *pictures = (struct Picture*)calloc(n, sizeof(struct Picture));

    if ( pictures == NULL ){
        printf("ERROR WHILE SETTING DINAMIC MEMORY!");
        exit(1);
    }

    for ( int i = 0; i < n; i++ ){

        printf("Code: ");
        scanf("%hd",&pictures[i].code);
        getchar();

        printf("Author: ");
        fgets(pictures[i].author, sizeof(pictures[i].author), stdin);
        pictures[i].author[strcspn(pictures[i].author, "\n")] = 0;

        printf("Name: ");
        fgets(pictures[i].name, sizeof(pictures[i].name), stdin);
        pictures[i].name[strcspn(pictures[i].name, "\n")] = 0;

        printf("Price: ");
        scanf("%f",&pictures[i].price);

    }

    float average = AveragePrice(pictures, n, 50.0);
    printf("Average price for pictures over 50 leva: %f\n", average);

    int countWrittenValues = WrittenValues(pictures, n, 'M');
    printf("%d pictures written into file info.txt\n", countWrittenValues);


    PrintAuthoMatching("Picaso");

    return 0;
}

float AveragePrice( struct Picture *pictures, int n, float newprice){
    int count = 0;
    float sum = 0.0;

    for ( int i = 0; i < n; i++ ){
        if ( pictures[i].price > newprice){
            count ++;
            sum += pictures[i].price;
        }
    }

    if ( count == 0 ){
        return 0;
    }
    else{
        return sum/count;
    }
}

int WrittenValues( struct Picture *pictures, int n, char a){
    int count = 0;

    FILE *fp;

    fp = fopen("info.txt","w");

    if ( fp == NULL ){
        printf("ERROR WHILE OPENING THE FILE!");
        exit(2);
    }

    for ( int i = 0; i < n; i++ ){
        if ( pictures[i].author[0] == a ){
            count++;
            fprintf(fp, "%d;%s;%fleva;",pictures[i].code, pictures[i].name, pictures[i].price);
        }
    }

    fclose(fp);

    if ( count == 0){
        return 0;
    }
    else{
        return count;
    }
}

void PrintAuthoMatching(char authornew[31]){
    FILE *fp;

    fp = fopen("picture.bin","rb");

    if ( fp == NULL ){
        printf("ERROR WHILE OPENING THE FILE!");
        exit(4);
    }

    struct Picture picturesbin;
    int sizeauthor = 0, sizename = 0;

    while ( fread(&picturesbin.code, sizeof(short int), 1 , fp)){
        if ( feof(fp) )break;

        if ( fread(&sizeauthor, sizeof(int), 1, fp) != 1){
            exit(4);
        }

        if ( fread(&picturesbin.author, sizeof(char)*sizeauthor, 1, fp) != 1){
            exit(4);
        }
        picturesbin.author[sizeauthor] = '\0';

        if ( fread(&sizename, sizeof(int), 1, fp) != 1){
            exit(4);
        }

        if( fread(&picturesbin.name, sizeof(char)*sizename, 1, fp) != 1){
            exit(4);
        }
        picturesbin.name[sizename] = '\0';

        if ( fread(&picturesbin.price, sizeof(float), 1, fp) != 1){
            exit(4);
        }

        if ( strcmp( picturesbin.author, authornew) == 0){
            printf("Picture title: %s\nPrice: %.2fBGN\n",picturesbin.name, picturesbin.price);
        }
    }

    fclose(fp);
}


