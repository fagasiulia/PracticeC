#include "checkNumbres.h"

enum states{
    START,
    FIZZBUZ,
    FIZZ,
    BUZZ,
    EXIT
}state;

enum events{
    ASK_FOR_INPUT(),
    CHECK_DIV_BY_3_AND_5(),
    CHECK_DIV_BY_3(),
    CHECK_DIV_BY_5(),
    STOP_LOOP()
};

void step_state(int n){
    while(n >0){

    switch(state){
    case START:
        switch(event){
        case ASK_FOR_INPUT:
            state = FIZZBUZZ;
            break;
        default exit(1);
        break;
        }
    case FIZZBUZZ:
        switch(event){
        case CHECK_DIV_BY_3_AND_5:
            state = FIZZ;
            break;
        default exit(1);
        break;
        }
    case FIZZ:
        switch(event){
        case CHECK_DIV_BY_3:
            state = BUZZ;
            break;
        default exit(1);
        break;
        }
    case BUZZ:
        switch(event){
        case CHECK_DIV_BY_5:
            state = EXIT;
            break;
        default exit(1);
        break;
        }
    case EXIT:
        switch(event){
        case STOP_LOOP:
          exit(1);
          break;
        }
    }
    n--;
}

}

