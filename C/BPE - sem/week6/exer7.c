#include <stdio.h>
float taxi(int n, char ch);
float bus(int n, char ch);
float train(int n, char ch);

int main(){
    int n;
    char ch;
    scanf("%d %c", &n, &ch);
    float result = taxi(n,ch);

    float result2 = bus(n,ch);

    float result3 = train(n,ch);

    if (result != 0 && result2 != 0 && result3 != 0){
        if(result < result2 && result < result3){
            printf("price for taxi: %f\n", result);
        }
        else if(result2 < result && result2 < result3){
            printf("price for bus: %f\n", result2);
        }
        else if(result3 < result && result3 < result2){
            printf("price for train: %f\n", result3);
        }
    }
    else{
        printf("price for taxi: %f\n", result);
        printf("price for bus: %f\n", result2);
        printf("price for train: %f\n", result3);

    }
}


float taxi(int n, char ch){
    if (ch == 'D') {
        return 0.70 + n * 0.79;
    } else if (ch == 'N') {
        return 0.70 + n * 0.90;
    }
}

float bus(int n, char ch){
    if ( n >= 20){
        return n*0.09;
    }
    else {
        return 0;
    }
}

float train(int n, char ch){
    if ( n >= 100){
        return n*0.06;
    }
    else{
        return 0;
    }
}

