#include<stdio.h>
#include<string.h>
int len_words(char *str1);
int main(){
    char str1 [20];
    scanf("%[^\n]",str1);
    printf("broi dumi: %d", len_words(str1));
}
int len_words(char *str1){
    int count = 0;
    int i = 0;
    while(str1[i]!= '\0'){
        if ((str1[i] != ' ' && str1[i+1] == ' ') || str1[i] != ' ' && str1[i+1] == '\0'){
            count++;
        }
        i++;
    }
    return count;
}
/////VIIIIIIIIIIIIIIIIIIIIIJ!!!
