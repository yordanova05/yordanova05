// za knigi , vsqka kniga ima zaglavie, avtor, godina na izdavane i cena, da se realizirat otdelni funkcii
// za VUVEJDANE NA INFORMACIQ ZA KNIGITE
// za ZA IZVEJDANE NA INFORMACIQ ZA VSICHKI KNIGI SLED 2005 GODINA
// za TURSENE NA KNIGI PO IME NA AVTOR

#include<stdio.h>
#include<string.h>

struct Book{
    char title[20];
    char autor[20];
    int year;
    float price;
};

int input( struct Book books[3]){
    for (int i = 0; i < 3; i++){
        printf("ime na kniga[%d]: ",i+1);
        scanf(" %[^\n]",books[i].title);

        printf("autor na kniga[%d]: ",i+1);
        scanf(" %[^\n]",books[i].autor);

        printf("godina na izdavane na kniga[%d]: ",i+1);
        scanf("%d",&books[i].year);

        printf("cena na kniga[%d]: ",i+1);
        scanf("%f",&books[i].price);
    }
    return 0;
}

int after2005( struct Book books[3]){
    for (int i = 0; i < 3; i++){
        if( books[i].year >= 2005){
            printf("MACHING BOOKS AFTER 2005!\n");
            printf("ime na kniga[%d]: %s\n",i+1,books[i].title);

            printf("autor na kniga[%d]: %s\n",i+1, books[i].autor);

            printf("godina na izdavane na kniga[%d]: %d\n",i+1, books[i].year);

            printf("cena na kniga[%d]: %f\n",i+1, books[i].price);
        }
    }
    return 0;
}

int machingautor( struct Book books[3], char nameautor[20]){
    for (int i = 0; i < 3; i++){
        if( strcmp(books[i].autor, nameautor)==0){
            printf("MACHING WITH AUTOR!\n");
            printf("ime na kniga[%d]: %s\n",i,books[i].title);

            printf("autor na kniga[%d]: %s\n",i, books[i].autor);

            printf("godina na izdavane na kniga[%d]: %d\n",i, books[i].year);

            printf("cena na kniga[%d]: %f\n",i, books[i].price);
        }
    }
    return 0;
}

int main(){
    struct Book books[3];

    char nameautor[20];

    input(books);
    after2005(books);
    printf("\nAutor for matching:");
    scanf(" %[^\n]", nameautor);
    machingautor(books,nameautor);

    return 0;
}
