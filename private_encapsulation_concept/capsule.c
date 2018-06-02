#include <stdio.h>

static int x = 10;

int *capsule_access(void)
{
  static int capsuler = 10;
  return &capsuler;
}

int abuse(void)
{
  static int *abused = (int*)0;
  if(abused == 0) { abused = capsule_access(); }
  int temp = *abused;
  (*abused)++;
  return temp;
}

int main(void)
{
  printf("%d\n", abuse());
  printf("%d\n", abuse());
  printf("%d\n", abuse());
  printf("%d\n", abuse());
  return 0;
}


/* Private variables implementations - for all instances of object */
typedef struct{
  int value1;
  int value2;
  int value3;
} private_vars_container_t;
/*  Private variables definition for actual object instances - separatedly */
private_vars_container_t *instance1_privatesACCESS(void)
{
  static private_vars_container_t privates = (private_vars_container_t){0,1,209};
  return &privates;
}
private_vars_container_t *instance2_privatesACCESS(void)
{
  static private_vars_container_t privates = (private_vars_container_t){0,1,209};
  return &privates;
}

/* Private function implementations */

/*   Private function wrappers - with reference to given private instance */


/* Public function implementations */
void setVal1(int val, private_vars_container_t *instance_privates)
{
  instance_privates->value1 = val;
}
void setVal2(int val, private_vars_container_t *instance_privates)
{
  instance_privates->value2 = val;
}
void setVal3(int val, private_vars_container_t *instance_privates)
{
  instance_privates->value3 = val;
}
/*   Public function wrappers - with reference to given private instance */
void instance1_setVal1(int val)
{
  static private_vars_container_t *priv = (private_vars_container_t*)0;
  if(priv == 0) { priv = instance1_privatesACCESS(); }
  setVal1(val, priv);
}
void instance1_setVal2(int val)
{
  static private_vars_container_t *priv = (private_vars_container_t*)0;
  if(priv == 0) { priv = instance1_privatesACCESS(); }
  setVal2(val, priv);
}
void instance1_setVal3(int val)
{
  static private_vars_container_t *priv = (private_vars_container_t*)0;
  if(priv == 0) { priv = instance1_privatesACCESS(); }
  setVal3(val, priv);
}

void instance2_setVal1(int val)
{
  static private_vars_container_t *priv = (private_vars_container_t*)0;
  if(priv == 0) { priv = instance2_privatesACCESS(); }
  setVal1(val, priv);
}
void instance2_setVal2(int val)
{
  static private_vars_container_t *priv = (private_vars_container_t*)0;
  if(priv == 0) { priv = instance2_privatesACCESS(); }
  setVal2(val, priv);
}
void instance2_setVal3(int val)
{
  static private_vars_container_t *priv = (private_vars_container_t*)0;
  if(priv == 0) { priv = instance2_privatesACCESS(); }
  setVal3(val, priv);
}
