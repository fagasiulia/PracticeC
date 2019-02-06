/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Initialize memory allocation
    char *str = NULL;
    str = (char*) malloc(15);
    strcpy(str,"jason");
    printf("The string is %s and the address is %p\n", str,str);
    
    //Reallocate memory
    str = (char*) realloc(str,25);
    strcat(str, ".com");
    printf("The string is %s and the address is %p\n", str,str);
    
    free(str);

    return 0;
}

