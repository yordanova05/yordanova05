#include<stdio.h>

float funct(float area, float t1, float t2, float hours);

int main(){
    float area, t1, t2, hours;
    scanf("%f %f %f %f",&area, &t1, &t2, &hours);
    float result = funct(area, t1, t2, hours);
    if ( result > 100){
        printf("Baseinut e prepulnen!");
    }
    else{
        printf("Baseinut e zapulnen na %.2f%%",result);
    }

}

float funct(float area, float t1, float t2, float hours){
    float liters = t1*hours + t2*hours;
    return (liters/(area*1000))*100.0;
}
