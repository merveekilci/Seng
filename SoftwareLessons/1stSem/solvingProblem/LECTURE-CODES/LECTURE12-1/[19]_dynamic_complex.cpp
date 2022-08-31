//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Compares dynamic string and number arrays
// Dynamic complex number array example - version 3
//==================================================

#include <iostream>
#include <ctime>
using namespace std;

struct Complex {
	int real;
	int imaginary;
};

void generateArray(Complex* n, int length);
Complex calculateSum(Complex number1, Complex number2);
void printComplexNumber(Complex number);

int main()
{
	Complex* complexNumbers;	// dynamic array

	int size; cout << "Enter size : "; cin >> size;

	complexNumbers = new Complex[size];

	generateArray(complexNumbers, size);

	Complex sum = calculateSum(complexNumbers[0], complexNumbers[1]);

	printComplexNumber(sum);

	delete[] complexNumbers;
	complexNumbers = NULL;
}

void generateArray(Complex* n, int length)
{
	srand(time(NULL));

	cout << "--------------------------------------------\n";
	for (int i = 0; i < length; i++)
	{
		// generate random numbers between 1-10
		n[i].real = rand() % 10 + 1;
		n[i].imaginary = rand() % 10 + 1;

		cout << i + 1 << ". element of the complex number array : ";
		printComplexNumber(n[i]);
		cout << "--------------------------------------------\n";
	}
}

Complex calculateSum(Complex number1, Complex number2)
{
	Complex result;

	result.real = number1.real + number2.real;
	result.imaginary = number1.imaginary + number2.imaginary;

	return result;
}

void printComplexNumber(Complex number)
{
	cout << number.real << "+"
		<< number.imaginary << "i" << endl;
}


