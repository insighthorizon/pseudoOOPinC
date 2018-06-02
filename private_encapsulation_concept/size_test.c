/* ALL POINTERS HAVE SAME SIZE
   .... EVEN STRUCT POINTERS 8 byte */


#include <stdio.h>
#include <stdlib.h>


typedef struct{
  char affs;
  char wfwe;
  char wre;
  float wefwef;
  float wefweff;
  double wfwefw;
  void (*func)(void);
} mystruct_t;


int main()
{
  
  //t is at least 64 bits in size. Specifi
  int* int_pointer;    // an integer pointer
  float* float_pointer;  //a float pointer
  char* char_pointer;   //a character pointer
  double* double_pointer;
  mystruct_t* struct_pointer;
  void (*func_ptr)(void);
  printf("size of an int pointer =  %ld\n", sizeof(int_pointer));
  printf("size of an float pointer =  %ld\n", sizeof(float_pointer));
  printf("size of an char pointer =  %ld\n", sizeof(char_pointer));
  printf("size of an double pointer =  %ld\n", sizeof(double_pointer));
  printf("size of an my struct  pointer =  %ld\n", sizeof(struct_pointer));
  printf("size of an func pointer =  %ld\n", sizeof(func_ptr));
  return 0;
}
