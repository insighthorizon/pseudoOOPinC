#ifndef _MYCLASS_H_
#define _MYCLASS_H_

typedef struct{
  int privVar1; // Definition of "private" variables - we cant practicaly do really hiden private variables, but 
  int privVar2;
}myClassPriv_t;
typedef struct{ 
  int pubVar1; // Definition of public variables
  int pubVar2;
  myClassPriv_t dontuseoutside; // You don't want to access this by hand
}myClass_t;

/* Method interface - better to not have methods global,
avoiding naming collisions, etc. having only interface
 method for the class global, shared by instancess of class*/
typedef struct{
  void (*print_privVar1)(void);
  void (*print_privVar2)(void);
  void (*set_privVars)(int, int);
}myClassMethods_t;

#ifdef _MYCLASS_C_
void print_privVar1(void);
void print_privVar2(void);
void set_privVars(int priv1, int priv2);
static int get_privVar1(void);
static int get_privVar2(void);
#else
extern myClassMethods_t myClass_m(myClass_t *inst);
#endif


#endif
