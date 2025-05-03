#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Product{
    char name[31];
    int code;
    char date[11];
    float price;
};

int count = 0;

void Adding(struct Product **products);
struct Product* HigherPrice(struct Product *products, float newprice);
void WrittenValues(struct Product *products);

int main(){
    struct Product* products = NULL;

    FILE *fp;
    fp = fopen("in.bin","wb");
    if ( fp == NULL ){
        printf("ERROR WHYLE CREATING THE FILE!");
        exit(1);
    }
    fclose(fp);

    Adding(&products);

    struct Product *newproducts = HigherPrice(products, 100.0);
    WrittenValues(products);

}

void Adding(struct Product **products){
    count++;
    FILE *fp = fopen("in.bin","ab");

    if ( fp == NULL ){
        printf("ERROR WHYLE OPENING THE FILE!");
        count--;
        exit(1);
    }

    struct Product *newproducts = (struct Product*)realloc(*products,count*sizeof(struct Product));

    if ( newproducts == NULL ){
        printf("ERROR WHYLE SETTING DINAMIC MEMORY!");
        exit(2);
    }

    printf("Code: ");
    scanf("%d", &newproducts[count-1].code);
    getchar();

    printf("Name: ");
    fgets(newproducts[count-1].name, sizeof(newproducts[count-1].name), stdin);

    printf("Date: ");
    fgets(newproducts[count-1].date, sizeof(newproducts[count-1].date),stdin);

    printf("Price: ");
    scanf("%f",&newproducts[count-1].price);
    getchar();

    if ( fwrite(&newproducts[count-1], sizeof(newproducts[count-1]), 1, fp) != 1){
        printf("ERROR WHILE WRITING IN THE FILE!");
    }

    *products = newproducts;
    fclose(fp);
}

struct Product* HigherPrice(struct Product* products, float newprice){
    int newcount = 0;

    for( int i = 0; i < count; i++ ){
        if ( products[i].price > newprice ){
            newcount++;
        }
    }

    struct Product *newproducts = (struct Product*)calloc(newcount, sizeof(struct Product));

    if ( newproducts == NULL ){
        printf("ERROR WHYLE SETTING DINAMIC MEMORY!");
        exit(1);
    }

    int j = 0;

    for ( int i = 0; i < count; i++ ){
        if ( products[i].price > newprice ){
            newproducts[j].code = products[i].code;
            strcpy( newproducts[j].name, products[i].name );
            strcpy( newproducts[j].date, products[i].date );
            newproducts[j].price = products[i].price;
            j++;
        }
    }

    return newproducts;
}

void WrittenValues(struct Product* products){
    FILE *fileb = fopen("in.bin", "rb");

    if ( fileb == NULL ){
        printf("ERROR WHYLE OPENING THE FILE!");
        exit(1);
    }

    FILE *file = fopen("out.txt","w");

    if ( file == NULL ){
        printf("ERROR WHYLE OPENING THE FILE!");
        exit(2);
    }

    struct Product *product = malloc(count * sizeof(struct Product));
    fread(product, sizeof(struct Product),count, fileb);

    for ( int i = 0; i < count; i++ ){
        fprintf(file, "%d\n%s\n%s\n%f\n", products[i].code,products[i].name,products[i].date,products[i].price);

        printf("TEXT: \n%d\n%s\n%s\n%f\n", products[i].code,products[i].name,products[i].date,products[i].price);
        printf("BINARY: \n%d\n%s\n%s\n%f\n", product[i].code,product[i].name,product[i].date,product[i].price);
    }

    free(product);
    fclose(fileb);
    fclose(file);
}
