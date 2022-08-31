//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// for_numbers.cpp
// Program that calculates 
// the factorial of a given number
//==================================================

#include <iostream>
using namespace std;

int main()
{
	unsigned int number;
	unsigned long fact = 1;

	cout << "Enter A Number : "; 4
	cin >> number; 

	for (int i = 2; i <= number; i++)
		fact *= i; //2, 3, ..., number-1, number fac= fac*i 
	
	//for (int i = number; i > 0; i--)
	//	fact *= i; //number, number-1, ..., 2, 1 

	cout << number << "! = " << fact << endl;
    
	return 0;
}


