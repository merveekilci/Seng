//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers & String
// string.cpp
//==================================================

#include <iostream>

using namespace std;

int main()
{
	char string1[]="SAKARYA";
	char* string2 = string1;	 

	char* string3 = "2020-2021 FALL SEMESTER";

	cout << string1 << endl;
	cout << string2 << endl;
	cout << string3 << endl;

	return 0;
}
