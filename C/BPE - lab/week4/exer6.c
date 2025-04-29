// chete ot klaviaturata dve celi chisla izvejda na koznolata sumata na chislata mevdu tezi dve chisla
#include <stdio.h>

int main(){
    int x,y;
    int sum = 0;
    scanf("%d %d",&x,&y);
    if (x < y){
        int z = x+1;
        for (z; z < y; z++){
            sum += z;
        }
        printf("Sum: %d", sum);
    }

    else if (x > y) {
        int z = y+1;
        for (z; z < x; z++){
            sum += z;
        }
        printf("Sum: %d", sum);
    }
    else{
        printf("Chislata sa ravni!");
    }
}
