#include <stdio.h>
#include "myClass.h"

/* you should never access object data dirrectly,
   always use them only through object methods  */

void Fun1(void)
{
  static myClass_t myInst1 = {.var1=0,.var2=0};

  printf("var11: %d\n", myInst1.var1);
  printf("var12: %d\n", myInst1.var2);

  myClass_m(&myInst1).printVar1();
  myClass_m(&myInst1).printVar2();
  myInst1.var1 += 1;
  myInst1.var2 += 1;
  
  return;
}



int main(int argc, char **argv)
{
  myClass_t myInst = {.var1=3,.var2=4};

  printf("1: %d\n", myInst.var1);
  printf("2: %d\n", myInst.var2);

  myClass_m(&myInst).printVar1();
  myClass_m(&myInst).printVar2();

  myClass_m(&myInst).setVars(10, 20);
  
  myClass_m(&myInst).printVar1();
  myClass_m(&myInst).printVar2();

  Fun1();
  Fun1();
  Fun1();


  return 0;
}
