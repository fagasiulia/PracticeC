void checkNumbers(int array[]){
    size_t n = sizeof(array)/sizeof(array[0]);
    
    for(int i = 0; i < n; i ++){
        if(((i % 3) == 0) && ((i % 5) == 0)){
            printf("Fizzbuzz\n");
        }
        else if((i % 3) == 0){
            printf("Fizz\n");
        }
        else if((i % 5) == 0){
            printf("Buzz\n");
        }
        else{
            printf("");
        }
    }
}
