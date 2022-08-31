//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Functions - Parameter as array
// struct.cpp
//==================================================

#include <iostream>
using namespace std;

const int MAX = 10;


float getAverage (int[]);

int main()
{
	int A[MAX] = {3, 11, 6, 7, 8, 10, 4, 17, 9, 1};

	cout << "AVERAGE OF NUMBERS....: " << getAverage(A);

	return 0;
}

float getAverage (int numbers[])
{
   	float total;
   
   	for (int i=0;i<MAX;i++)
		total+=numbers[i];

	return total/MAX;
}

