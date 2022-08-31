//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// random_frequency.cpp
// Program that calculates 
// the multiplication of two arrays 
//==================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>					// for time() function

using namespace std;

const int M = 6;
const int N = 5;
const int K = 4;

int main()
{
	int A[M][N];
    int B[N][K];
    int C[M][K];

	srand(time(0));

    // Create random values between [1-10] of matrix A
    for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
            A[i][j] = rand() % 10 + 1; 

    // Create random values between [1-10] of matrix B
    for (int i = 0; i < N; i++)
		for (int j = 0; j < K; j++)
            B[i][j] = rand() % 10 + 1; 

	// Calculate the multiplication of two random valued matrix
    int sum;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
        {
            sum =0;
            for (int n=0; n<N; n++)
                sum += A[i][n] * B[n][j];
            C[i][j] = sum;          
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
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << setw(5) << B[i][j];
		cout << endl;
	}

    // Print matrix C values on the screen
    cout << "---------------C------------------\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
			cout << setw(5) << C[i][j];
		cout << endl;
	}

    return 0;
}
