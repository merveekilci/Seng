//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// for.cpp
// Program that calculates 
// third power of numbers from 1 to 10
//==================================================

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	for (int i = 1; i <= 10; i++)
		cout << setw(10) << left << i << setw(15) << pow(i, 3.0f) << endl; 
	
	return 0;
}


