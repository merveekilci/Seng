//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Functions - Return a value
// return.cpp
//==================================================

#include <iostream>
using namespace std;

float toLibre(float);

int main()
{
    float libre, kilo;  

	cout << "Enter a Weight (kg) : ";
	cin >> kilo;

	libre = toLibre(kilo);
	cout << "Weight as libre : " << libre << "lb\n";

	return 0;
}

float toLibre(float kg)
{
	float lb = kg / 0.453592f;
	return lb;
}


