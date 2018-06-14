#include <stdio.h>
#include <stdlib.h>

/* Primitive types */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
            //typedef long double f96; // in MINGW64 was sizeof(long double) 12 ... ???
/* User defined data types (data structures like structures, arrays, buffers, linked lists...) */
typedef struct {
  int a;
  int b;
}myStruct_t;
typedef struct {
  int size;
  int *data; // type of array is defined by the typeIdentifier
}ArrayWrapper_t;
/* List of all data types */
typedef enum {
  TYPE_s8 = 9999, // High values to make less probable the  accidental input of type into the polymophic functions by programmer 
  TYPE_u8,
  TYPE_s16,
  TYPE_u16,
  TYPE_s32,
  TYPE_u32,
  TYPE_s64,
  TYPE_u64,
  TYPE_f32,
  TYPE_f64,
  /*TYPE_f96,*/
  TYPE_myStruct_t,
  TYPE_u8array_t,
}typeIdentifier_t;
/* Type for Interface to polymorphic variable */
typedef struct {
  typeIdentifier_t type;
  int *data;
}polyVarInterface_t;
/* Macros to define and initialize polymorphic variables */
#define OOC_SIGNED_CHAR8(NAME, INIT_VALUE) \
  s8 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##s8, (int*)&polyVar_storage_##NAME};
#define OOC_UNSIGNED_CHAR8(NAME, INIT_VALUE) \
  u8 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u8, (int*)&polyVar_storage_##NAME};
#define OOC_SIGNED_SHORT16(NAME, INIT_VALUE) \
  s16 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##s16, (int*)&polyVar_storage_##NAME};
#define OOC_UNSIGNED_SHORT16(NAME, INIT_VALUE) \
  u16 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u16, (int*)&polyVar_storage_##NAME};
#define OOC_SIGNED_INT32(NAME, INIT_VALUE) \
  s32 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##s32, (int*)&polyVar_storage_##NAME};
#define OOC_UNSIGNED_INT32(NAME, INIT_VALUE) \
  u32 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u32, (int*)&polyVar_storage_##NAME};
#define OOC_SIGNED_LONGLONG64(NAME, INIT_VALUE) \
  s64 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##s64, (int*)&polyVar_storage_##NAME};
#define OOC_UNSIGNED_LONGLONG64(NAME, INIT_VALUE) \
  u64 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u64, (int*)&polyVar_storage_##NAME};
#define OOC_FLOAT32(NAME, INIT_VALUE) \
  f32 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##f32, (int*)&polyVar_storage_##NAME};
#define OOC_DOUBLE64(NAME, INIT_VALUE)	   \
  f64 polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##f64, (int*)&polyVar_storage_##NAME};
#define OOC_MYSTRUCT_T(NAME, INIT_VALUE1, INIT_VALUE2) /* Multiple init values (non-scalar type)*/ \
  myStruct_t polyVar_storage_##NAME = (myStruct_t){INIT_VALUE1, INIT_VALUE2};		\
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##myStruct_t, (int*)&polyVar_storage_##NAME};
#define OOC_UNSIGNED_CHAR8_ARRAY(NAME, SIZE, INIT_VALUES... ) // needs to be variadic macro


int polymorphicFun(polyVarInterface_t x) // Example how to handle all the variants of the data type of variable
{
  switch(x.type)
    {
    default:
      return 1;
      break;
    case TYPE_s8:
      printf("This is signed char: %d\n", *(s8*)x.data);
      break;
    case TYPE_u8:
      printf("This is unsigned char: %d\n", *(u8*)x.data);
      break;
    case TYPE_s16:
      printf("This is signed short: %d\n", *(s16*)x.data);
      break;
    case TYPE_u16:
      printf("This is unsigned short: %d\n", *(u16*)x.data);
      break;
    case TYPE_s32:
      printf("This is signed int: %d\n", *(s32*)x.data);
      break;
    case TYPE_u32:
      printf("This is unsigned int: %d\n", *(u32*)x.data);
      break;      
    case TYPE_s64:
      printf("This is signed long long: %ld\n", *(s64*)x.data);
      break;
    case TYPE_u64:
      printf("This is unsigned long long: %ld\n", *(u64*)x.data);
      break;
    case TYPE_f32:
      printf("This is float: %f\n", *(f32*)x.data);
      break;
    case TYPE_f64:
      printf("This is double: %f\n", *(f64*)x.data);
      break;
    case TYPE_myStruct_t:
      printf("This is my struct: %d, %d\n", ((myStruct_t*)x.data)->a, ((myStruct_t*)x.data)->b);
      break;
    }
  return 0;
}


void useMyCrap(void)
{
OOC_DOUBLE64(newVar, 0.99)
OOC_MYSTRUCT_T(newStruct, 10, 20)

  char err = 0;
  err = polymorphicFun( newVar );
  printf("%s\n", (err == 0) ?"ok":"error" );
  err = polymorphicFun( newStruct );
  printf("%s\n", (err == 0) ?"ok":"error" ); 
}



  
int main(void)
{
  useMyCrap();



/*  
#ifdef _WIN32
  system("pause");
#endif
*/
  return 0;
}
