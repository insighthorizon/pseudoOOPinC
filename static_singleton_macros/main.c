#include <stdio.h>
#include "singleton1.h"


int main(int argc, char **argv)
{
  printf("%d ", singleton1.pubVar1);
  printf("%d\n", singleton1.pubVar2);
  singleton1.pubFun1();
  
  printf("%d ", singleton1.pubVar1);
  printf("%d\n", singleton1.pubVar2);
  singleton1.pubFun2();
  
  printf("%d ", singleton1.pubVar1);
  printf("%d\n", singleton1.pubVar2);
  singleton1.pubFun3(1, 2);

  printf("%d ", singleton1.pubVar1);
  printf("%d\n", singleton1.pubVar2);
  singleton1.pubFun1();
  singleton1.pubFun2();
  
  return 0;
}
