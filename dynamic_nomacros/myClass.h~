#ifndef _MYCLASS_H_
#define _MYCLASS_H_

typedef struct{ 
  int var1; // Object data
  int var2;
}myClass_t;

/* Method interface - better to not have methods global,
avoiding naming collisions, etc. having only interface
 method for the class global, shared by instancess of class*/
typedef struct{
  void (*printVar1)(void);
  void (*printVar2)(void);
  void (*setVars)(int, int);
}myClassMethods_t;

#ifdef _MYCLASS_C_
void printVar1(void);
void printVar2(void);
void setVars(int priv1, int priv2);
static int getVar1(void);
static int getVar2(void);
#else
extern myClassMethods_t myClass_m(myClass_t *inst);
#endif

#endif
