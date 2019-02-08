int number;

void ASK_FOR_INPUT(){
    printf("Enter a number:\n");
    char str[9];
    scanf("%s", str);
    number = atoi(str);
}

void CHECK_DIV_BY_3_AND_5(){
    if((number % 3 == 0) && (number % 5 == 0))
        printf("Fizzbuzz\n");
}

void CHECK_DIV_BY_3(){
    if (number % 3 == 0)
        printf("Fizz\n");
}

void CHECK_DIV_BY_5(){
    if (number % 5 == 0)
        printf("Buzz\n");
}

void STOP_LOOP(){
    printf("");
}
