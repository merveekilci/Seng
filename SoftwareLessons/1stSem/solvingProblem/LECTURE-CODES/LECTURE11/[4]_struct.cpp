//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Functions - Parameter as struct
// struct.cpp
//==================================================

#include <iostream>
using namespace std;

struct complexNumber{
	int real;
	int imaginary;
};

void writeComplexNumber (complexNumber);

int main()
{
	complexNumber number = {10,20};

	writeComplexNumber (number);

	return 0;
}

void writeComplexNumber (complexNumber complex)
{
	cout << complex.real << "i + " << complex.imaginary;
}

