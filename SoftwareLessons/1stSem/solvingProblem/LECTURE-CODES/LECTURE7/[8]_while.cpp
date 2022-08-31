//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// while.cpp
// Program that calculates 
// third power of numbers from 1 to 10
//==================================================

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int i=1;

    while(i<=10)
    {
		cout << setw(10) << left << i << setw(15) << pow(i, 3.0f) << endl; 
        i++;
    }

    int i=1;
    int sum;

    while ( i<=10 )
    {
		sum+=i;
        i++;
    }

	return 0;
}


