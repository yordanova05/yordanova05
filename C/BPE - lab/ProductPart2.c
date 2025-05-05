#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Product{
    char name[21];
    int code;
    char date[11];
    float price;
}Product;

float avrg_by_price( Product *products, int n, float newprice);
int write_text_file(Product *products, int n, char newdate[11], float newprice);
int print_info( char name[21], int code);

int main(){
    int n;

    while (n < 10 || n > 30){
        scanf("%d",&n);
        getchar();
    }

    Product *products = (Product*)malloc(n*sizeof(Product));
    if ( products == NULL ){
        printf("Error memory set!\n");
        exit(2);
    }

    for ( int i = 0; i < n; i++ ){
        printf("Name: ");
        fgets(products[i].name, sizeof(products[i].name), stdin );

        printf("Code: ");
        while( 1 ){
            scanf("%d", &products[i].code);
            getchar();
            if ( products[i].code > 99 && products[i].code < 1000 ){
                break;
            }
        }

        printf("Date (YYYY.MM.DD): ");
        fgets(products[i].date, sizeof(products[i].date), stdin );

        printf("Price: ");
        scanf("%f", &products[i].price);
        getchar();
    }

    float avrg = avrg_by_price(products, n, 50.0);
    int count = write_text_file(products,n, "2024.12.31", 70.0);
    print_info("Paracetamol", 123);

    return 0;
}

float avrg_by_price( Product *products, int n, float newprice){
    int count = 0;
    float sum = 0.0;

    for ( int i = 0; i < n; i++ ){
        if ( products[i].price < newprice){
            count++;
            sum+=products[i].price;
        }
    }

    if ( sum == 0){
        printf("No products under the price!\n");
        return sum;
    }
    else{
        return sum/count;
    }
}

int write_text_file(Product *products, int n, char newdate[11], float newprice){
    int count = 0;

    FILE *fp;
    fp = fopen("products.txt","w");

    if ( fp == NULL ){
        printf("Error opening file!\n");
        exit(2);
    }

    int endmonth, endyear, endday;
    int month, year, day;

    for ( int i = 0; i < n; i++ ){
        sscanf(products[i].date, "%d.%d.%d", &year,&month,&day);
        sscanf(newdate, "%d.%d.%d", &endyear, & endmonth, &endday);

        if( ((year == endyear && month < endmonth) || year < endyear) && products[i].price > newprice ){
            fprintf(fp, "%s-%d-%s-%f\n",products[i].name, products[i].code, products[i].date, products[i].price);
            count++;
        }
    }
    if ( !count ){
        return 0;
    }
    else{
        return count;
    }
}

int print_info( char name[21], int code){
    int SizeName = 0;

    Product values; // values type struct NOT A POINTER!

    FILE *fpb;
    fpb = fopen("products.bin","rb");
    if ( fpb == NULL ){
        printf("Error opening the file!");
        exit(3);
    }

    while(1){
        if ( feof(fpb) ) {
                break;
        }

        if ( fread( &SizeName, sizeof(int), 1, fpb) != 1){
            printf("Error!");
            fclose(fpb);
            exit(4);
        }

        if ( fread(&values.name, sizeof(char)*SizeName, 1, fpb) != 1){
            printf("Error!");
            fclose(fpb);
            exit(4);
        }
        values.name[SizeName] = '\0';

        if ( fread( &values.code, sizeof(int), 1, fpb) != 1){
            printf("Error!");
            fclose(fpb);
            exit(4);
        }

        if ( fread( &values.date, sizeof(char)*11, 1, fpb) != 1){
            printf("Error!");
            fclose(fpb);
            exit(4);
        }
        values.date[11] = '\0';

        if ( fread( &values.price, sizeof(float), 1, fpb) != 1){
            printf("Error!");
            fclose(fpb);
            exit(4);
        }
        if ( values.code == code && strcmp(values.name, name) == 0 ){
            printf("Name: %s - eat before %s - price %.2flev\n", values.name, values.date, values.price);
            fclose(fpb);
            return 1;
        }
    }
    printf("Products not found!");
    fclose(fpb);
    return 0;
}
