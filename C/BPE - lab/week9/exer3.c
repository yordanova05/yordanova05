// potrebitelq suzdava nov razmer NEWSIZE ako e po-golqm da zapulnim novi elementi, ako e - po-maluk da se iztriqt elementi


#include<stdio.h>
#include<stdlib.h>

int main(){

    int *array;
    int i;
    int n;
    int sum = 0;

    printf("n = ");
    scanf("%d", &n);

    array = (int*)malloc(n*sizeof(int));
    if(array == NULL){
        exit(1);
    }

    for( i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    int *newarray;
    int newn;

    printf("newn = ");
    scanf("%d", &newn);

    newarray = (int*) realloc(array, newn*sizeof(int));

    if ( newn > n ){
        for ( i = n; i < newn; i++){
            printf("array[%d] = ", i);
            scanf("%d", &newarray[i]);
        }
    }

    for( i = 0; i < newn; i++){
        printf("%d, ", newarray[i]);
    }
}
