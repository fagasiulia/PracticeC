#include <stdio.h>
#include <stdlib.h>

enum states {
    START,
    EXIT_LOOP
}states;

enum events{
    ASK_FOR_MONEY,
    CHECK_MONEY,
    DISPENSE_COKE,
    DISPENSE_CHANGE
}event;

void step_state(int price){
    int n = price;
    int money = 0;
    int moneyInserted;
    int state = START;
    int event = ASK_FOR_MONEY;
    
while (n > money){
        switch(state){
        case START:
        event = ASK_FOR_MONEY;
        
        switch(event){
            case ASK_FOR_MONEY:
            printf("Please insert money: \n");
            scanf("%d", &moneyInserted);
            money += moneyInserted;
            event = CHECK_MONEY;
            break;
            
            case CHECK_MONEY:
            if(money >= n){
                event = DISPENSE_COKE;
            }
            else {
                printf("Not enough money");
                event = ASK_FOR_MONEY;
            }
            break;
            
            case DISPENSE_COKE:
            printf("Enjoy");
            if(money> n){
                event = DISPENSE_CHANGE;
            }
            else{
                state = EXIT_LOOP;
            }
            break;
    
            case DISPENSE_CHANGE:
            printf("Your change is %d", money -n);
            state = EXIT_LOOP;
            break;
        }
        case EXIT_LOOP:
        printf("Thank you!");
        exit(1);
    }
