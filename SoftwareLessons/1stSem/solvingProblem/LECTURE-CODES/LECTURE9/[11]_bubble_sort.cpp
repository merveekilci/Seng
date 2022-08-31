//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// random_frequency.cpp
// Program that sorts numbers in a random array
// with bubble sort algorithm 
//==================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>					// for time() function

using namespace std;

const int MAX = 10;

int main()
{
	int A[MAX];

	srand(time(0));

    // Create random values between [1-10] of matrix A
	// and write the matrix on the screen
    for (int i = 0; i < MAX; i++)
	{
        A[i] = rand() % 10 + 1; 
		cout <<  A[i] << setw(5); 
    }

	// sort matrix A with buble sort
	int temp;

	for (int i=0; i<MAX; i++)
		for (int j=0; j<MAX-1; j++)
			if (A[j]>A[j+1])
			{
				temp  = A[j];
				A[j]= A[j+1];
				A[j+1]  = temp;
			}

	cout << "\n----------------------------------------------\n";
	
	// and write the sorted version of matrix on the screen
    for (int i = 0; i < MAX; i++)
    	cout <<  A[i] << setw(5); 

    return 0;
}
