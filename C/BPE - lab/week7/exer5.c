#include<stdio.h>
#include<string.h>

int main(){
    char str [30];

    char ch;
    scanf("%[^\n] %c",str,&ch);

    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ch){
            count++;
        }
    }
    printf("kolko puti se sudurja znaka %c - %d\n",ch,count);
}
