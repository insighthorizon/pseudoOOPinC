#define _SINGLETON1_C_
#include "singleton1.h"
#undef _SINGLETON1_C_

// library includes
#include <stdio.h>

// there is the only instantiation of the object
TYPE_PASTE SINGLETON_NAME = {.pubVar1=0, .pubVar2=0, .pubFun1=pubFun1, .pubFun2=pubFun2, .pubFun3=pubFun3};

// this type of object has true encapsulation of private data
static int priv1 = 0;
static int priv2 = 0;


PUBLIC_FUNCTIONS_DEF(PUB_HEADER, FUN_BODY)
PRIVATE_FUNCTIONS_DEF(PRIV_HEADER, FUN_BODY)


