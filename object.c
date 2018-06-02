/* Include dependencies - Must be at very beginning of file! (before object header include) */
#include <stdio.h> // for example

/* Include object typedef */
/* Never modify this define */
#define __PSEUDO_OBJECT_C__
#include "object.h" /* Modify this include to match the pseudoClass type name */
#undef __PSEUDO_OBJECT_C__


/* final form of this object.c file will contain only content above this comment */
/* Rest will be implemented in header                                            */
/* ------------------------------------------------------------------------------*/

/* Private and public function declarations */
/* Every function is defined just once - same for every object (instance) */
/* private */
static void printInteger(long x);
static int scanInteger(void);
/* public */
void MY_objectInsertValue(void);
void MY_objectDisplayValue(void);

/* Private variable definitions */
/* Private variables must be created and handled extra for every object (instance) */
typedef struct{
  int value;
  int cumulative;
} private_container;

static private_container MY_object_private_container = (private_container){0, 0};


#define OBJECT_INSTANCE MY_object
#define GET_PRIV(X) X ## _private_container
#define INDIRECT_GET_PRIV(X) GET_PRIV(X)
#define PRIV INDIRECT_GET_PRIV(OBJECT_INSTANCE)


/* Object instance definition 
   - contains creation of global variables */
object_t MY_object = (object_t){0, 0, MY_objectInsertValue, MY_objectDisplayValue};

/* Private function definitions */
void printInteger(long x)
{
  printf("%ld\n", x);
}

int scanInteger(void)
{
  int temp;
  scanf("%d", &temp);
  return temp;
}

/* Actual public function definitions */
void MY_objectInsertValue(void)
{
  static int x = 0;
  PRIV.value = scanInteger();
  PRIV.cumulative += (long)PRIV.value;
  MY_object.wFlag = 1;
  MY_object.rFlag = 0;
}

void MY_objectDisplayValue(void)
{
  printInteger(PRIV.value);
  printInteger(PRIV.cumulative);
  MY_object.wFlag = 0;
  MY_object.rFlag = 1;
}

