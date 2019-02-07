#include <stdio.h>
#include <stdlib.h>
#include "checkNumbres.h"

int main()
{
    printf("How many numbers would you like to check?\n");
    int numbers;
    scanf("%d", &numbers);
    checkNumbers(numbers);
    return 0;
}
