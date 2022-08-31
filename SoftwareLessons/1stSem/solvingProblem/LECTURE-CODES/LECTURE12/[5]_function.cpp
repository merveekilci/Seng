//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers as Function Parameters 
// string.cpp
//==================================================

#include <iostream>

using namespace std;

void centimize(double*);  

const int MAX = 5;

void increase_by_value(int);
void increase_by_reference(int*);

int main()
{
	int x=10;
	cout << "First value of 'x' : " << x << "\n\n";
	
	increase_by_value(x);

	cout << "function call by value\n";
	cout << "Increase 'x'       : " << x << "\n\n";

	increase_by_reference(&x);
	
	cout << "function call by reference\n";
	cout << "Increase 'x'       : " << x << "\n\n";

	return 0;
}

void increase_by_value(int value)
{
	value++;
}

void increase_by_reference(int* value)
{
	(*value)++;
}

