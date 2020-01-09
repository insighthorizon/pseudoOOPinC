#define _CLASS_1_C_
#include "./class1.h"
#undef _CLASS_1_C_

// ==========================================================================
// definition of the class 2) - class methods implementation
// ==========================================================================
static int class1_get_state1(t_class1_private_state *state){
    return state->state1;
}
static int class1_get_state2(t_class1_private_state *state){
    return state->state2;
}
static void class1_set_state1(t_class1_private_state *state, int new_state1){
    state->state1 = new_state1;
}
static void class1_set_state2(t_class1_private_state *state, int new_state2){
    state->state2 = new_state2;
}
// ==========================================================================


// ==========================================================================
// implementation of the particular instance of the class (class1_object1)
// ==========================================================================
static t_class1_private_state class1_object1_state = {0, 0};
t_class1_methods class1_object1 = {.get_state1=class1_object1_get_state1_wrapper, .get_state2=class1_object1_get_state2_wrapper, .set_state1=class1_object1_set_state1_wrapper, .set_state2=class1_object1_set_state2_wrapper};

// method wrappers for particular object object1 of class1
static int class1_object1_get_state1_wrapper(void){
    return class1_get_state1(&class1_object1_state);
}
static int class1_object1_get_state2_wrapper(void){
    return class1_get_state2(&class1_object1_state);
}
static void class1_object1_set_state1_wrapper(int new_state1){
    class1_set_state1(&class1_object1_state, new_state1);
}
static void class1_object1_set_state2_wrapper(int new_state2){
    class1_set_state2(&class1_object1_state, new_state2);
}
// ==========================================================================

