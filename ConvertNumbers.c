#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SUBSTRACT 10
#define LENGTH 38

typedef unsigned int uint8;
typedef unsigned int uint16;
typedef unsigned int uint32;
typedef char char8;

uint16 isDigit(char8 number);
uint16 getHowMuchToSubtractToConvertCharToNumber(char8 letter);
uint16 convertHexToDecimal(char8 letter);
uint16 convertAFullHexNumber(char8 letter[]);
void convertHexToBinaty(uint8 last);
void printBit(uint8 last, uint8 position);

int main()
{
    char str[]="137AF00A0A0D00000000000000000000000000";
    char8 hex [] = "00";
    uint32 sum = 0;
    uint8 lastByte;
    uint16 complementNo = 0;
    
    /*Group the chars and add them */
    for (uint16 i = 0; i < LENGTH; i+=2){
        hex[0]= str[i];
        hex[1] = str[i + 1];
        sum +=convertAFullHexNumber(hex);
    }
    
    /*Display the result */
    printf("The sum is: %x\n", sum);
    
    /*Get the last significant byte */
    lastByte = sum &0xFF; /******* IMPORTANT ******/
    printf("The last significat byte is: %x\n", lastByte);
    
    /*Convert hex to binary */
    convertHexToBinaty(lastByte);
    
    /*Compute one's complement */
    complementNo = ~lastByte &0xFF; /* ~ (tilde) */
    
    
    printf("\n");
    printf("\nOne's complement is: %x.\nIn binary that means: ", complementNo);
    convertHexToBinaty(complementNo);
    
}


/*Check if the char is a digit */
uint16 isDigit(char8 number){
    uint16 n = number;
    if(n >= 48 && n <= 57){  // 48-57 este intervalul pentru '0' - '9'
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/*Check if the char is a hex */
uint16 getHowMuchToSubtractToConvertCharToNumber(char8 letter){
    if (isDigit(letter)){
        return '0';
    }
    else if(letter >= 65 && letter <= 70){ // 65-70 este intervalul pentru 'A' - 'F'
        return 'A' - SUBSTRACT;
    }
    else if (letter >= 97 && letter <= 102){ // 97-102 este intervalul pentru 'a' - 'f'
        return 'a' - SUBSTRACT;
    }
    else{
        return FALSE;
    }
}

/* Convert hex to decimal */
uint16 convertHexToDecimal(char8 letter){
    uint16 number = getHowMuchToSubtractToConvertCharToNumber(letter);
    uint16 result = letter - number;
    return result;
}

/* Convert a full hex number */
uint16 convertAFullHexNumber(char8 letter[]){
    uint16 result;
    result = convertHexToDecimal(letter[0]) * 16 + convertHexToDecimal(letter[1]);
    return result;
}

/*Convert hex to binary */
void convertHexToBinaty(uint8 last){
    for(uint8 i = 0; i < 8; i++){
        printBit(last,i);
    }
}

void printBit(uint8 last, uint8 position){
    uint8 mask;
    mask = 0x80 >> position;
    uint8 number = last&mask;
    if(number > 0 ){
        printf("1");
    }
    else {
        printf("0");
    }
}
