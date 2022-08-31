//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// compare.cpp
// Program that compares two numbers
//==================================================

#include <iostream>

using namespace std;


int main()
{
	int midterm;
	int final;

	if ((midterm<50) || (final<50))
		cout << "Failed";
	else
		cout << "Passed";
	
	int number1, number2;

	cout << "Enter two numbers: ";
	cin >> number1 >> number2;
   
	if( number1 < number2)
		cout << number1 << " is smaller than " 
		     << number2 <<"\n";
   
	if( number1 > number2)
		cout << number1 << " is bigger than " 
		     << number2 <<"\n";
	
	if( number1==number2)
		cout << number1 << " equals to " 
		     << number2 <<"\n";	
	return 0;
}

