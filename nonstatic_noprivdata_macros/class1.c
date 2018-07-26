/* User setup code START: */
// Set those according class name
#define _CLASS1_C_
#include "class1.h"
#undef _CLASS1_C_

// Include dependencies here:
#include <stdio.h>

/* User setup code END */


static CLASS_T *instPtrTmp = 0;

// Definition of public functions
USER_FUNCTIONS_DEF(USER_HEADER, FUN_BODY, NONE)
// Definition of private functions
HIDDEN_FUNCTIONS_DEF(HIDD_HEADER, FUN_BODY)

CLASS_METHODS_T CLASS_M(CLASS_T *inst)
{
  instPtrTmp = inst;
  return (CLASS_METHODS_T){ USER_FUNCTIONS_DEF(TAKE_NAME, JUST_NAME, COMMA) };
}

