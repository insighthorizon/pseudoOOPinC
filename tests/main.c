#include <stdio.h>
#include <stdlib.h>

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef long long s64;
typedef float f32;
typedef double f64;


typedef enum {
  TYPE_s8 = 1000000000,
  TYPE_u8,
  TYPE_u32,
  TYPE_s32,
  TYPE_f32,
  TYPE_f64,
  TYPE_my_struct_t,
}type_t;


typedef struct {
  type_t type;
  int *data;
}polymorphicType_t;

#define OOC_DOUBLE(NAME, INIT_VALUE)     \
  f64 polyType_storage_##NAME = INIT_VALUE; \
  polymorphicType_t NAME = (polymorphicType_t){TYPE_##f64, (int*)&polyType_storage_##NAME};


typedef struct {
  int a;
  int b;
}my_struct_t;


#define OOC_MY_STRUCT_T(NAME, INIT_VALUE1, INIT_VALUE2)		\
  my_struct_t polyType_storage_##NAME = (my_struct_t){INIT_VALUE1, INIT_VALUE2};		\
  polymorphicType_t NAME = (polymorphicType_t){TYPE_##my_struct_t, (int*)&polyType_storage_##NAME};


int polymorphicFun( polymorphicType_t x)
{
  switch(x.type)
    {
    default:
      return 1;
    case TYPE_f64:
      printf("This is double: %f\n", *(f64*)x.data); // This is how you hadnle double
      break;
    case TYPE_my_struct_t:
      printf("This is my struct: %d, %d\n", ((my_struct_t*)x.data)->a, ((my_struct_t*)x.data)->b);
    }
  return 0;
}


void useMyCrap(void)
{
OOC_DOUBLE(newVar, 0.99)
OOC_MY_STRUCT_T(newStruct, 10, 20)

  char err = 0;
  err = polymorphicFun( newVar );
  printf("%s\n", (err == 0) ?"ok":"error" );
  err = polymorphicFun( newStruct );
  printf("%s\n", (err == 0) ?"ok":"error" );
  
}



  








  
int main(void)
{
  useMyCrap();

  
/*double a = 1000000;
  int b = 128;
  *(unsigned char*)(&a) = 256;

  printf("%d\n", *(unsigned char*)(&a));
  printf("%d\n", *(int*)(&a));
  printf("%f\n", *(float*)(&a));
  printf("%f\n", *(double*)(&a));

  *(int*)(&a) = (int)(&b); // all pointers are size of integer
  printf("b is %d\n", *(int*)(*(int*)(&a)) ); */



  
#ifdef _WIN32
  system("pause");
#endif
  return 0;
}
