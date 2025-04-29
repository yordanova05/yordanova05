// funkciq namirashta duljinata na niz, koqto namira dukjinata na niza bez strlen
#include<stdio.h>
int len_string(char str1[]);
//ili izpolzvam char *str; ili char str[];

int main(){
    char str1 [30];
    scanf("%[^\n]",str1);
    //fgets(str1, 30, stdin);
    //puts(str1);
    printf("duljina na niza: %d",len_string(str1));
}

int len_string(char str1[]){
    int count = 0;
    for (int i = 0; str1[i]!= '\0' ;i++){
        count++;
    }
    return count;

    /*while(str1[count] != '\0'){
        count++;
    }
    return count;*/
}
