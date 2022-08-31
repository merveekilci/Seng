//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Compares dynamic string and number arrays
// Dynamic complex number array example - version 1
//==================================================

#include <iostream>
#include <ctime>
using namespace std;

struct Complex {
	int real;
	int imaginary;
};

const int MAX = 5;

int main()
{
	Complex numbers[MAX];		// static array

	Complex* dynamicNumbers;		// dynamic array

	int size;
	cout << "Enter size : "; cin >> size;

	dynamicNumbers = new Complex[size];

	srand(time(NULL));

	cout << "--------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		// generate random numbers between 1-10
		dynamicNumbers[i].real = rand() % 10 + 1;
		dynamicNumbers[i].imaginary = rand() % 10 + 1;

		cout << i + 1 << ". element of the complex number array : ";
		cout << dynamicNumbers[i].real << "+"
			<< dynamicNumbers[i].imaginary << "i\n";

		cout << "--------------------------------------------\n";
	}

	delete[] dynamicNumbers;
	dynamicNumbers = NULL;
}


