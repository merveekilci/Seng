//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Program that calculates whether a number 
// entered from keyboard is prime or not
// prime.cpp
//==================================================

#include <iostream>
using namespace std;

int main()
{	
	int number;
	bool prime;				// variable that controls whether number is prime or not

	cout << "Enter a number : ";
	cin >> number;

	// the number is initially assumed to be prime
	prime = 1;
	for (int i = 2; i < number; i++)
	{
		// sayının asal olup olmadığını kontrol etme
		if (number % i == 0)
		{
			// if number is not prime, variable 'prime' is set to 0
			// and the inner loop is ended 
			prime = 0;
			break;
		}
	}
		
	// if number is prime, so variable 'prime' is true(1)  
    if (prime)
		cout << number << " is prime..." << endl;
	else
		cout << number << " is not prime..." << endl;

	return 0;
}


