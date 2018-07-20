#ifndef _CLASS1_H_
#define _CLASS1_H_



typedef struct{
  int privVar1; // Definition of "private" variables - we cant practicaly do really hiden private variables, but 
  int privVar2;
}class1Priv_t;
typedef struct{ 
  int pubVar1; // Definition of public variables
  int pubVar2;
  class1Priv_t dontuseoutside; // You don't want to access this by hand
}class1_t;

// Method interface - better to not have methods global, avoiding naming collisions, etc.
typedef struct{
  void (*print_privVar1)(void);
  void (*print_privVar2)(void);
  void (*set_privVars)(int, int);
}class1Methods_t;

#ifdef _CLASS1_C_
void print_privVar1(void);
void print_privVar2(void);
void set_privVars(int priv1, int priv2);
static int get_privVar1(void);
static int get_privVar2(void);
#else
extern class1Methods_t class1_m(class1_t *inst);
#endif


#endif
