/* 
TODO light weight pseudo-objects
*/

#define _CLASS1_C_
#include "class1.h"
#undef _CLASS1_C_

// Library includes
#include <stdio.h>


// Vital component:
static class1_t *instPtrTmp = 0; // Class methods need to know where to look for data

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

class1Methods_t class1_m(class1_t *inst)
{
  instPtrTmp = inst;
  return (class1Methods_t){print_privVar1 ,print_privVar2 ,set_privVars};
}


  // Public variable use: c1Inst1.pubVar1
  // Public function use: class1_m(&c1Inst1).print_pubVar1()

// TODO create header with exports
// TODO create main(), create instances, test them
// TODO create extra header with macros for facilitation of creating new classes, OOP.h, which will be include into every class .c file
