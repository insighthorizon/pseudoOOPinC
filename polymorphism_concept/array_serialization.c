/* Proof that software stack can be implemented to store
   all data types
   - posibility to implement data structures in static memory */

#include <stdio.h>

int main(void)
{
  /* We have char array and it can store whatever we wish */
  unsigned char storage_array[64]= {0};

  //  (*(unsigned char*)(storage_array)) = 3;
  (*(float*)(storage_array+1)) = 40000.0004;
  (*(double*)(storage_array+1+sizeof(float))) = 498789.49879;
  (*(unsigned char*)(storage_array+1+sizeof(float)+sizeof(double))) = 18;

  
   printf("%d\n", (*(unsigned char*)(storage_array)));
   printf("%f\n", (*(float*)(storage_array+1)) );
   printf("%f\n", (*(double*)(storage_array+1+sizeof(float))));
   printf("%d\n", (*(unsigned char*)(storage_array+1+sizeof(float)+sizeof(double))));
   printf("%d\n", (*(unsigned char*)(storage_array+40)));
  
  return 0;
}


/*
  // This is how you can store anything into double...
  double a = 1000000;
  int b = 128;
  *(unsigned char*)(&a) = 256;

  printf("%d\n", *(unsigned char*)(&a));
  printf("%d\n", *(int*)(&a));
  printf("%f\n", *(float*)(&a));
  printf("%f\n", *(double*)(&a));

  *(int*)(&a) = (int)(&b); // all pointers are size of integer
  printf("b is %d\n", *(int*)(*(int*)(&a)) ); */
