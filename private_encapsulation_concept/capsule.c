#include <stdio.h>

/* OBJECT structure TYPEdef */
typedef struct{
  /* Global variables defined by user */
  int globVar1;
  /* Pointers to global functions */
  void (*setVal1)(int val);
  void (*setVal2)(int val);
  void (*setVal3)(int val);
  int (*getVal1)(void);
  int (*getVal2)(void);
  int (*getVal3)(void);
  void (*useGlobVars1)(int x);
  int (*useGlobVars2)(void);
}object1_t;

/* Creating the object structure - uninitialized instance structure */
object1_t object1_instance1;
object1_t object1_instance2;

/* Private variables implementations - for all instances of object */
typedef struct{
  int value1;
  int value2;
  int value3;
} obj1_privates_t;
/*  Private variables definition for actual object instances - separatedly */
obj1_privates_t *obj1_inst1_privatesACCESS(void)
{
  static obj1_privates_t privates = (obj1_privates_t){0,1,209};
  return &privates;
}
obj1_privates_t *obj1_inst2_privatesACCESS(void)
{
  static obj1_privates_t privates = (obj1_privates_t){0,1,209};
  return &privates;
}

/* Private function implementations */

/*   Private function wrappers - with reference to given private instance */


/* Public function implementations */
// globals - globals of own instance of object
// privates - privates of own instance of object
void obj1_setVal1(object1_t *globals, obj1_privates_t *privates,/*Here start user input variables*/ int val)
{
  /* USER code for FUNCTION BODY starts here */
  privates->value1 = val;
  /* USER code for FUNCTION BODY ends here */
}
void obj1_setVal2(object1_t *globals, obj1_privates_t *privates,/*Here start user input variables*/ int val)
{
  /* USER code for FUNCTION BODY starts here */
  privates->value2 = val;
  /* USER code for FUNCTION BODY ends here */
}
void obj1_setVal3(object1_t *globals, obj1_privates_t *privates,/*Here start user input variables*/ int val)
{
  /* USER code for FUNCTION BODY starts here */
  privates->value3 = val;
  /* USER code for FUNCTION BODY ends here */
}
int obj1_getVal1(object1_t *globals, obj1_privates_t *privates)
{
  /* USER code for FUNCTION BODY starts here */  
  return privates->value1;
  /* USER code for FUNCTION BODY ends here */  
}
int obj1_getVal2(object1_t *globals, obj1_privates_t *privates)
{
  /* USER code for FUNCTION BODY starts here */  
  return privates->value2;
  /* USER code for FUNCTION BODY ends here */  
}
int obj1_getVal3(object1_t *globals, obj1_privates_t *privates)
{
  /* USER code for FUNCTION BODY starts here */  
  return privates->value3;
  /* USER code for FUNCTION BODY ends here */  
}
void obj1_useGlobVars1(object1_t *globals, obj1_privates_t *privates,/*Here start user input variables*/ int x)
{
  globals->globVar1 = x;
}
int obj1_useGlobVars2(object1_t *globals, obj1_privates_t *privates)
{
  return globals->globVar1;
}
/*   Public function wrappers - with reference to given private instance */
void wrapperObj1_inst1_setVal1(int val)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_setVal1(&object1_instance1, priv, val);
}
void wrapperObj1_inst1_setVal2(int val)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_setVal2(&object1_instance1, priv, val);
}
void wrapperObj1_inst1_setVal3(int val)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_setVal3(&object1_instance1, priv, val);
}
int wrapperObj1_inst1_getVal1(void)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_getVal1(&object1_instance1, priv);
}
int wrapperObj1_inst1_getVal2(void)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_getVal2(&object1_instance1, priv);
}
int wrapperObj1_inst1_getVal3(void)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_getVal3(&object1_instance1, priv);
}
void wrapperObj1_inst1_useGlobVars1(int x)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_useGlobVars1(&object1_instance1, priv, x);
}
int wrapperObj1_inst1_useGlobVars2(void)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst1_privatesACCESS(); }
  return obj1_useGlobVars2(&object1_instance1, priv);
}

void wrapperObj1_inst2_setVal1(int val)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_setVal1(&object1_instance2, priv, val);
}
void wrapperObj1_inst2_setVal2(int val)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_setVal2(&object1_instance2, priv, val);
}
void wrapperObj1_inst2_setVal3(int val)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_setVal3(&object1_instance2, priv, val);
}
int wrapperObj1_inst2_getVal1(void)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_getVal1(&object1_instance2, priv);
}
int wrapperObj1_inst2_getVal2(void)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_getVal2(&object1_instance2, priv);
}
int wrapperObj1_inst2_getVal3(void)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_getVal3(&object1_instance2, priv);
}
void wrapperObj1_inst2_useGlobVars1(int x)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_useGlobVars1(&object1_instance2, priv, x);
}
int wrapperObj1_inst2_useGlobVars2(void)
{
  static obj1_privates_t *priv = (obj1_privates_t*)0;
  if(priv == 0) { priv = obj1_inst2_privatesACCESS(); }
  return obj1_useGlobVars2(&object1_instance2, priv);
}


int main(void)
{

  return 0;
}
