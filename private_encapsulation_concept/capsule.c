/* CLASS NAME = obj1 */
#include <stdio.h>

#define __OBJ1_C__ /* macro that says we are inside of class named obj1 */
#include "capsule.h"
#undef __OBJ1_C__

/* Creating the object structure - uninitialized instance structure */
obj1_publics_T obj1_instance1 =
(obj1_publics_T){
  0,
  pubWrapperObj1_inst1_setVal1, pubWrapperObj1_inst1_setVal2, pubWrapperObj1_inst1_setVal3,
  pubWrapperObj1_inst1_getVal1, pubWrapperObj1_inst1_getVal2, pubWrapperObj1_inst1_getVal3,
  pubWrapperObj1_inst1_usePubVars1, pubWrapperObj1_inst1_usePubVars2, pubWrapperObj1_inst1_usePrivFun
};
obj1_publics_T obj1_instance2 =
(obj1_publics_T){
  1,
  pubWrapperObj1_inst2_setVal1, pubWrapperObj1_inst2_setVal2, pubWrapperObj1_inst2_setVal3,
  pubWrapperObj1_inst2_getVal1, pubWrapperObj1_inst2_getVal2, pubWrapperObj1_inst2_getVal3,
  pubWrapperObj1_inst2_usePubVars1, pubWrapperObj1_inst2_usePubVars2, pubWrapperObj1_inst2_usePrivFun
};


/*  Privates definiions inside function for actual object instances - separatedly */
obj1_privates_T *obj1_inst1_privatesACCESS(void)
{
  static obj1_privates_T privates = (obj1_privates_T){0,1,209, privWrapperObj1_inst1_giveInfo};
  return &privates;
}
obj1_privates_T *obj1_inst2_privatesACCESS(void)
{
  static obj1_privates_T privates = (obj1_privates_T){10,3,5, privWrapperObj1_inst2_giveInfo};
  return &privates;
}

/* Private function implementations */
static void obj1_giveInfo_privFun(obj1_publics_T *publics, obj1_privates_T *privates)
{
  printf("Info about obj1 varibles:\n");
  printf("pubVar1 (public variable) = %d\n", publics->pubVar1);
  printf("value1 (private variable) = %d\n", privates->value1);
  printf("value2 (private variable) = %d\n", privates->value2);
  printf("value3 (private variable) = %d\n", privates->value3);
}

/*   Private function wrappers - with reference to given private instance */
static void privWrapperObj1_inst1_giveInfo(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_giveInfo_privFun(&obj1_instance1, priv);
}
static void privWrapperObj1_inst2_giveInfo(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_giveInfo_privFun(&obj1_instance2, priv);
}

/* Public function implementations */
// publics - publics of own instance of object
// privates - privates of own instance of object
void obj1_setVal1(obj1_publics_T *publics, obj1_privates_T *privates,/*Here start user input variables*/ int val)
{
  privates->value1 = val;
}
void obj1_setVal2(obj1_publics_T *publics, obj1_privates_T *privates,/*Here start user input variables*/ int val)
{
  privates->value2 = val;
}
void obj1_setVal3(obj1_publics_T *publics, obj1_privates_T *privates,/*Here start user input variables*/ int val)
{
  privates->value3 = val;
}
int obj1_getVal1(obj1_publics_T *publics, obj1_privates_T *privates)
{
  return privates->value1;
}
int obj1_getVal2(obj1_publics_T *publics, obj1_privates_T *privates)
{
  return privates->value2;
}
int obj1_getVal3(obj1_publics_T *publics, obj1_privates_T *privates)
{
  return privates->value3;
}
void obj1_usePubVars1(obj1_publics_T *publics, obj1_privates_T *privates,/*Here start user input variables*/ int x)
{
  publics->pubVar1 = x;
}
int obj1_usePubVars2(obj1_publics_T *publics, obj1_privates_T *privates)
{
  return publics->pubVar1;
}
void obj1_usePrivFun(obj1_publics_T *publics, obj1_privates_T *privates)
{
  privates->giveInfo();
}

/*   Public function wrappers - with reference to given private instance */
void pubWrapperObj1_inst1_setVal1(int val)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_setVal1(&obj1_instance1, priv, val);
}
void pubWrapperObj1_inst1_setVal2(int val)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_setVal2(&obj1_instance1, priv, val);
}
void pubWrapperObj1_inst1_setVal3(int val)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_setVal3(&obj1_instance1, priv, val);
}
int pubWrapperObj1_inst1_getVal1(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_getVal1(&obj1_instance1, priv);
}
int pubWrapperObj1_inst1_getVal2(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_getVal2(&obj1_instance1, priv);
}
int pubWrapperObj1_inst1_getVal3(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_getVal3(&obj1_instance1, priv);
}
void pubWrapperObj1_inst1_usePubVars1(int x)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_usePubVars1(&obj1_instance1, priv, x);
}
int pubWrapperObj1_inst1_usePubVars2(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_usePubVars2(&obj1_instance1, priv);
}
void pubWrapperObj1_inst1_usePrivFun(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_usePrivFun(&obj1_instance1, priv);
}     

void pubWrapperObj1_inst2_setVal1(int val)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_setVal1(&obj1_instance2, priv, val);
}
void pubWrapperObj1_inst2_setVal2(int val)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_setVal2(&obj1_instance2, priv, val);
}
void pubWrapperObj1_inst2_setVal3(int val)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_setVal3(&obj1_instance2, priv, val);
}
int pubWrapperObj1_inst2_getVal1(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_getVal1(&obj1_instance2, priv);
}
int pubWrapperObj1_inst2_getVal2(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_getVal2(&obj1_instance2, priv);
}
int pubWrapperObj1_inst2_getVal3(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_getVal3(&obj1_instance2, priv);
}
void pubWrapperObj1_inst2_usePubVars1(int x)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_usePubVars1(&obj1_instance2, priv, x);
}
int pubWrapperObj1_inst2_usePubVars2(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_usePubVars2(&obj1_instance2, priv);
}
void pubWrapperObj1_inst2_usePrivFun(void)
{
  static obj1_privates_T *priv = (obj1_privates_T*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_usePrivFun(&obj1_instance2, priv);
}

int main(void)
{

  return 0;
}
