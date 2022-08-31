//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// calculator.cpp
// Program that calculates four basic operations 
// with two given numbers
//==================================================

#include <iostream>
using namespace std;

int main()
{
	char operation;
	float number1, number2;

	cout << "Enter an operation (+, -, *, /): ";
	cin >> operation;

	cout << "Enter two numbers: ";
	cin >> number1 >> number2;

	switch (operation)
	{
	case '+':
		cout << number1 << " + " << number2 << " = " << number1 + number2;
		break;
	case '-':
		cout << number1 << " - " << number2 << " = " << number1 - number2;
		break;
	case '*':
		cout << number1 << " * " << number2 << " = " << number1 * number2;
		break;
	case '/':
		cout << number1 << " / " << number2 << " = " << number1 / number2;
		break;
	default:
		// Otherwise - entered operation is not one of these {+, -, *, /}
		cout << "ERROR!...";
		break;
	}

	//switch-case structure will be implemented also by using if/else statements.
	/*
    if (operation='+')
		cout << number1 << " + " << number2 << " = " << number1 + number2;
	else if (operation = '-')
		cout << number1 << " - " << number2 << " = " << number1 - number2;
	else if (operation = '*')
		cout << number1 << " * " << number2 << " = " << number1 * number2;
	else if (operation = '/')
		cout << number1 << " / " << number2 << " = " << number1 / number2;
	else 
		cout << "ERROR!..."; 
    */
	

	return 0;
}


