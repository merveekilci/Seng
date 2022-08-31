//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// dowhile_root.cpp
// Program that calculates 
// third power of numbers from 1 to 10
//==================================================
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int power = 1;							// assign initial value fourth power as 1
	int number = 1;               			// counts numberw whose fourth power is smaller than 10.000

	while (power < 10000)            		// continues as long as the fourth power of the number is less than 10.000
	{
		cout << setw(2) << number;
		cout << setw(5) << power << endl;   // write the fourth power of number
        ++number;                          	// increase number by 1 for the next power value
		power = pow(number,4);              // calculate fourth power of number
    }

	return 0;
}


