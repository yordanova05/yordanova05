#include<stdio.h>
void funct(int x, int y, int x1, int y1, int x2, int y2);
int main(){
    float x, y,x1,y1,x2,y2;
    printf("x1 = ");
    scanf("%d",&x1);
    printf("y2 = ");
    scanf("%d",&y1);
    while(1){
        printf("x2 = ");
        scanf("%d",&x2);
        if ( x2 > x1 ){
            break;
        }
    }

    while(1){
        printf("y2 = ");
        scanf("%d",&y2);
        if ( y2 > y1 ){
            break;
        }
    }
    printf("x = ");
    scanf("%d",&x);
    printf("y = ");
    scanf("%d",&y);

    funct(x,y,x1,y1,x2,y2);
}
void funct(int x, int y, int x1, int y1, int x2, int y2){
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2){
        printf("Inside!");
    }
    else{
        printf("Outside!");
    }

}
