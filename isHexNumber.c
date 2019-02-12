/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


_Bool isDigit(char *number);
int isHexNumber (char *letter);

int main()
{
    char a ='f';
    int number = isHexNumber(a);
    printf("%d", number);

    return 0;
}

_Bool isDigit(char *number){
    int n = number;
    if(n >= 48 && n <= 57){
        return 1;
    }
    else{
        return 0;
    }
}
int isHexNumber (char *letter){
    int y = letter;
    if (isDigit(y) == 1){
        return 48;
    }
    else if((y >= 65 && y <= 70) || (y>= 113 && y <= 118)){
        return 65;
    }
    else{
        return 0;
    }
}

