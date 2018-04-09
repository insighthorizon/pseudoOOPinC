/* Proof that software stack can be implemented to store
   all data types
   - posibility to implement data structures in static memory */

#include <stdio.h>

int main(void)
{
  /* We have char array and it can store whatever we wish */
  long storage;
  char storage_ptr[2] = {1};

  (*(float*)storage_ptr) = 40000.0004;

  printf("%d\n",   (*(int*)storage_ptr) );
  printf("%f\n", (*(float*)storage_ptr) );
  printf("%d\n", sizeof(float));


  
  return 0;
}
