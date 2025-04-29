// fputs i fgets(), programata chete 5 niza ot potrebitelq i gi zapisva vuv fail, chete gi ot faila i gi printira na konzolata
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    fp = fopen("file1","w");
    if (fp == NULL){
        printf("Error!");
        exit(1);
    }

    char string1 [50];
    for( int i = 0; i < 5; i++){
        printf("string[%d] = ", i+1);
        fgets(string1, 50, stdin); // po podrazbirane slaga na nov red!!!
        fputs(string1, fp);
    }

    fclose(fp);

    fp = fopen("file1","r");

    if ( fp == NULL){
        printf("ERROR!");
        exit(2);
    }

    for (int i = 0; i < 5; i++){
        fgets(string1, 50, fp);
        printf("%s",string1);
    }

    fclose(fp);










}
