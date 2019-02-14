
/**************************************************
I need to create a function that converts numbers to binary 
***************************************************/

#include <stdio.h>
#include <string.h> /* need to be taken out */
#define LENGTH 38
#define TRUE 1
#define FALSE 0
#define SUBTRACT 10
#define HEXADECIMALVALUE

typedef unsigned int uint16;
typedef unsigned int uint32;
typedef char char8;
typedef char char16;
typedef char char32;

uint16 isDigit(char8 number);
uint16 getHowMuchToSubtractToConvertCharToNumber(char8 letter);
uint16 convertHexadecimalToDecimal(char hex[]);
uint16 oneDigitHexadecimalToDecimal(char8 letter)

char8 *concat (char * s1, char *s2);
int main()
{
    char str[]="137AF00A0A0D00000000000000000000000000"; /** typdef? */
    char8 hex [] = "00";
    char8 bin[9] = "";
    uint32 binary;
    char16 lastChars[4];
    char16 lastTwo[3];
    uint16 sum = 0; 
    uint16 i;
    
    
    /*Group 2 chars together and add them */
    for (i = 0; i < LENGTH; i+=2){
        hex[0]= str[i];
        hex[1] = str[i + 1];
        sum += convertHexadecimalToDecimal(hex);
    }
    
    /*Display the result */
    printf("The sum is: %x\n", sum);
    
    /*Get the last 2 chars from the result */
    sprintf(lastChars, "%x", sum);
    lastTwo[0] = lastChars[1];
    lastTwo[1] = lastChars[2];
    
    /*Convert hex to binary */
    for(i = 0; i < 2; i++){
        switch(lastTwo[i]){
            case '0':
                concat(bin, "0000");
                break;
            case '1':
                concat(bin, "0001");
                break;
            case '2':
                concat(bin, "0010");
                break;
            case '3':
                concat(bin, "0011");
                break;
            case '4':
                concat(bin, "0100");
                break;
            case '5':
                concat(bin, "0101");
                break;
            case '6':
                concat(bin, "0110");
                break;
            case '7':
                concat(bin, "0111");
                break;
            case '8':
                concat(bin, "1000");
                break;
            case '9':
                concat(bin, "1001");
                break;
            case 'a':
            case 'A':
                concat(bin, "1010");
                break;
            case 'b':
            case 'B':
                concat(bin, "1011");
                break;
            case 'c':
            case 'C':
                concat(bin, "1100");
                break;
            case 'd':
            case 'D':
                concat(bin, "1101");
                break;
            case 'e':
            case 'E':
                concat(bin, "1110");
                break;
            case 'f':
            case 'F':
                concat(bin, "1111");
                break;
            default:
                printf("\nInvalid input.");
 
        }
    }
    
    /*Print the result */
    printf("\nThe binary number is: \n");
    for(i = 0; bin[i] !='\0'; i++){
            printf("%c", bin[i]);
    }
    
    /*Compute one's complement */
    for(i = 0; i < 8; i++){
        if(bin[i] == '0'){
            bin[i] = '1';
        }
        else{
            bin[i] = '0';
        }
    }
    
    /*Print the result */
    printf("\nThe number's complement is: \n");
    for(i = 0; bin[i] !='\0'; i++){
            printf("%c", bin[i]);
    }
    
    /*Convert binary to hex
    ***********************Create a function for this one */
    binary = strtol(bin, NULL, 2);
    printf("\nThe one's complement is: %x", binary);
    
    return 0;
}
/*Concat method */
char *concat (char * s1, char *s2){
    uint16 length = strlen(s1); /********need to remove strlen */
    for(int i = 0; i < strlen(s2); i++)
    {
        s1[length++] = s2[i];
    }

    s1[length] = '\0';
    
    return s1;
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
/* Hex char to decimal */ 
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
/* Get the final result */
uint16 convertHexadecimalToDecimal(char hex[]){
    uint16 result;
    
    result = oneDigitHexadecimalToDecimal(hex[0]) * 0 + oneDigitHexadecimalToDecimal(hex[1]) * HEXADECIMALVALUE;
    
    return result;   
}
