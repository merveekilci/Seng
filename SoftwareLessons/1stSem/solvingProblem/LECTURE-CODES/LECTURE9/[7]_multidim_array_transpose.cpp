//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// random_frequency.cpp
// Program that calculates 
// the transpose of a MxN matrix
//==================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>					// for time() function

using namespace std;

const int M    = 6;
const int N = 5;

int main()
{
	int matrix[M][N];
    int transpose[N][M];

	srand(time(0));

	// Create random values between [1-10] and
	// calculate the transpose of the random valued matrix
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = rand() % 10 + 1;
			transpose[j][i] = matrix[i][j];
		}

	// Print matrix values on the screen
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(5) << matrix[i][j];
		cout << endl;
	}

    cout << "----------------------------------\n";

    // Print transpose values on the screen
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(5) << transpose[i][j];
		cout << endl;
	}    

	return 0;
}
