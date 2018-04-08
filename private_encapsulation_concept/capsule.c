#include <stdio.h>

static int x = 10;

int *capsule_access(void)
{
  static int capsuler = 10;
  return &capsuler;
}

int abuse(void)
{
  static int *abused;
  if (abused == 0) {
  abused = capsule_access();
  }
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

typedef struct{
  int value1;
  int value2;
  int value3;
  void (*privFun1)(void);
  void (*privFun2)(void);
} private_container_t;

private_container_t *MY_instance_privateACCESS(void){
  static private_vars_container_t privates = (private_vars_container){0,1,209};
  return &private_vars;
}
/* Private function implementations */
/* Public function implementations */
void setVal1(int val, private_vars_container_t *instance_privates)
{
  *instance_privates.value1 = val;
}
void setVal2(int val, private_vars_container_t *instance_privates)
{
  *instance_privates.value2 = val;
}
void setVal3(int val, private_vars_container_t *instance_privates)
{
  *instance_privates.value3 = val;
}
/* Function wrappers - with reference for given private instance */
