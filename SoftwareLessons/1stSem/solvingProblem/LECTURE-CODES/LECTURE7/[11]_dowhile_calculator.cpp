//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// dowhile_calculator.cpp
// Program that calculates four basic operations 
// until an exit key is entered
//==================================================

#include <iostream>
using namespace std;

struct product
{
	int modelNumber;
	int partNumber;
	float price;
};

int main()
{
	int age[4];

	
	
	product product1={5235, 98, 153.5f};	// define product1 struct variable		
	product1.partNumber = 2020;				// assign first product part number as 2020

	product product2;						// define product2 struct variable
	product2=product1;						// assign first struct variables values to second

	char operation, ch;
	float number1, number2;

	do {
		cout << "Enter an operation (+, -, *, /): ";
		cin >> operation;

		cout << "Enter two numbers: ";
		cin >> number1 >> number2;

		switch (operation)
		{
		case '+': cout << number1 << " + " << number2 << " = " << number1 + number2; break;
		case '-': cout << number1 << " - " << number2 << " = " << number1 - number2; break;
		case '*': cout << number1 << " * " << number2 << " = " << number1 * number2; break;
		case '/': cout << number1 << " / " << number2 << " = " << number1 / number2; break;
		default : cout << "ERROR!..."; break;
		}
		
		do {
			cout << "\nAnother Operation (y/n) : ";
			cin >> ch;
		} while (!(ch == 'y' || ch == 'n'));

	} while (ch != 'n');

	return 0;
}


