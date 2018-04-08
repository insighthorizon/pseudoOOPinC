#include <stdio.h>

static float value1 = 0;
static float value2 = 0;

#define COMMA ,

#define FUNC_PROTOTYPE(BUILD, BODY, PREFIX__)			\
  BUILD( void, setVals, float val1 COMMA float val2, PREFIX__ )		\
  BODY( value1 = val1; value2 = val2; )


#define MAGIC_BUILD(X, Y, Z, P) X Y(Z)
#define SKIP_BODY(X) ;
#define CREATE_BODY(X) {X}

// !!! For concatenating macro values - two levels of indirection
#define PASTE(X,Y) X ## _ ## Y
//#define PREFIX(X,Y) PASTE(X,Y) // !!! This would be necessary if MAFIC_POINTER used dirrectly macro with prefix value
#define MAGIC_POINTER(X, Y, Z, P)		\
  X (*PASTE(P,Y))(Z) = Y

// function prototype
FUNC_PROTOTYPE(MAGIC_BUILD, SKIP_BODY, PREFIX__)

// function pointer
#define INSTANTIATE_POINTER(PTR_NAME) FUNC_PROTOTYPE(MAGIC_POINTER, SKIP_BODY, PTR_NAME)

INSTANTIATE_POINTER(foo) // super duper user friendly macro


int main()
{
  printf("%f, %f\n", value1, value2);
  foo_setVals(3.443, 9.333);
  printf("%f, %f\n", value1, value2);


  return 0;
}


// function definition
FUNC_PROTOTYPE(MAGIC_BUILD, CREATE_BODY, PREFIX__)

