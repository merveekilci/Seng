//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Program that writes prime numbers between [1-100]
// prime_ex.cpp
//==================================================

#include <iostream>
using namespace std;

int main()
{	
	bool prime;				// variable that controls whether number is prime or not
	short counter = 0;		// control variable that ensures three prime numbers in a row
	
	for (int i = 1; i <= 100; i++)
	{
		// the number is initially assumed to be prime
		prime = 1;
		for (int j = 2; j < i; j++)
		{
			// controls whether number(i.e., i) is prime or not 
			if (i%j == 0)
			{
				// if number is not prime, variable 'prime' is set to 0
				// and the inner loop is ended 
				prime = 0;
				break;
			}
		}
		
		// if number is prime, so variable 'prime' is true(1)  
		if (prime)
		{
			cout << i << "   ";
			counter++;

			// if value of counter is 3, than passes to new line 
			if (counter % 3 == 0)	cout << endl;
		}
	}

	return 0;
}


