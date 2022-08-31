//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers & Struct
// dynamic_struct.cpp
//==================================================

#include <iostream>

using namespace std;

struct Measure
{
	int meter;
	int cmeter;
};


int main()
{
	Measure *m1 = new Measure;

	cout << "ENTER MEASURE (IN METER) : "; cin >> m1->meter;
	cout << "ENTER MEASURE (IN METER) : "; cin >> m1->cmeter;

	cout << m1->cmeter << " m " << m1->cmeter << "cm\n";
    
	return 0;
}
