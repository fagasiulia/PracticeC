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

