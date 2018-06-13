#include <stdlib.h>
#include <stdio.h>
#include "obj1.h"


int main(void)
{
  printf("%d\n", obj1_instance1.getVal1()); 
  printf("%d\n", obj1_instance1.getVal2());
  printf("%d\n", obj1_instance1.getVal3());

  printf("%d\n", obj1_instance2.getVal1()); 
  printf("%d\n", obj1_instance2.getVal2());
  printf("%d\n", obj1_instance2.getVal3());
  printf("\n");

  obj1_instance1.setVal1(3);
  obj1_instance1.setVal2(2);
  obj1_instance1.setVal3(11);
  obj1_instance2.setVal1(3);
  obj1_instance2.setVal2(2);
  obj1_instance2.setVal3(11);

  obj1_instance1.usePrivFun();
  obj1_instance2.usePrivFun();
  printf("\n");
  
  printf("%d\n", obj1_instance1.usePubVars2() );
  printf("%d\n", obj1_instance2.usePubVars2() );
  obj1_instance1.usePubVars1(876);
  obj1_instance2.usePubVars1(876);
  printf("%d\n", obj1_instance1.usePubVars2() );
  printf("%d\n", obj1_instance2.usePubVars2() );

#ifdef _WIN32
  system("pause");
#else
  printf("\nEnd of program. Press ENTER...\n");
  getchar();
#endif
  
  return 0;
}
