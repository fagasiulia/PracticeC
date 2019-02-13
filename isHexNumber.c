#include <stdio.h>


int isDigit(char number);
int isHexNumber (char letter);

int main()
{
    char a ='f';
    int number = isHexNumber(a);
    printf("%d", number);

    return 0;
}

int isDigit(char number){
    int n = number;
    if(n >= 48 && n <= 57){
        return 1;
    }
    else{
        return 0;
    }
}
int isHexNumber (char letter){
    int y = letter;
    if (isDigit(y) == 1){
        return 48;
    }
    else if(y >= 65 && y <= 70){
        return 65;
    }
    else if (y>= 97 && y <= 102){
        return 97;
    }
    else{
        return 0;
    }
}
