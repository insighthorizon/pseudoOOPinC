#ifndef _CLASS_1_H_
#define _CLASS_1_H_

// ==========================================================================
// definition of the class 1) - inner state & method structure
// ==========================================================================
/* visible from outside of source file */
typedef struct{
    // getters
    int (*get_state1)(void);
    int (*get_state2)(void);
    // setters
    void (*set_state1)(int);
    void (*set_state2)(int);
} t_class1_methods;

#ifdef _CLASS_1_C_
/* invisible froum otside of source file */
typedef struct{
    int state1;
    int state2;
} t_class1_private_state;

// ==========================================================================

static int class1_object1_get_state1_wrapper(void);
static int class1_object1_get_state2_wrapper(void);
static void class1_object1_set_state1_wrapper(int new_state1);
static void class1_object1_set_state2_wrapper(int new_state2);

static int class1_get_state1(t_class1_private_state *state);
static int class1_get_state2(t_class1_private_state *state);
static void class1_set_state1(t_class1_private_state *state, int new_state1);
static void class1_set_state2(t_class1_private_state *state, int new_state2);
#endif


// showing the object of the class to outside of the source file
extern t_class1_methods class1_object1;


#endif
