//failove
// texstovi i binarni
#include<stdio.h>
int main(){
    char myChar [20];
    FILE *fp = fopen("example.txt", 'w');

    if (fp == NULL){
        return 1;
    }

    fprint(fp, "ivan\sofia"); // pishe text v faila

    while((ch == fgets(fp))!= '\\'){

    }

    fclose(fp);

    fp = fopen("example.txt", 'r');

    fgets(myChars, 20, fp);

    printf(myChars);
    return 0;
}

