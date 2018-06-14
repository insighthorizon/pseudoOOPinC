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
            //typedef long double f96/f128; // in MINGW64 was sizeof(long double) 12 , in linux long double has 16 bytes
/* User defined data types (data structures like structures, arrays, buffers, linked lists...) */
typedef struct {
  int a;
  int b;
}myStruct_t;
typedef struct {
  int size;
  int *data; // type of array is defined by the typeIdentifier
}arrayWrapper_t;
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
  s8 s8_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##s8, (int*)&s8_polyVar_storage_##NAME};
#define OOC_UNSIGNED_CHAR8(NAME, INIT_VALUE) \
  u8 u8_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u8, (int*)&u8_polyVar_storage_##NAME};
#define OOC_SIGNED_SHORT16(NAME, INIT_VALUE) \
  s16 s16_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##s16, (int*)&s16_polyVar_storage_##NAME};
#define OOC_UNSIGNED_SHORT16(NAME, INIT_VALUE) \
  u16 u16_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u16, (int*)&u16_polyVar_storage_##NAME};
#define OOC_SIGNED_INT32(NAME, INIT_VALUE) \
  s32 s32_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##s32, (int*)&s32_polyVar_storage_##NAME};
#define OOC_UNSIGNED_INT32(NAME, INIT_VALUE) \
  u32 u32_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u32, (int*)&u32_polyVar_storage_##NAME};
#define OOC_SIGNED_LONGLONG64(NAME, INIT_VALUE) \
  s64 s64_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##s64, (int*)&s64_polyVar_storage_##NAME};
#define OOC_UNSIGNED_LONGLONG64(NAME, INIT_VALUE) \
  u64 u64_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u64, (int*)&u64_polyVar_storage_##NAME};
#define OOC_FLOAT32(NAME, INIT_VALUE) \
  f32 f32_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##f32, (int*)&f32_polyVar_storage_##NAME};
#define OOC_DOUBLE64(NAME, INIT_VALUE)	   \
  f64 f64_polyVar_storage_##NAME = INIT_VALUE; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##f64, (int*)&f64_polyVar_storage_##NAME};
#define OOC_MYSTRUCT_T(NAME, INIT_VALUE1, INIT_VALUE2) /* Multiple init values (non-scalar type)*/ \
  myStruct_t myStruct_t_polyVar_storage_##NAME = (myStruct_t){INIT_VALUE1, INIT_VALUE2};		\
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##myStruct_t, (int*)&myStruct_t_polyVar_storage_##NAME};
#define OOC_UNSIGNED_CHAR8_ARRAY(NAME, SIZE, INIT_VALUES... ) /* Needs to be variadic macro */ \
  u8 u8array_t_polyVar_storage_##NAME[SIZE] = {INIT_VALUES}; \
  arrayWrapper_t arrayWrapper_t_polyVar_wrapper_##NAME = (arrayWrapper_t){SIZE, (int*)&u8array_t_polyVar_storage_##NAME}; \
  polyVarInterface_t NAME = (polyVarInterface_t){TYPE_##u8array_t, (int*)&arrayWrapper_t_polyVar_wrapper_##NAME};

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
      printf("This is signed long long: %lld\n", *(s64*)x.data);
      break;
    case TYPE_u64:
      printf("This is unsigned long long: %lld\n", *(u64*)x.data);
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
    case TYPE_u8array_t:
      {
      u32 u32_temp_size = ((arrayWrapper_t*)x.data)->size;
      printf("This is array of %d unsigned chars:\n", u32_temp_size);
      for(int i = 0; i < u32_temp_size; i++)
	{
	  printf("%d", ((char*)((arrayWrapper_t*)x.data)->data)[i]);
	}
      printf("\n");
      }
      break;
    }
  return 0;
}


void useMyCrap(void)
{

  OOC_DOUBLE64(newVar, 0.99)
    
  OOC_MYSTRUCT_T(newStruct, 10, 20)
    
  OOC_UNSIGNED_CHAR8_ARRAY(new_u8array, 20, 0)

  u8 u8_temp_err = 0;
  u8_temp_err = polymorphicFun( newVar );
  printf("%s\n", (u8_temp_err == 0) ?"ok":"error" );
  u8_temp_err = polymorphicFun( newStruct );
  printf("%s\n", (u8_temp_err == 0) ?"ok":"error" ); 
  u8_temp_err = polymorphicFun( new_u8array );
  printf("%s\n", (u8_temp_err == 0) ?"ok":"error" ); 

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
