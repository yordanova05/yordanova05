// zapisva v dvoichen fail 20 chisla, potrebitelq vuvejda koe ot tezi chisla iska da vidi, fseek() za konkretno chislo ot faila
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    int num;

    fp = fopen("file2","wb");

    if ( fp == NULL ){
        printf("Error!");
        exit(1);
    }
    for (int i = 0; i < 20; i++){
        scanf("%d", &num);
        fwrite(&num,sizeof(int),1,fp);
    }

    fclose(fp);

    fp = fopen("file2", "rb");

    int index;
    printf("Koi index iskash da vidish: ");
    scanf("%d",&index);

    fseek(fp, (index-1)*sizeof(int),SEEK_SET);

    fread(&num,sizeof(int),index,fp);
    printf("%d", num);

}
