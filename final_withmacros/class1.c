/* User setup code begin: */
// Set those according class name
#define _CLASS1_C_
#include "class1.h"
#undef _CLASS1_C_

// Include dependencies here:
#include <stdio.h>
// If you want to have global objects, define them here (with macro):

/* User setup code END */


static CLASS_T *instPtrTmp = 0;

// Definition of public functions
PUBLIC_FUNCTIONS_DEF(PUB_HEADER, FUN_BODY, NONE)
// Definition of private functions
PRIVATE_FUNCTIONS_DEF(PRIV_HEADER, FUN_BODY)

CLASS_METHODS_T CLASS_M(CLASS_T *inst)
{
  instPtrTmp = inst;
  return (CLASS_METHODS_T){ PUBLIC_FUNCTIONS_DEF(TAKE_NAME, JUST_NAME, COMMA) };
}

