#include <stdlib.h>
#include <stdio.h>
#include "checkNumbers.h"

enum states{
    START,
    FIZZBUZZ,
    FIZZ,
    BUZZ,
    EXIT
}state;

enum events{
    ask_for_input,
    check_div_by_3_and_5,
    check_div_by_3,
    check_div_by_5,
    stop
}event;

void step_state(int n){
    while(n >0){

    switch(state){
    case START:
        switch(event){
        case ask_for_input:
            ASK_FOR_INPUT();
            state = FIZZBUZZ;
            break;
        default: exit(1);
        break;
        }
    case FIZZBUZZ:
        switch(event){
        case check_div_by_3_and_5:
            CHECK_DIV_BY_3_AND_5();
            state = FIZZ;
            break;
        default: exit(1);
        break;
        }
    case FIZZ:
        switch(event){
        case check_div_by_3:
            CHECK_DIV_BY_3();
            state = BUZZ;
            break;
        default: exit(1);
        break;
        }
    case BUZZ:
        switch(event){
        case check_div_by_5:
            CHECK_DIV_BY_5();
            state = EXIT;
            break;
        default: exit(1);
        break;
        }
    case EXIT:
        switch(event){
        case stop:
          STOP_LOOP();
          exit(1);
          break;
        }
    }
    n--;
}

}
