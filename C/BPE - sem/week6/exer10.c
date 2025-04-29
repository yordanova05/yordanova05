#include <stdio.h>

int main(){
    int n,x;
    int count = 0;
    printf("Kolko chisla shte pishehs: ");
    float p1 = 0;
    float p2 = 0;
    float p3 = 0;
    float p4 = 0;
    float p5 = 0;
    scanf("%d", &n);
    while(count<n){
        printf("chislo[%d]: ",count + 1);
        scanf("%d",&x);
        if (x >= 1 && x <= 1000){
            count++;
            if ( x < 200){
                p1++;
            }
            else if ( x >= 200 && x < 400){
                p2++;
            }
            else if ( x >= 400 && x < 600){
                p3++;
            }
            else if ( x >= 600 && x < 800){
                p4++;
            }
            else{
                p5++;
            }
        }
    }
    printf("%d\n",p1);
    printf("%d\n",p2);
    printf("%d\n",p3);
    printf("%d\n",p4);
    printf("%d\n",p5);

    printf("Chislata mejdu 1 i 199 sa %.2f%%\n",(p1/n)*100.0);
    printf("Chislata mejdu 200 i 399 sa %.2f%%\n",(p2/n)*100.0);
    printf("Chislata mejdu 400 i 599 sa %.2f%%\n",(p3/n)*100.0);
    printf("Chislata mejdu 600 i 799 sa %.2f%%\n",(p4/n)*100.0);
    printf("Chislata mejdu 800 i 1000 sa %.2f%%\n",(p5/n)*100.0);
}
