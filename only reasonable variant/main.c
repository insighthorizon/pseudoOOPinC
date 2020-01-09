#include <stdio.h>

#include "./class1.h"


int main(void){

    printf("class1 object1 state1: %d\n", class1_object1.get_state1());
    printf("class1 object1 state2: %d\n", class1_object1.get_state2());    
    class1_object1.set_state1(5);
    class1_object1.set_state2(10);
    printf("class1 object1 state1: %d\n", class1_object1.get_state1());
    printf("class1 object1 state2: %d\n", class1_object1.get_state2());
    class1_object1.set_state1(0);
    class1_object1.set_state2(0);
    printf("class1 object1 state1: %d\n", class1_object1.get_state1());
    printf("class1 object1 state2: %d\n", class1_object1.get_state2());    
    
    return 0;
}

