#define _MYCLASS_C_
#include "myClass.h"
#undef _MYCLASS_C_

// Library includes
#include <stdio.h>


// Vital component:
static myClass_t *instPtrTmp = 0; // Class methods need to know where to look for data

// Definition of user functions
/* Warning - once you use static variable inside of user or hidden function,
this variable will be shared for all objects */
void printVar1(void)
{
  printf("This is Var1: %d\n", getVar1());
  return;
}
void printVar2(void)
{
  printf("This is Var2: %d\n", getVar2());
  return;
}
void setVars(int v1, int v2)
{
  instPtrTmp->var1 = v1;
  instPtrTmp->var2 = v2;  
  return;
}

// Definition of hidden functions - these functions are really hidden, since they are not exported from the file - true encapsulation
static int getVar1(void)
{
  return instPtrTmp->var1;
}
static int getVar2(void)
{
  return instPtrTmp->var2;
}

// Method interface
myClassMethods_t myClass_m(myClass_t *inst)
{
  instPtrTmp = inst;
  return (myClassMethods_t){printVar1 ,printVar2 ,setVars};
}

