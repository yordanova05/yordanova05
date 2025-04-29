#include<stdio.h>
#include<stdlib.h>

int main(){
    int *array;
    int count = 7;
    int i;
    array = (int*)malloc(count*sizeof(int));
    if (array == NULL){
        exit(1);
    }

    for( i = 0; i < count; i++){
        array[i] = i+1; // narastva s 1byte toest 1, 2, 3,4...
    }

    for( i = 0; i < count; i++){
        printf("%d", array[i]);
    }

    int *newptr;
    newptr = array;
    array = (int*)malloc(++count*sizeof(int));

    if(array == NULL){
        exit(1);
    }

    for( i = 0; i <count - 1; i++){
        array[i] = newptr[i];
    }
    array[i] = count;
    free(newptr);

    // da iztriem 3-tiq element

    int x = 3;
    newptr = array;

    for (i = x; i < count; i++){
        // izmestvame elementite s edna poziciq sled index 3
        newptr[i-1] = newptr[i];
    }
    array = (int*)malloc(--count*sizeof(int));
    if(array == NULL){
        exit(2);
    }

    for( i = 0; i < count; i++){
        array[i] = newptr[i];
    }

    free(newptr);

}


