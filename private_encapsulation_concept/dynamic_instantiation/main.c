#include <stdio.h>
#include <stdlib.h>

int SWstack[1000] = {0};
int *SWstack_pointer = SWstack;

/* Types for partycular classes */
/* Class called className1 */
typedef struct{
  int *pubVar1;
  int (*privVar1getter)(void);
  void (*privVar1setter)(int);
}className1_publicObjectMembers_t;
typedef struct{
  int pubVar1;
}className1_publicData_t;
typedef struct{
  int privVar1;
}className1_privateData_t;
/* Class called className2 */
typedef struct{
  int *pubVar1;
  int (*privVar1getter)(void);
  void (*privVar1setter)(int);
}className2_publicObjectMembers_t;
typedef struct{
  int pubVar1;
}className2_publicData_t;
typedef struct{
  int privVar1;
}className2_privateData_t;

/* Generic interface type and class list */
typedef enum{
  CLASS_NAME1 = 9999,
  CLASS_NAME2,
}className_t;
typedef struct{
  className_t class;
  int *publicData;
  int *privateData;
}instanceInterface_t;

/* Pointer used every time any instance of any class is acessed - we must tell to the function where is the objects data ... */
int *objectPublicContentPointer;
int *objectPrivateContentPointer;

/* className1 functions */
int className1privVar1getter(void)
{
  ((className1_publicData_t*)objectPublicContentPointer)->pubVar1 = 0;
  return ((className1_privateData_t*)objectPrivateContentPointer)->privVar1;
}
void className1privVar1setter(int x)
{
  ((className1_publicData_t*)objectPublicContentPointer)->pubVar1 = 1;
  ((className1_privateData_t*)objectPrivateContentPointer)->privVar1 = x;
}
/* ClassName2 functions */
int className2privVar1getter(void)
{
  ((className2_publicData_t*)objectPublicContentPointer)->pubVar1 = 0;  
  return ((className2_privateData_t*)objectPrivateContentPointer)->privVar1;
}
void className2privVar1setter(int x)
{
  ((className2_publicData_t*)objectPublicContentPointer)->pubVar1 = 1;
  ((className2_privateData_t*)objectPrivateContentPointer)->privVar1 = x;
}



/* Entry points for classes */
className1_publicObjectMembers_t className1(instanceInterface_t instanceName)
{
  if(instancename.class == class_NAME1)
    {
      objectPublicContentPointer = instanceName.publicData;
      objectPrivateContentPointer = instanceName.privateData;
      return (className1_publicObjectMembers_t){&((className1_publicData_t*)objectPublicContentPointer)->pubVar1, className1privVar1getter, className1privVar1setter };
    }
  else{printf("This is not instance of that class!\n"); exit(EXIT_FAILURE); }  
}
className2_publicObjectMembers_t className2(instanceInterface_t instanceName)
{
  if(instanceName.class == CLASS_NAME2)
    {
      objectPublicContentPointer = instanceName.publicData;
      objectPrivateContentPointer = instanceName.privateData;
      return (className2_publicObjectMembers_t){&((className2_publicData_t*)objectPublicContentPointer)->pubVar1, className2privVar1getter, className2privVar1setter };      
    }
  else{printf("This is not instance of that class!\n"); exit(EXIT_FAILURE); }
}

/* Instantiator macros */
#define INSTANTIATE_CLASS1(NAME, PUB1INIT_VALUE, PRIV1INIT_VALUE) \
  className1_publicData_t className1_publicData_t_##NAME = (className1_publicData_t){PUB1INIT_VALUE}; \
  className1_privateData_t className1_privateData_t_##NAME = (className1_privateData_t){PRIV1INIT_VALUE}; \
instanceInterface_t NAME = \
  (instanceInterface_t){CLASS_NAME1, (int*)&className1_publicData_t_##NAME, (int*)&className1_privateData_t_##NAME};
#define INSTANTIATE_CLASS2(NAME, PUB1INIT_VALUE, PRIV1INIT_VALUE) \
className2_publicData_t className2_publicData_t_##NAME = (className2_publicData_t){PUB1INIT_VALUE}; \
 className2_privateData_t className2_privateData_t_##NAME = (className2_privateData_t){PRIV1INIT_VALUE}; \
instanceInterface_t NAME = \
  (instanceInterface_t){CLASS_NAME2, (int*)&className2_publicData_t_##NAME, (int*)&className2_privateData_t_##NAME};


void tryIt(void)
{
  int *stackPointerMark = SWstack_pointer;
  /* Local implementation */
  INSTANTIATE_CLASS1(className1_instance_a, 11, 12)
    
  INSTANTIATE_CLASS1(className1_instance_b, 13, 14)
    
  INSTANTIATE_CLASS2(className2_instance_a, 21, 22)
    
  INSTANTIATE_CLASS2(className2_instance_b, 23, 24)

    /* This should work */
  printf("%d\n", *className1(className1_instance_a).pubVar1 );
  printf("%d\n", className1(className1_instance_a).privVar1getter() );
  printf("%d\n", *className1(className1_instance_a).pubVar1 );
  className1(className1_instance_a).privVar1setter(234);
  printf("%d\n", *className1(className1_instance_a).pubVar1 );
  printf("%d\n", className1(className1_instance_a).privVar1getter() );
  printf("\n");

  printf("%d\n", *className1(className1_instance_b).pubVar1 );
  printf("%d\n", className1(className1_instance_b).privVar1getter() );
  printf("%d\n", *className1(className1_instance_b).pubVar1 );
  className1(className1_instance_b).privVar1setter(543);
  printf("%d\n", *className1(className1_instance_b).pubVar1 );
  printf("%d\n", className1(className1_instance_b).privVar1getter() );
  printf("\n");
    
  printf("%d\n", *className2(className2_instance_a).pubVar1 );
  printf("%d\n", className2(className2_instance_a).privVar1getter() );
  printf("%d\n", *className2(className2_instance_a).pubVar1 );
  className2(className2_instance_a).privVar1setter(78);
  printf("%d\n", *className2(className2_instance_a).pubVar1 );
  printf("%d\n", className2(className2_instance_a).privVar1getter() );
  printf("\n");
    
  printf("%d\n", *className2(className2_instance_b).pubVar1 );
  printf("%d\n", className2(className2_instance_b).privVar1getter() );
  printf("%d\n", *className2(className2_instance_b).pubVar1 );
  className2(className2_instance_b).privVar1setter(987);
  printf("%d\n", *className2(className2_instance_b).pubVar1 );
  printf("%d\n", className2(className2_instance_b).privVar1getter() );
  printf("\n");
  
  /* This should cause the wrong class error */
  className2(className1_instance_a).privVar1setter(654);
      
    
  /* End of function implementation */
  SWstack_pointer = stackPointerMark;
}

int main(void)
{
  tryIt();

  /*#ifdef _WIN32
  system("pause");
  #endif*/
  return 0;
}
