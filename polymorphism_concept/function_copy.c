/* !Have to compile with:
  gcc -z execstack main.c */
  
#include <stdio.h>

typedef struct{
  int a;
  int b;
} struct_t;

void tiskni(){ printf("Tisknu\n"); }

void seeMe(struct_t *x)
{
  void (*fun)(void) = &tiskni;
  fun();
  x->a++;
  x->b++;
}
void end_mark(void) {;}

int main(void)
{
  int size = 0;
  int *startAdd = (int*)&seeMe;
  size = (int)((int*)&end_mark - startAdd);
  int storage[100] = {0};
  printf("%d\n", size);




  for (int i = 0; i <= size; i++)
    {
      storage[i] = startAdd[i];
      printf("%d\n", i);

    }
  

  void (*caller)(struct_t*) = (void (*)(struct_t*))storage;

  for (int i = 0; i <= size; i++)
    {
  printf("%d\n", ((int*)&seeMe)[i]);
  printf("%d\n", ((int*)caller)[i]);
    }
  
  struct_t myStruct = (struct_t){0,1};

  
  caller(&myStruct);
  printf("%d %d\n", myStruct.a, myStruct.b);
  caller(&myStruct);
  printf("%d %d\n", myStruct.a, myStruct.b);
  caller(&myStruct);
  printf("%d %d\n", myStruct.a, myStruct.b);
  caller(&myStruct);
  printf("%d %d\n", myStruct.a, myStruct.b);

  return 0;
}
