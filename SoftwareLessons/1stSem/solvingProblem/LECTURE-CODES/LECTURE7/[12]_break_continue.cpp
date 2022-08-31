//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// break_continue.cpp
//==================================================

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int i; 

	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			break;
			//continue;
		cout << setw(10) << left << i 
		     << setw(15) << pow(i, 3.0f) << endl;
	}

	cout << "i = " << i << endl;

	return 0;
}


