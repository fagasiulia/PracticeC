#include <stdio.h>
#include "FizzBuzz.h"

int main(int argc, char *argv [])
{
    printf("The command line has the following parameters:\n");
    for(int i = 0; i < argc; i++){
        printf("argv[%d] : %s \n", i , agrv[i]);
    }
    checkNumbers(argc);
    

    return 0;
}
