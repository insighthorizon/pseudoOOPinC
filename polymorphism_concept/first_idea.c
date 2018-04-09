#include <stdio.>

typedef struct{ /* Float polytype definition */
  int type_identifier; /* there will be asigned value to identify data type */
  float data;
  } float_poly_t;
  
/* This should be implemented for all data types including all types of arrays and structures */
  #define CREATE_FLOAT(NAME, INIT_VALUE) \
  float_poly_t NAME = (float_poly_t){0x00000001, INIT_VALUE};
  
/* all functions have to be void and their outpud passed to be also via pointers */
void read_something(int *something, int *output)
{
  if((*something) == 0x0000001) 
    /* later todo switch instead of ifs and can use enum for the identifier */
    /* later TODO lookup table that 0x000001 ... 
    ... function pointer to function implementing  void float_poly_operate(char i_or_o, int *x, float output)
                                                             if  (i_or_o)
                                                             return ((float_poly_t*)x)->data; //-for inputs 
                                                             else ((float_poly_t*)x)->data = output //-for outputs*/
  {
    if((*output) ==0x0000001)
    {
    ((float_poly_t*)output)->data = ((float_poly_t*)something)->data;
    }
  }
  printf("error!\n");
  return 1;
}

int main(void)
{
   CREATE_FLOAT(myFloat, 10)
   CREATE_FLOAT(x, 0)
  read_something(&myFloat, &x); 
  printf("%f\n", x);
   
  return 0;
}
  
  /* TODO macro CREATE_POLYVAR(TYPE, NAME, INIT_VALUE) */
