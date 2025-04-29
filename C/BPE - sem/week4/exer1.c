#include <stdio.h>;

int main()  {
    char numbers[] = {
    "one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine", "ten"};

    for (int i = 0; i < sizeof(numbers); i++)   {
        printf("%s\n", numbers[i]);
    }
    return 0;
}
