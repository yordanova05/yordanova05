#include <stdio.h>
int main()  {
    int a = 1;
    double d = 0.5;
    char ch = 'c';
    scanf("%d", &a); /*grupirasht metod, standarten vhod*/
    printf("%d", a);

    int min = 0;
    int sum = 0;
    int arr[5] = {1, -2, 3, -4, 5};
    for(int i = 0; i < 5; i++)  {
        if (min > arr[i])   {
            min = arr[i];
        }
        sum += arr[i];
        printf("%d\n",arr[i]);
    }
    double avg = (double)sum / 5;
    printf("%lf\n", sum / sizeof(arr));
    printf("%d\n", min);
    printf("%d",arr[0]);

    int arr2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i  = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\n", arr2[i][j]);
        }
    }

    int num = 0;
    int arrr[3][3] = {1,2,3,4,5,6,7,8,9};
    for (int i  = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                num += arrr[i][j];
            }
        }
    }
    printf("%d\n", num);

    /* char ch[20];
    // scanf("%s", ch);
    / printf("%s", ch); */

}
