#include <stdio.h>
#include <stdlib.h>

enum states {
    START,
    DISPENCE_COKE,
    DISPENCE_CHANGE,
    EXIT_LOOP
}states;

enum events{
    ASK_FOR_MONEY,
    CHECK_MONEY,
    NOT_ENOUGH_MONEY,
    ENOUGH_MONEY
}event;

void step_state(int price, int quantity){
	int n = price;
	int y = quantity;
	int money = 0;
	int moneyInserted = 0;
	int state=START;
	int event=ASK_FOR_MONEY;
	
    while(y > 0){
        switch(state){
            case START:
                switch(event){
                    case ASK_FOR_MONEY:
                        printf("Insert the money \n");
                        scanf("%d", &moneyInserted);
                        money += moneyInserted;
                        event = CHECK_MONEY;
                    break;
                    
                    case CHECK_MONEY:
                        if(money < n){
                            event = NOT_ENOUGH_MONEY;
                        }
                        else{
                             event = ENOUGH_MONEY;
                        }
                    break;
                    
                    case NOT_ENOUGH_MONEY:
                        printf("Not enough money\n");
                        event = ASK_FOR_MONEY;
                    break;
                    
                    case ENOUGH_MONEY:
                        if(money> price){
                            state = DISPENCE_CHANGE; 
                        }
                        else{
                             state = DISPENCE_COKE;
                        }
                    break;
                }
            break;
            
            case DISPENCE_COKE:
                printf("Here is your coke\n");
                state = EXIT_LOOP;
            break;
            
            case DISPENCE_CHANGE:
                printf("Your change is %d\n", money - price);
                state = DISPENCE_COKE;
            break;
            
            case EXIT_LOOP:
                printf("Enjoy!\n");
                money = 0;
                y --;
                state = START;
                event = ASK_FOR_MONEY;
            break;
        }
    }
}
