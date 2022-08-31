//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// random_frequency.cpp
// Program that calculates the sum of two arrays 
//==================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>					// for time() function

using namespace std;

const int M = 6;
const int N = 5;

int main()
{
	int A[M][N];
    int B[M][N];
    int C[M][N];

	srand(time(0));

	// Create random values between [1-10] and
	// calculate the sum of two random valued matrix
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
        {
			A[i][j] = rand() % 10 + 1; //cout << A[i][j];
            B[i][j] = rand() % 10 + 1;  //cout << B[i][j];

            C[i][j] = A[i][j] + B[i][j];  //  cout << C[i][j];
        }

	// Print matrix A values on the screen
    cout << "---------------A------------------\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(5) << A[i][j];
		cout << endl;
	}

    // Print matrix B values on the screen
    cout << "---------------B------------------\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(5) << B[i][j];
		cout << endl;
	}

    // Print matrix C values on the screen
    cout << "---------------C------------------\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(5) << C[i][j];
		cout << endl;
	}

    return 0;
}
