/* AS very last think maybe implement veryfication of argument - something like
   if(second char is given value also) - to verify that we past right address and not something random */

#include <stdio.h>

enum container_types {INT_t = 1, FLOAT_t, DOUBLE_t};

#define INT_c(X) ((int_container_t){INT_t, X}) /* container macro */
#define INT_pt(X) {.i_container = INT_c(X)} /* polytype macro */

#define FLOAT_c(X) ((float_container_t){FLOAT_t, X})
#define FLOAT_pt(X) {.f_container = FLOAT_c(X)}

#define DOUBLE_c(X) ((double_container_t){DOUBLE_t, X})
#define DOUBLE_pt(X) {.d_container = DOUBLE_c(X)}




typedef struct{
  unsigned short identifier;
  int data;
} int_container_t;
typedef struct{
  unsigned short indentifier;
  float data;
} float_container_t;
typedef struct{
  unsigned short identifier;
  double data;
} double_container_t;

typedef union{
  int_container_t i_container;
  float_container_t f_container;
  double_container_t d_container;
/*int sheeet[128];*/
} polytype_t;

/* array of function pointers of extraction of any data type from polytype container */





polytype_t my_polyVar = DOUBLE_pt(7.48);

double_container_t my_double = DOUBLE_c(5.25); 




polytype_t crunch_data(polytype_t x_interface){
unsigned short identifier = *(unsigned short*)&x_interface;

printf("Identifier: %d\n", identifier);
if((*((unsigned short*)&x_interface)) == DOUBLE_t){
/* Shadow the interface */
double x = (double)x_interface.d_container.data;
/* user code */
x = 3*x;
printf("Data: %f\n", x);
/* end of user code */
/* return values back to the interface */
x_interface.d_container.data = x;
}

return x_interface;
}



int main(void)
{
polytype_t polyVar2;
polytype_t polyVar3 = DOUBLE_pt(184.48);

  printf("-----\n");
(void)crunch_data((polytype_t)DOUBLE_pt(35.35));
polyVar2 = crunch_data(my_polyVar); 
printf("%f\n", (double)polyVar2.d_container.data);
printf("%d\n", sizeof(polyVar2));
printf("%d\n", sizeof(my_polyVar));
printf("%d\n", sizeof(polytype_t));
printf("%d\n", sizeof(polyVar3));
  
  return 0;
}
