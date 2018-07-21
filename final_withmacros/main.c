#include <stdio.h>
#include "class1.h"

// Just testing for bugs

void Fun1(void)
{
  // Instantiation
  static class1_t myInst1 = {0, 0, {0, 0} };
  
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
  // Instantiation
  class1_t myInst = {3, 4, {1, 2} };

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
