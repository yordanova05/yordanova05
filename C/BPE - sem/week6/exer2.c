#include<stdio.h>

int main(){
    int minutes, hours;
    int new_hours, new_minutes;
    printf("(hh:mm)\n");
    scanf("%d:%d", &hours, &minutes);
    if (minutes < 45){
        new_minutes = minutes + 15;
        new_hours = hours;
    }
    else{
        new_minutes = (minutes + 15) - 60;
        if (hours == 23){
            new_hours = 0;
        }
        else {
            new_hours = hours + 1;
        }
    }
    if (new_minutes < 10){
        printf("new time: (%d:0%d)", new_hours,new_minutes);
    }
    else {
        printf("new time: (%d:%d)", new_hours,new_minutes);
    }
}
