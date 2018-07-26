#include <stdio.h>
#include "singleton1.h"


int main(int argc, char **argv)
{
  printf("%d ", mySingleton.pubVar1);
  printf("%d\n", mySingleton.pubVar2);
  mySingleton.pubFun1();
  
  printf("%d ", mySingleton.pubVar1);
  printf("%d\n", mySingleton.pubVar2);
  mySingleton.pubFun2();
  
  printf("%d ", mySingleton.pubVar1);
  printf("%d\n", mySingleton.pubVar2);
  mySingleton.pubFun3(1, 2);

  printf("%d ", mySingleton.pubVar1);
  printf("%d\n", mySingleton.pubVar2);
  mySingleton.pubFun1();
  mySingleton.pubFun2();
  
  return 0;
}
