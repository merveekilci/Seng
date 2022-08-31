//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// for_numbers.cpp
// Program that calculates the average
// of odd and even numbers from 1 to 1000
//==================================================

#include <iostream>
using namespace std;

int main()
{
	int sumOfOddNumbers = 0;
    int sumOfEvenNumbers = 0;

    int oddCounter=0;
    int evenCounter=0;

	for (int i = 1; i <= 1000; i++)
	{
		if (i % 2 == 0)		
		{
			sumOfEvenNumbers += i;
			evenCounter++;
		}
		else
		{
			sumOfOddNumbers += i;
			oddCounter++;
		}
	}

	cout << "Sum of Even Numbers between [0-1000]  : " << sumOfEvenNumbers << endl;
	cout << "Sum of Odd Numbers between [0-1000]  : " << sumOfOddNumbers << endl << endl;

	cout << "Average of Even Numbers between [0-1000] : " << sumOfEvenNumbers / evenCounter << endl;
	cout << "[0-1000] arasındaki tek sayıların ortalaması  : " << sumOfOddNumbers / oddCounter << endl;

	return 0;
}


