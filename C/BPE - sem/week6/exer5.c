#include<stdio.h>

int main(){
    int sec1, sec2, sec3;
    scanf("%d %d %d", &sec1, &sec2, &sec3);
    int result = sec1 + sec2 + sec3;

    int minutes = result/60;
    int seconds = result - minutes*60;

    if (seconds < 10){
        printf("time: %d:0%d",minutes, seconds);
    }
    else{
        printf("time: %d:%d",minutes, seconds);
    }
}

