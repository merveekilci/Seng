//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2021 Fall Semester
//==================================================
// operators.cpp
// Program that samples 
// arithmetic assignment operators
//==================================================

#include <iostream>

using namespace std;

//************************************************************************
//**																	**
//**		STUDENT NAME...............:								**
//**		STUDENT NUMBER.............:								**
//************************************************************************



int main()
{
	int number = 27;

	number += 10;								// a = a + 10;
	number -= 7;								// a = a - 7;
	number *= 2;								// a = a * 2;
	number /= 3;								// a = a / 3;
	number %= 3;								// a = a % 3;
	cout << number << endl;

	number = 10;

	cout << "Number =" << number << endl;		// 10
	cout << "Number =" << ++number << endl;		// 11 (pre-increment)
	cout << "Number =" << number << endl;		// 11
	cout << "Number =" << number++ << endl;		// 11 (post-increment)
	cout << "Number =" << number << endl;		// 12

	system("pause");  							// display answer

	return 0;
}





