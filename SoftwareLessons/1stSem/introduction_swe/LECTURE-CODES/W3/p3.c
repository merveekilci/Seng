// Program that calculates area of triangle
// Date: 15.10.2021

#include<stdio.h>
// Function prototype
double calc(int b, int h);

int main()
{
  // Input 
  printf("Please enter the base length: ");
  int base;
  scanf("%d", &base);

  printf("Please enter the height: ");
  int height;
  scanf("%d", &height);

  // Calculation
  double  s;
  // Calling a function
  s = calc(base, height);

  // Output
  printf("The area of triangle = %lf unit square.\n", s);
  
  return 0;
}

// Function definiton
double calc(int b, int h)
{
  double surf = (b * h) / 2.0;
  return surf;
}
