#include <stdio.h>
#include <string.h>
#define LENGTH 38

char *concat (char * s1, char *s2);
int main()
{
    char str[]="137AF00A0A0D00000000000000000000000000";
    char hex [] = "00";
    char bin[9] = "";
    long int binary;
    char lastChars[4];
    char lastTwo[3];
    int sum = 0; 
    int i;
    int temp;
    
    //Group 2 chars together and add them
    for (i = 0; i < LENGTH; i+=2){
        hex[0]= str[i];
        hex[1] = str[i + 1];
        sum += (int)strtol(hex, NULL, 16);
    }
    
    //Display the result
    printf("The sum is: %x\n", sum);
    
    //Get the last 2 chars from the result
    sprintf(lastChars, "%x", sum);
    lastTwo[0] = lastChars[1];
    lastTwo[1] = lastChars[2];
    
    //Convert hex to binary
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
    
    //Print the result
    printf("\nThe binary number is: \n");
    for(i = 0; bin[i] !='\0'; i++){
            printf("%c", bin[i]);
    }
    
    //Compute one's complement
    for(i = 0; i < 8; i++){
        if(bin[i] == '0'){
            bin[i] = '1';
        }
        else{
            bin[i] = '0';
        }
    }
    
    //Print the result
    printf("\nThe number's complement is: \n");
    for(i = 0; bin[i] !='\0'; i++){
            printf("%c", bin[i]);
    }
    
    //Convert binary to hex
    binary = strtol(bin, NULL, 2);
    printf("\nThe one's complement is: %x", binary);
    
    return 0;
}
// Concat method
char *concat (char * s1, char *s2){
    int length = strlen(s1);
    for(int i = 0; i < strlen(s2); i++)
    {
        s1[length++] = s2[i];
    }

    s1[length] = '\0';
    
    return s1;
}
