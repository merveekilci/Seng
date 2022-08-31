// Sample program
// Date: 15.10.2021

#include<stdio.h>

//Global scope
int a;
double const PI = 3.14;

int main()
{
  // Local variables
  int b;
  char c;
  float d;
  double dd;
  short e;
  long f;

  unsigned int k;
  unsigned char l;
  unsigned long m;
  unsigned short n;

  
  printf("The size of int =%d\n", sizeof(int));
  int size = sizeof(double);
  printf("The size of int =%d\n", size);
}
