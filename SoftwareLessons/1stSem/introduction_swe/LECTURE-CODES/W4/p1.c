// Program: Variables revisited
// Date: 22.10.21

#include<stdio.h>

int main()
{
  int a;  // Type  and name

  a = 45; // Assignment statement

  int *aPtr; // Pointer variable (address variable)

  aPtr = &a;

  printf("a = %d and address of a = 0x%x\n", a, aPtr);

  a = 85;  
 
  return 0;
}
