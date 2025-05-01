#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Picture{
    short int code;
    char author[31];
    char name[31];
    float price;
};

struct PictureFull{
    short int code;
    int authorlong;
    char author[31];
    int namelong;
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

    if ( count == 0){
        return 0;
    }
    else{
        return count;
    }
}

void PrintAuthoMatching(char authornew[31]){
    FILE *fp;
    int truee = 0;

    fp = fopen("picture.bin","rb");

    if ( fp == NULL ){
        printf("ERROR WHILE OPENING THE FILE!");
        exit(4);
    }

    fseek(fp, 0, SEEK_END);
    int bytes = ftell(fp);
    rewind(fp);

    int count = bytes/sizeof(struct PictureFull);

    struct PictureFull *picturesbin = (struct PictureFull*)malloc(count*sizeof(struct PictureFull));

    if ( picturesbin == NULL ){
        printf("ERROR WHILE SETTING DINAMIC MEMORY!");
        exit(5);
    }

    fread(picturesbin, count, sizeof(struct PictureFull), fp);

    for ( int i = 0; i < count; i++ ){
        if ( strcmp( picturesbin[i].author, authornew) == 0){
            printf("Picture title: %s\nPrice: %.2fBGN\n",picturesbin[i].name, picturesbin[i].price);
            truee++;
        }
    }
    if ( truee == 0 ){
        printf("PRICTURES NOT FOUND!");
    }
    fclose(fp);
}


