#include <stdio.h>
#include <stdlib.h>
#include "stateMachine.h"

extern void step_state(int n);

int main()
{
    printf("How many numbers would you like to check?\n");
    int numbers;
    scanf("%d", &numbers);
    step_state(numbers);
    return 0;
}
