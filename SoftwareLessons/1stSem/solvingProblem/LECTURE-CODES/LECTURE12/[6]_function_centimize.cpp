//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers as Function Parameters 
// function_centimize.cpp
//==================================================

#include <iostream>

using namespace std;

void centimize(double*);  

const int MAX = 5;

int main()
{
	//double measure=10.0;
	//centimize(&measure);

	double measure[MAX] = { 10.0, 43.1, 95.9, 59.7, 87.3 };
	
	centimize(measure);
	
	for (int j = 0; j < MAX; j++)
		cout << "measure[" << j << "]=" << measure[j] << " cm" << endl;

	system("pause");
	return 0;
}

void centimize(double* inch)
{
	//*inch= *inch * 2.54;

	for (int j = 0; j < MAX; j++)
	{
		*inch *= 2.54;
		inch++;  //points to array elements
	}
}