/* Include to get acces to the object */
#include "object.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  MY_object.displayValue();
  printf("%d %d\n", MY_object.wFlag, MY_object.rFlag);

  for(int i = 4; i > 0; i--)
  {
  MY_object.insertValue();
  printf("%d %d\n", MY_object.wFlag, MY_object.rFlag);
  MY_object.displayValue();
  printf("%d %d\n", MY_object.wFlag, MY_object.rFlag);
  printf("-------------------------------------\n");
  }

  system("pause");
  
  return 0;
}
