//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// struct_complex1.cpp
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
	complexNumber number1, number2;
	number1.real = 44.423423423;
	number1.imaginary = 48;

	
	cout << fixed << setprecision(3) << number1.real
		<< ' + ' << number1.imaginary << "i" << endl;

	//cout <<scientific<<setprecision(3)
	//	   <<number1.real<<'+'<<setw(5)<<right
	//     <<number1.imaginary<<'i'<<endl;

	cout << sizeof(number1) << "    " << sizeof(int) << endl;

	return 0;
}

