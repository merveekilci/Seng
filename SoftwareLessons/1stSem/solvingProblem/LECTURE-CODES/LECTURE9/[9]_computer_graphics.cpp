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

const int M=6;
const int N=4;
const int K=4;

int main()
{
	float A[M][N]={0,3,0,1,
                   2,3,0,1,
                   0,3,3,1,
                   0,0,0,1,
                   2,0,0,1,
                   0,0,2,1};

    float B[N][K]={0.707,0,0,-0.353,
                   0,1,0,0,
                   0.707,0,0,0.353,
                   2,0,0,1};
    float C[M][K];


    // Calculate the multiplication of two random valued matrix
    float sum;
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
            {
                C[i][j]=C[i][j]/C[i][K-1];
			    cout << setw(8) << C[i][j];
            }
		cout << endl;
	}

    return 0;
}
