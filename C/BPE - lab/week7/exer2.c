#include<stdio.h>
#include<string.h>
// dva masiva ot tip char, chetem stoinost za ediniq niz, v drugiq masiv da ..strcpy., sled tova string concatination, strcmp, strlen

int main(){
    char str1[20];
    char str2[30];

    //scanf("%[^\n]", str1);
    fgets(str1, 20, stdin);
    puts(str1);

    strcpy(str2,str1);

    printf("1-%s\n",str1);
    printf("2-%s\n",str2);

    //fgets(str1, 20, stdin);

    strcat(str1,str2);

    printf("1-%s\n",str1);
    printf("2-%s\n",str2);

    printf("%d\n",strcmp(str1,str2));

    printf("%d\n",strlen(str1));

}
