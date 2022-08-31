//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// struct_complex2.cpp
//==================================================

#include <iostream>
#include <iomanip>

using namespace std;

struct complexNumber
{
	double real;
	double imaginary;
};

int main()
{
	complexNumber number1, number2, result;
	number1.real = 44.426423423;
	number1.imaginary = 48;

	cout << "Enter second number's real and imaginary parts : ";
	cin  >> number2.real >> number2.imaginary;

	result.real = number1.real + number2.real;
	result.imaginary = number1.imaginary + number2.imaginary;

	cout << fixed << setprecision(2) << result.real
		 << "+" << result.imaginary << " i" << endl;
	
	//cout << fixed <<setprecision(1)<<result.real
	//     << '+' << setw(5) << right << result.imaginary << 'i' << endl;
	
	return 0;
}

