#define _MYCLASS_C_
#include "myClass.h"
#undef _MYCLASS_C_

// Library includes
#include <stdio.h>


// Vital component:
static myClass_t *instPtrTmp = 0; // Class methods need to know where to look for data

// Definition of public functions
void print_privVar1(void)
{
  printf("This is privVar1: %d\n", get_privVar1());
  return;
}
void print_privVar2(void)
{
  printf("This is privVar2: %d\n", get_privVar2());
  return;
}
void set_privVars(int priv1, int priv2)
{
  (instPtrTmp->dontuseoutside).privVar1 = priv1;
  (instPtrTmp->dontuseoutside).privVar2 = priv2;  
  return;
}

// Definition of private functions - functions are really private, since they are not exported from the file - true encapsulation
static int get_privVar1(void)
{
  return (instPtrTmp->dontuseoutside).privVar1;
}
static int get_privVar2(void)
{
  return (instPtrTmp->dontuseoutside).privVar2;
}

// Method interface
myClassMethods_t myClass_m(myClass_t *inst)
{
  instPtrTmp = inst;
  return (myClassMethods_t){print_privVar1 ,print_privVar2 ,set_privVars};
}

