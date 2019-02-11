
#include <stdio.h>
#include <string.h>

int main()
{
    char str[39];
    char hex [] = "00";
    char bin[9] = "";
    long int binary;
    char lastChars[4];
    char lastTwo[3];
    int sum = 0; 
    int i;
    int temp;
    
    
    //Read a strings
    printf("Enter a string:\n");
    scanf("%s", str);
    
    //Group 2 chars together and add them
    for (i = 0; str[i] != 0; i+=2){
        hex[0]= str[i];
        hex[1] = str[i + 1];
        sum += (int)strtol(hex, NULL, 16);
    }
    
    //Display the result
    printf("%x\n", sum);
    
    //Get the last 2 chars from the result
    sprintf(lastChars, "%x", sum);
    lastTwo[0] = lastChars[1];
    lastTwo[1] = lastChars[2];
    
    //Convert hex to binary
    for(i = 0; i < 2; i++){
        switch(lastTwo[i]){
            case '0':
                strcat(bin, "0000");
                break;
            case '1':
                strcat(bin, "0001");
                break;
            case '2':
                strcat(bin, "0010");
                break;
            case '3':
                strcat(bin, "0011");
                break;
            case '4':
                strcat(bin, "0100");
                break;
            case '5':
                strcat(bin, "0101");
                break;
            case '6':
                strcat(bin, "0110");
                break;
            case '7':
                strcat(bin, "0111");
                break;
            case '8':
                strcat(bin, "1000");
                break;
            case '9':
                strcat(bin, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin, "1111");
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
    printf("The one's complement is: %x", binary);
    
    return 0;
}

