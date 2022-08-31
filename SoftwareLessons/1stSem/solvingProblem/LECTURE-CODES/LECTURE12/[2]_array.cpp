//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers & Arrays
// array.cpp
//==================================================

#include <iostream>
using namespace std;

const int MAX = 5;

int main()
{
	int number = 15;
    int *numberPtr ;

    numberPtr = &number;
    *numberPtr = 20;            // number = 20
    
    int numbers[MAX] = {0};
	int *p;
	
    p = numbers;  *p = 10;      // p[0] = 10
	p++;  *p = 20;              // p[1] = 20
	p = &numbers[2];  *p = 30;  // p[2] = 30
	p = numbers + 3;  *p = 40;  // p[3] = 40
	p = numbers;  *(p + 4) = 50;// p[4] = 50
	
    for (int n = 0; n < 5; n++)
		cout << numbers[n] << ", ";

	cout << "numbers                             : " << numbers << endl
		 << "address of numbers[0]               : " << &numbers[0] << endl
		 << "size of pointer variable of numbers : " << sizeof(numbers) << endl<<endl;

	cout << "number                              : " << number << endl
		 << "address of number                   : " << numberPtr << endl
		 << "size of pointer variable of number  : " << sizeof(numberPtr) << endl<< endl;

	return 0;
}
