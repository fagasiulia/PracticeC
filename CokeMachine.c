#include <stdio.h>
#include <stdlib.h>

enum states {
    START,
    ASK_FOR_MONEY,
    EXIT_LOOP
}states;

enum events{
    CHECK_MONEY,
    NOT_ENOUGH_MONEY,
    DISPENSE_COKE,
    DISPENSE_CHANGE
}event;

void step_state(int price){
    int n = price;
    int money = 0;
    int moneyInserted = 0;
    int state = START;
    int event = CHECK_MONEY;
    
    while (n != 0){
        switch(state){
            case START:
                switch(event){
                    case CHECK_MONEY: 
                       if(money < n){
                           state = ASK_FOR_MONEY;
                       }
                       else{
                           event = DISPENSE_COKE;
                       }
                    break;
                    
                    case DISPENSE_COKE:
                        printf("Enjoy\n");
                        if(money > n){
                            event = DISPENSE_CHANGE;
                        }
                        else{
                            state = EXIT_LOOP;
                        }
                    break;
                    
                    case DISPENSE_CHANGE:
                        printf("Your change is: %d \n", money - n);
                        state = EXIT_LOOP;
                    break;
                }
                break;
                
            case ASK_FOR_MONEY:
                printf("Insert money: \n");
                scanf("%d", &moneyInserted);
                money += moneyInserted;
                state = START;
            break;
            
            case EXIT_LOOP:
                printf("Thank you!");
                exit(1);
                
        }
    
    }    
}
