//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// grade_calculator.cpp
// Program that calculates grade of a student
//==================================================

#include <iostream>
using namespace std;

int main()
{
	int		midterm, final;

	cout << "Enter midterm and final exam grades : ";
	cin >> midterm >> final;

	float	average = (midterm*0.4 + final*.6);

	cout << "Your Total Grade Is : " << average << endl;

	if (average < 50 || final < 50)
		cout << "Failed..." << endl;
	else
		cout << "Passed..." << endl;

	return 0;
}