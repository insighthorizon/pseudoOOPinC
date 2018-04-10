#include <stdio.h>


#define DOUBLE(X) {0xFF, 0x01, X}


#ifdef __GNUC__ /* without packed attribute dont even compile - would not work */
typedef struct __attribute__((packed)){
  unsigned char a;
  unsigned char b;
  double c;
} reap_double_t;
#endif


reap_double_t double_container = 
  (reap_double_t){0xFF, 0x01, 358.488}; 




int crunch_data(unsigned char *x){
  printf("%d\n", *x);
  printf("%d\n", *(x+1));
  printf("%f\n", *((double*)(x+2)));  

  return 0;
}



int main(void)
{
  // (*(double*)(polyContainer+2)) = 3.14; 


  /*
  
  printf("%d\n", *((unsigned char*)&polyContainer));
  printf("%d\n", *(((unsigned char*)&polyContainer+1)));
  printf("%f\n", (*(double*)(((unsigned char*)&polyContainer+2))));

  for(int i = 0; i < sizeof(double); i++)
  {
    printf("0x%04x,", *(((unsigned char*)(&polyContainer)+2 + i)));
  }
  printf("\n");
  printf("%04x\n", *(((unsigned char*)(&polyContainer)+2+sizeof(double))));
  */


  printf("-----\n");
  (void)crunch_data((unsigned char*)&((reap_double_t){0x0F,0x10, 3.45})); // MACRO(DOUBLE(3.45))
  (void)crunch_data((unsigned char*)&double_container); //pack this into macro MACRO(double_container)

  /* at the end first idea with structure concept should be used with this argument inserting above - MACRO(DOUBLE(...)) */

  
  return 0;
}
