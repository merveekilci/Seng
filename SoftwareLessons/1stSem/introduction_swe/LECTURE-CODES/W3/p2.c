// Sample program
// Date: 15.10.2021

#include<stdio.h>

//Global scope
int a;
double const PI = 3.14;

int main()
{
  // Local variables
  int b = 22;
  char c = 'c';
  float d = -4.56; 
  double dd = 78.34;
  short e = -56;
  long f = 5426326;

  unsigned int k = 234;
  unsigned char l = 34;
  unsigned long m = 234343;
  unsigned short n = 2341;


  printf("This is %d bytes integer, its value is = %d\n", sizeof(int), b);
  printf("This is %d byte integer, its value as char is = %c, as int = %d\n", sizeof(char), c, c);
  printf("This is %d float, its value is = %f\n", sizeof(float), d);
  printf("This is %d double, its value is = %lf\n", sizeof(double), dd);
  printf("This is %d short, its value is = %d\n", sizeof(short), e);
  printf("This is %d long, its value is = %d\n", sizeof(long), b);

  // Hexodecimal representation
  printf("Hexodecimal value of integer %d,  is = 0x%x\n", b, b);
 

  return 0;
}
