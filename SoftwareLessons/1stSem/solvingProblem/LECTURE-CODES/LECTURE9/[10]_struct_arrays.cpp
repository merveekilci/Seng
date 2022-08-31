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

struct measure {
	int meter;
	int cmeter;
};

const int MAX = 10;

int main()
{
	measure A[MAX];
    
	srand(time(0));

    // Create random values between [1-10] of matrix A
    for (int i = 0; i < MAX; i++)
	{ 
		A[i].meter = rand() % 10 + 1;
		A[i].cmeter = rand() % 10 + 1;
	} 

    return 0;
}
