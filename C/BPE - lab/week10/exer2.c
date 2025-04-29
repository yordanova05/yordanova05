// structura box, sudurja poletata shirina duljuna visichina i obem, obem se izchislqva, stoinosti ot potrebitelq
// da printira informaciq s nai maluk i nai golqm obem

#include<stdio.h>

struct Cube{
    float shirina;
    float duljina;
    float visochina;
    float obem;
};

void calculate(struct Cube* cube){
    cube->obem = cube->duljina*cube->shirina*cube->visochina;
}

int main(){
    struct Cube cube1, cube2, cube3;

    printf("shirina na kub(1/2/3): ");
    scanf("%f %f %f",&cube1.shirina, &cube2.shirina, &cube3.shirina);

    printf("duljina na kub(1/2/3): ");
    scanf("%f %f %f",&cube1.duljina, &cube2.duljina, &cube3.duljina);

    printf("visochina na kub(1/2/3): ");
    scanf("%f %f %f",&cube1.visochina, &cube2.visochina, &cube3.visochina);

    calculate(&cube1);
    calculate(&cube2);
    calculate(&cube3);

    struct Cube minObem = cube1, maxObem = cube1;

    struct Cube arr[3] = {cube1,cube2,cube3};

    for(int i = 0; i < 3; i++){
        if ( minObem.obem > arr[i].obem){
            minObem = arr[i];
        }
        if ( maxObem.obem < arr[i].obem){
            maxObem = arr[i];
        }
    }

    printf("Nai-golqm obem ima cube-> shirina: %f, duljina: %f, visochina: %f, obem: %f\n",maxObem.shirina, maxObem.duljina, maxObem.visochina, maxObem.obem);
    printf("Nai-maluk obem ima cube-> shirina: %f, duljina: %f, visochina: %f, obem: %f",minObem.shirina, minObem.duljina, minObem.visochina, minObem.obem);
}
