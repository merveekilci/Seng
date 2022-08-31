//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// OOP IN C++
//==================================================

#include <iostream>
using namespace std;

class ComplexNumber
{

	float real;
	float imaginary;
public:
    ComplexNumber();    		// constructor  //class adı ile aynı
	ComplexNumber(float,float);	// constructor with two parameters
	~ComplexNumber();			// destructor
	
	void setReal(float);
	void setImaginary(float);

	float getReal();
	float getImaginary();

	void printComplexNumber();
};

ComplexNumber::ComplexNumber()
{}

ComplexNumber::ComplexNumber(float _real, float _imaginary)
{}

ComplexNumber::~ComplexNumber()
{
	cout << "Destructor is called....";
}

void ComplexNumber::setReal(float _real)
{
	real = _real;
}

void ComplexNumber::setImaginary(float _imaginary)
{
	imaginary = _imaginary;
}


float ComplexNumber::getReal()
{
	return real;
}


float ComplexNumber::getImaginary()
{
	return imaginary;
}

void ComplexNumber::printComplexNumber() 
{
	cout << real << "+" << imaginary << "i" << endl;
}

int main()
{

}
