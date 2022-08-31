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


	if (average >= 90)			// 90-100
		cout << "A";
	else if (average >= 80)     // 80-89 
		cout << "B";
	else if (average >= 70)     // 70-79  
		cout << "C";
	else if (average >= 60)     // 60-69   
		cout << "D";
	else if (average >= 50)     // 50-59
		cout << "E";
	else					    // 0 - 60   
		cout << "F";

	return 0;
}


