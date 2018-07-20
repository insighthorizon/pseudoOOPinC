#include <stdio.h>
#include "class1.h"

void Fun1(void)
{
  static class1_t myInst1 = {.pubVar1=0,.pubVar2=0,.dontuseoutside.privVar1=0,.dontuseoutside.privVar2=0};

  printf("Pub11: %d\n", myInst1.pubVar1);
  printf("Pub12: %d\n", myInst1.pubVar2);

  class1_m(&myInst1).print_privVar1();
  class1_m(&myInst1).print_privVar2();
  class1_m(&myInst1).set_privVars(10, 20);
  myInst1.pubVar1 += 1;
  
  return;
}



int main(int argc, char **argv)
{
  class1_t myInst = {.pubVar1=3,.pubVar2=4,.dontuseoutside.privVar1=1,.dontuseoutside.privVar2=2};

  printf("Pub1: %d\n", myInst.pubVar1);
  printf("Pub2: %d\n", myInst.pubVar2);

  class1_m(&myInst).print_privVar1();
  class1_m(&myInst).print_privVar2();

  class1_m(&myInst).set_privVars(10, 20);
  
  class1_m(&myInst).print_privVar1();
  class1_m(&myInst).print_privVar2();

  Fun1();
  Fun1();
  Fun1();


  return 0;
}
