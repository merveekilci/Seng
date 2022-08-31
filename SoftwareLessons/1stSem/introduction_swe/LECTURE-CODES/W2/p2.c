// A program that calculates triangle area
#include <stdio.h>

int main()
{
  // Declaration of variables
  double base;
  double height;
  // Get values
  printf("Enter base: ");
  scanf("%lf", &base);
  printf("Enter height: ");
  scanf("%lf", &height);
  // Process the data
  printf("base = %lf, height = %lf\n", base, height);
  double surface = base * height / 2;
  
  // Output the data
  printf("Triangular area = %lf\n", surface);
}
