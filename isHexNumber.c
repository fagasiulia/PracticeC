
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int isDigit(char number);
int getHowMuchToSubtractToConvertCharToNumber(char letter);

int main()
{
    char a ='8';
    int number = getHowMuchToSubtractToConvertCharToNumber(a);
    
    if(getHowMuchToSubtractToConvertCharToNumber(a)){
        printf("Trebuie sa scad din %d...%d ca sa imi dea %d", a, number, a-number);
    }
    return 0;
}

int isDigit(char number){
    int n = number;
    if(n >= 48 && n <= 57){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
int getHowMuchToSubtractToConvertCharToNumber(char letter){
    if (isDigit(letter) == 1){
        return '0';
    }
    else if(letter >= 65 && letter <= 70){
        return 'A';
    }
    else if (letter >= 97 && letter <= 102){
        return 'a';
    }
    else{
        return FALSE;
    }
}
