/*  <stdio.h>
    1) otvarqne na fail i asociiraneto mu s potoka
        - FILE* = fopen(<faila>,<vid na dostup>) -> vrushta failov ukazatel (ako e neuspeshno vrushta NULL)
                            "r","w","a","r+","w+","a+"- tekstov fail
                            "rb",""wb","ab","rb+","wb+","ab+"- dvoichen fail
                            pri "w" - se trie sudurjanieto

    2) funkcii za chetene byte po byte
        int fgetc(<prototip na funkciq(FILE *fp)>) - chete byte po byte info ot fail
        int fputc(int ch, FILE *fp) - zapisva byte po byte info ot fail

        int feof(FILE *fp) - kogato ne e stignat kraq na faila vrushta nenuleva stoinost!
        int ferror(FILE *fp) - ako vuznikne greshka vrushta nenuleva stoinost!

        #chetene na fail cql a ne byte po byte
        fgets(<ime na niz>,<razmera>,FILE *fp) - vrushta niza ako e uspeshno, ako ne e uspeshno vrusta NULL!
        fputs(<niz>,FILE *fp) - zapisva se niza v dadeniq fail!

        #chetene na danni s razlichen tip
        fprintf(FILE *fp,"gotov niz", argumenti) - zapisva vuv fail
        fscanf(FILE *fp, "....",argument) - vzema tekst i go preobrazuva v zadadenoto v argumenta MAI

        #rabotqt v binaren rejim!!!!!!
        (size.t - tip danni )
        fread(void *adresa, size.t size, size.t num, FILE *fp) - chete ot failoviq ukazatel FILE *fp num na broi, s razmer size, ot adresa
        fwrite(void *adresa, size.t size, size.t num, FILE *fp) - zapisva ot failoviq ukazatel FILE *fp num na broi, s razmer size, ot adresa
        (I DVETE )

        fseek(FILE *fp, long <vid otmestvane>, <nachalo>) - okazva poziciqta na buffera

        VIDOVE OTMESTVANIQ <nachalo>:
        SEEK_SET -> nachalo
        SEEK_CUR -> tekushta poziciq
        SEEK_END -> otkraq

        ftell(FILE *fp) - vrushta chislo na tekushtata poziciq kato broi baitove

        rewind(FILE *fp) - vrushta faila v nachaloto

        int fflush(FILE *fp) - izchistva buffera na faila


    3) fclose(ukazatel)
        - fclose(FILE *fp) - funkciqta vrushta makros fail - EOF - vrushta 1 ako uspeshno e zatvoren!


    PRIMER:

    */
    #include<stdio.h>
    #include<stdlib.h>

    int main(){
        FILE *fp;
        fp = fopen("myfile.txt","wb");
        if (fp == NULL){
            printf("Error!");
            exit(1);
        }
        int x = 243;
        if (fwrite(&x, sizeof(int), 1, fp) != 1){
            printf("Error!");
            exit(2);
        }
        fclose(fp);
        fp = fopen("myfile.txt", "rb");
        int num;
        if(fread(&num, sizeof(int),1,fp) != 1){
            printf("Error!");
            exit(3);
        }
        printf("num is %d\n",num);
    }




