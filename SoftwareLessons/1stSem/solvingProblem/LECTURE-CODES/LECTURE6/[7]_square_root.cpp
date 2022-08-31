//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// square_root.cpp
// Program that calculates the square root of a number
//==================================================

#include <iostream>
// library/header for sqrt() function
#include <cmath>											

using namespace std;

int main()
{
	double number, sroot;

	cout << "Input a number : ";
	cin >> number;


	// sqrt() - for function that calculates square root	
	sroot = sqrt(number);

	cout << "square root of " << number << " is : " << sroot << endl;

	system("pause");
	return 0;
}





