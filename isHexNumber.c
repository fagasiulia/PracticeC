
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SUBTRACT 10


int isDigit(char number);
int getHowMuchToSubtractToConvertCharToNumber(char letter);

int main()
{
    char a ='C';
    int number = getHowMuchToSubtractToConvertCharToNumber(a);
    
    if(getHowMuchToSubtractToConvertCharToNumber(a)){
        printf("Trebuie sa scad din %d...%d ca sa imi dea %d. Rezultatul inseamna defapt: %c", a, number, a-number, a);
    }
    return 0;
}

//Check if the char is a digit
int isDigit(char number){
    int n = number;
    if(n >= '0' && n <= '57'){  // 48-57 este intervalul pentru '0' - '9'
        return TRUE;
    }
    else{
        return FALSE;
    }
}

//Check if the char is a hex
int getHowMuchToSubtractToConvertCharToNumber(char letter){
    if (isDigit(letter) == 1){
        return '0';
    }
    else if(letter >= 'A' && letter <= 'F'){ // 65-70 este intervalul pentru 'A' - 'F'
        return 'A' - SUBSTRACT;
    }
    else if (letter >= 'a' && letter <= 'f'){ // 97-102 este intervalul pentru 'a' - 'f'
        return 'a' - SUBSTRACT;
    }
    else{
        return FALSE;
    }
}
