//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// enum.cpp
//==================================================

#include <iostream>
using namespace std;

enum enumDirections { NORTH, SOUTH, EAST, WEST };

int main()
{
	enumDirections direction;

	int selection;

	cout << "Enter Direction (NORTH=0, SOUTH=1, EAST=2, WEST=3) :";
	cin >> selection;

	direction = static_cast<enumDirections>(direction);

	switch (direction)
	{
		case NORTH	: cout << "NORTH"; break;
		case SOUTH	: cout << "SOUTH"; break;
		case EAST	: cout << "EAST"; break;
		case WEST	: cout << "WEST"; break;
		default		: cout << "ERROR...";
	}

	return 0;
}

