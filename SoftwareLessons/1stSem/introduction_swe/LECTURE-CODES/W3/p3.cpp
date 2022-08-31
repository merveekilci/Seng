// Program that calculates area of triangle
// Date: 15.10.2021

#include<iostream>
using namespace std; 
// Function prototype
double calc(int b, int h);

int main()
{
  // Input 
  cout << "Please enter the base length: ";
  int base;
  cin >> base;

  cout << "Please enter the height: ";
  int height;
  cin >>  height;

  // Calculation
  double  s;
  // Calling a function
  s = calc(base, height);

  // Output
  cout << "The area of triangle = " << s << " unit square." << endl;
  
  return 0;
}

// Function definiton
double calc(int b, int h)
{
  double surf = (b * h) / 2.0;
  return surf;
}
