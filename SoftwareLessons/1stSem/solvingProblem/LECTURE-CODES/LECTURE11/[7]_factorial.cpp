//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Functions Recursive Functions
// factorial.cpp
//==================================================

#include <iostream>
using namespace std;

unsigned long rec_factorial(unsigned int);
unsigned long it_factorial(unsigned int);


int main()
{
    unsigned int number;

	cout << "ENTER A NUMBER.......: ";
	cin >> number;

	cout << "[ITERATIVE]...." << number << "! = " << it_factorial(number) << endl;
	cout << "[RECURSIVE]...." << number << "! = " << rec_factorial(number) << endl;

	return 0;
}

int function(int k)
{
	//...
	int a;
	if (k<0)
		return a;			// return point
	else
		function (k-1);		// recursion	


unsigned long rec_factorial(unsigned int n)
{
	if (n == 1)
		return 1;
	else
		return rec_factorial(n - 1)*n;
}

unsigned long it_factorial(unsigned int n)
{
	unsigned long factorial = 1;

	for(int i=2; i<=n; i++)
		factorial*=i;

	return factorial;
}
