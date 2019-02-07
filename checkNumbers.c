void checkNumbers(int n){
    while(n > 0){
    //Ask the user to enter a numbers
    printf("Enter a number:\n");
    //Save that number in a String
    char str[9];
    scanf("%s", str);
    //Convert the String into an integer
    int number = atoi(str);
    //Check if the number is divisible by 3/ 5 or both
    if((number % 3 == 0) && (number % 5 == 0))
        printf("Fizzbuzz\n");
    else if (number % 3 == 0)
        printf("Fizz\n");
    else if (number % 5 == 0)
        printf("Buzz\n");
    else
        printf("");

    n--;
    }


}
