//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Program that calculates  the square root of 
// the number entered from the keyboard according 
// to the estimated square root and the error value.
// square_root.cpp
//==================================================

#include <iostream>
#include <iomanip>          // for setprecision()
#include <math.h>

using namespace std;

int main()
{	
	float a, x, e, b, y;

	cout << "Enter a number to calculate square its root : ";
	cin >> a;
	cout << "Enter an estimated square root value        : ";
	cin >> x;
	cout << "Enter an error value                        : ";
	cin >> e;

	do
	{
		b = (a - x * x) / (2 * x);				// calculate error
		y = x + b;								// new square root value
		cout << endl << x;
		x = y;
	} while (fabs(b) > e);

	cout << "\nSquare Root    : " 
         << setprecision(3) << y <<endl;    // last calculated square root value
	
	return 0;
}


