#include <stdio.>

typedef struct{ /* Float polytype definition */
  int type_identifier; /* there will be asigned value to identify data type */
  float data;
  } float_poly_t;
  
/* This should be implemented for all data types including all types of arrays and structures */
  #define CREATE_FLOAT(NAME, INIT_VALUE) \
  float_poly_t NAME = (float_poly_t){0x00000001, INIT_VALUE};
  
int read_something(int *something)
{
  if((*something) == 0x0000001)
  {
    float_poly_t temp = (float_poly_t*)something;
    return (float)something->data;
  }
  printf("Unidentified type!\n");
  return 1;
}

int main(void)
{
   CREATE_FLOAT(myFloat, 10)
   float x;
   x = read_something(&myFloat); 
  printf("%f\n", x);
   
  return 0;
}
  
  /* TODO macro CREATE_POLYVAR(TYPE, NAME, INIT_VALUE) */
