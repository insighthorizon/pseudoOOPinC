#define _SINGLETON1_C_
#include "singleton1.h"
#undef _SINGLETON1_C_

// library includes
#include <stdio.h>

// there is the only instantiation of the object
singleton1_t mySingleton = {.pubVar1=0, .pubVar2=0, .pubFun1=pubFun1, .pubFun2=pubFun2, .pubFun3=pubFun3};

// this type of object has true encapsulation of private data
static int priv1 = 0;
static int priv2 = 0;

void pubFun1(void)
{
  printf("%d\n", getPriv1() );
  mySingleton.pubVar1 += 1;
  return;
}
void pubFun2(void)
{
  printf("%d\n", getPriv2() );
  mySingleton.pubVar2 += 1;
  return;
}
void pubFun3(int x, int y)
{
  priv1 = x;
  priv2 = y;
  mySingleton.pubVar1 += 1;
  mySingleton.pubVar2 += 1;
  return;
}

static int getPriv1(void)
{
  return priv1;
}
static int getPriv2(void)
{
  return priv2;
}


