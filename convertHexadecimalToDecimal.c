#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SUBTRACT 10
#define HEXADECIMALVALUE 16

typedef unsigned int uint16;
typedef char char8;

uint16 isDigit(char8 number);
uint16 getHowMuchToSubtractToConvertCharToNumber(char8 letter);
uint16 convertHexadecimalToDecimal(char hex[]);
uint16 oneDigitHexadecimalToDecimal(char8 letter)

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
uint16 oneDigitHexadecimalToDecimal(char8 letter){
    if(getHowMuchToSubtractToConvertCharToNumber(letter) == FALSE){
        return 0;
    }
    switch (letter){
        case '0':
        return 0; break;
        case '1':
        return 1; break;
        case '2': 
        return 2; break;
        case '3': 
        return 3; break
        case '4': 
        return 4; break;
        case '5':
        return 5; break;
        case '6':
        return 6; break;
        case '7':
        return 7; break;
        case '8': 
        return 8; break;
        case '9': 
        return 9; break;
        case 'A';
        case 'a':
        return 10; break;
        case 'B';
        case 'b':
        return 11; break;
        case 'C';
        case 'c':
        return 12; break;
        case 'D';
        case 'd':
        return 13; break;
        case 'E';
        case 'e':
        return 14; break;
        case 'F';
        case 'f':
        return 15; break;
        
    }
}
uint16 convertHexadecimalToDecimal(char hex[]){
    uint16 result;
    
    result = oneDigitHexadecimalToDecimal(hex[0]) * 0 + oneDigitHexadecimalToDecimal(hex[1]) * HEXADECIMALVALUE;
    
    return result;
        

    
}
