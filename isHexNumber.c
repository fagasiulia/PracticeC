
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SUBTRACT 10

typedef unsigned int uint16;
typedef char char8;
uint16 isDigit(char8 number);
uint16 getHowMuchToSubtractToConvertCharToNumber(char8 letter);

int main()
{
    char8 a ='C';
    uint16 number = getHowMuchToSubtractToConvertCharToNumber(a);
    
    if(getHowMuchToSubtractToConvertCharToNumber(a)){
        printf("Trebuie sa scad din %d...%d ca sa imi dea %d. Rezultatul inseamna defapt: %c", a, number, a-number, a);
    }
    return 0;
}

/*Check if the char is a digit */
uint16 isDigit(char8 number){
    uint16 n = number;
    if(n >= '0' && n <= '9'){  /* 48-57 este intervalul pentru '0' - '9' */
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/*Check if the char is a hex */
uint16 getHowMuchToSubtractToConvertCharToNumber(char8 letter){
    if (isDigit(letter) == 1){
        return '0';
    }
    else if(letter >= 'A' && letter <= 'F'){ /* 65-70 este intervalul pentru 'A' - 'F' */
        return 'A' - SUBTRACT;
    }
    else if (letter >= 'a' && letter <= 'f'){ /* 97-102 este intervalul pentru 'a' - 'f' */
        return 'a' - SUBTRACT;
    }
    else{
        return FALSE;
    }
}
