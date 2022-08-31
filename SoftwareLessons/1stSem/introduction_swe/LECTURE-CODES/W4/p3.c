// Scope and life span of a variable
#include<stdio.h>
// Function prototypes
void foo1(int);
void foo2();
void foo3();

int b; // Global variable (be careful)

int main()
{
  int a, c; // Local variable declaration
  a = 45; // assignment a value
  b = 3;


  { // Block
    int k;
    k = 23;
     printf("k = %d\n", k);
  }

  
  printf("a = %d, b = %d, c = %d\n", a, b, c); // printing the local variable a
  foo1(a); // calling foo1


  foo2();
  foo2();

  foo3();
  foo3();

  return 0;
}

// Call by value
void foo1(int m)
{
  printf("inside foo1 a = %d\n", m);
}

void foo2()
{
  int s = 0;
  s++;
  printf("foo2 s = %d\n", s);
}

void foo3()
{
  static int r = 0;
  r++;
  printf("foo3 r = %d\n", r);
}
