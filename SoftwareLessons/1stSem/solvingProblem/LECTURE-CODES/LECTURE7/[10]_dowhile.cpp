//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// dowhile.cpp
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

    //do-while loop
    do
    {
		cout << setw(10) << left << i << setw(15) << pow(i, 3.0f) << endl; 
        i++;
    } while(i<=10);

	return 0;
}


