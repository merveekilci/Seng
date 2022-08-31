//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// random_frequency.cpp
// Program that calculates 
// the frequency of a number in an array
//==================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>					// for time() function

using namespace std;

const int ROW    = 6;
const int COLUMN = 5;

int main()
{
	int matrix[ROW][COLUMN];

	srand(time(0));

	// Create random values
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COLUMN; j++)
			matrix[i][j] = rand() % 10 + 1;

	// Print values on the screen
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(5) << matrix[i][j];
		cout << endl;
	}

	cout << endl << matrix[0][0] + matrix[5][4] << endl;
	
	return 0;
}
