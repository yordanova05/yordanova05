#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct IceCream{
    char code[3];
    char name[21];
    int kg;
    float price;
};

struct IceCream2{
    char code[3];
    int namelong;
    char name[21];
    int kg;
    float price;
};

float MatchingFirstLetter(struct IceCream *sklad, int n, char a);
int AddingToFile(struct IceCream *sklad, int n, float newprice, int newkg);
void ReturnIceCream(char code1[3]);

int main(){
    int n;
    while (1){
        scanf("%d",&n);
        getchar();
        if ( n > 5 && n < 15 ){
            break;
        }
    }

    struct IceCream *sklad = (struct IceCream*)malloc(n*sizeof(struct IceCream));

    if ( sklad == NULL ){
        printf("DIDN'T SET DINAMIC MEMORY!");
        exit(1);
    }

    for ( int i = 0; i < n; i++ ){
        printf("Code: ");
        scanf("%[^\n]", &sklad[i].code);
        getchar();

        printf("Name: ");
        scanf("%[^\n]", &sklad[i].name);
        getchar();

        printf("Kilograms: ");
        scanf("%d", &sklad[i].kg);
        getchar();

        printf("Price: ");
        scanf("%f",&sklad[i].price);
        getchar();
    }

    float result = MatchingFirstLetter(sklad, n, 'C');
    printf("Amount price for icecreams starting with letter C: %f\n", result);

    int count = AddingToFile(sklad, n, 10.50, 50);
    printf("Added %d to the file!\n", count);

    ReturnIceCream("A4");

    free(sklad);
    return 0;

}


float MatchingFirstLetter(struct IceCream* sklad, int n, char a){
    float result = 0.0;

    for ( int i = 0; i < n; i++ ){
        if (sklad[i].name[0] == a){
            result += sklad[i].price;
        }
    }
    if ( result == 0 ){
        return 0;
    }
    else{
        return result;
    }
}

int AddingToFile(struct IceCream *sklad, int n, float newprice, int newkg){
    FILE *fp;
    int count = 0;

    fp = fopen("info.txt","a");

    if ( fp == NULL ){
        printf("ERROR WHILE OPENING THE FILE!");
        exit(3);
    }

    for ( int i = 0; i < n; i++ ){
        if ( sklad[i].price < newprice && sklad[i].kg > newkg ){
            count++;
            fprintf(fp, "Code: %s; Name: %s; Price: %.2fleva; Kg: %d;",sklad[i].code, sklad[i].name, sklad[i].price, sklad[i].kg);
        }
    }
    fclose(fp);
    if ( count != 0 ){
        return count;
    }
    else{
        return 0;
    }
}

void ReturnIceCream(char code1[3]){
    FILE *fp;
    int truee = 0;

    fp = fopen("icecream.bin", "rb");

    if ( fp == NULL ){
        printf("ERROR WHILE OPENING THE FILE!");
        exit(4);
    }

    fseek(fp, 0, SEEK_END);
    int result = ftell(fp);
    rewind(fp);

    int count = result/sizeof(struct IceCream2);

    struct IceCream2 *skladbin = (struct IceCream2*)malloc(count*sizeof(struct IceCream2));

    if ( skladbin == NULL ){
        printf("ERROR WHILE SETTING DINAMIC MEMORY!");
        exit(5);
    }

    fread(skladbin,sizeof(struct IceCream), count, fp);

    for ( int  i = 0; i < count; i++ ){
        if ( strcmp( skladbin[i].code, code1) == 0 ){
            printf("Founded icecream with code: %s; len: %d; name: %s; kg: %d; price: %f",
                   skladbin[i].code, strlen(skladbin[i].name), skladbin[i].name, skladbin[i].kg, skladbin[i].price);
            truee = 1;
        }
    }
    if ( truee == 0 ){
        printf("NOT FOUNDED ICECREAMS WITH THAT CODE!");
    }
    fclose(fp);
    free(skladbin);

}




