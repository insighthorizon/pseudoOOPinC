/* !!! - Have to compile with:
   gcc -z execstack main.c ,
   or to use mprotect to make given memory executable */

#include <stdio.h>
#ifndef _WIN32
#include <sys/mman.h>
#include <unistd.h>
#else
#include <stdlib.h>
#endif

static char storage1[1000] = {0};
static long storage1ptr = 0;

typedef struct{
  int a;
  int b;
}myStruct_t;


void (*loader( void (*sourceAddress)(void), long size ))(void)
{
  long tmp = storage1ptr;
  for (long i = 0; i < size; i++)
    {
      storage1[tmp+i] = ((char*)sourceAddress)[i];
      printf("%ld ", (long)storage1[tmp+i]);
    }
  storage1ptr += size;
  printf("\n");
  printf("%ld\n", tmp);
  return (void (*)(void))(storage1 + tmp);
}


myStruct_t myStruct_a = (myStruct_t){5,5};
myStruct_t myStruct_b = (myStruct_t){8,8};

void fun1(myStruct_t *data)
{
  printf("The a member: %d\n", data->a);
}
void fun2(myStruct_t *data)
{
  printf("The b member: %d\n", data->b);  
}

void wrapper(void)
{
  void (*fun)(myStruct_t*) = &fun2;
  myStruct_t *x = &myStruct_b;
  fun(x);
}
void endMark(void){;}
// machine code of wrapper
char wrapperCode[] =
{ 85, 72, -119, -27, 72, -125, -20, 16, 72, -57, 69, -16, 0,
  0, 0, 0, 72, -57, 69, -8, 0, 0, 0, 0, 72, -117, 85, -8, 72,
  -117, 69, -16, 72, -119, -41, -1, -48, -112, -55, -61 };
#define CODE_SIZE (long)40
#define FUN_PTR_POS (long)12
#define DATA_PTR_POS (long)20
//long sizeCode = sizeof(wrapperCode)/sizeof(wrapperCode[0]);

void (*binaryLoader( char *sourceAddress, long size, long funPtrPos, long dataPtrPos, void (*wrappedFunction)(myStruct_t*), myStruct_t *data))(void)
{
 long tmp = storage1ptr;
  for (long i = 0; i < size; i++)
    {
      storage1[tmp+i] = sourceAddress[i];
    }
  storage1ptr += size;
  /* Here is where the real magic happens ... */
  *(int*)(storage1 + tmp + funPtrPos) = (int)(long)wrappedFunction;
  *(int*)(storage1 + tmp + dataPtrPos) = (int)(long)data;
   for (long i = 0; i < size; i++)
    {
      printf("%ld ", (long)storage1[tmp+i]);
    }
  printf("\n");
  printf("%ld\n", tmp);

  return (void (*)(void))(storage1 + tmp);
} 

char win32wrapperCode[] =
{ 85, -119, -27, -125, -20, 40, -57, 69, -12,
  0, 0, 0, 0, -57, 69, -16, 0, 0, 0, 0, -117,
  69, -16, -119, 4, 36, -117, 69, -12, -1, -48,
  -112, -55, -61 };
#define win32_CODE_SIZE (long)34
#define win32_FUN_PTR_POS (long)9
#define win32_DATA_PTR_POS (long)16

int main(void)
{
  /*    
  long size1 = (long)(((char*)&endMark) - ((char*)&wrapper));
  void (*callerA)(void) = loader(&wrapper, size1);
  callerA(); 
  */

#ifndef _WIN32
  /* These three lines of code allows execution of code without the gcc compile option, should be also more secure */
  long pageSize =  sysconf(_SC_PAGESIZE);
  long pageNumber = (long)storage1/pageSize;
  if ( mprotect((void*)(pageNumber*pageSize), (long)pageNumber+CODE_SIZE, PROT_EXEC|PROT_WRITE|PROT_READ) )
    {
      printf("mprotec failed\n");
      return 1;
    }
#endif

#ifdef _WIN32
#define WRAPPER win32wrapperCode
#define CODE_SIZE_X win32_CODE_SIZE
#define FUNPTR win32_FUN_PTR_POS
#define DATAPTR win32_DATA_PTR_POS
#else
#define WRAPPER wrapperCode
#define CODE_SIZE_X CODE_SIZE
#define FUNPTR FUN_PTR_POS
#define DATAPTR DATA_PTR_POS
#endif
  
  void (*callerA)(void) = binaryLoader(WRAPPER, CODE_SIZE_X, FUNPTR, DATAPTR, &fun1, &myStruct_a);
  void (*callerB)(void) = binaryLoader(WRAPPER, CODE_SIZE_X, FUNPTR, DATAPTR, &fun1, &myStruct_b);
  void (*callerC)(void) = binaryLoader(WRAPPER, CODE_SIZE_X, FUNPTR, DATAPTR, &fun2, &myStruct_a);
  void (*callerD)(void) = binaryLoader(WRAPPER, CODE_SIZE_X, FUNPTR, DATAPTR, &fun2, &myStruct_b);

  callerA();
  callerB();
  callerC();
  callerD();

#ifdef _WIN32
  system("pause");
#endif
  return 0;
}
