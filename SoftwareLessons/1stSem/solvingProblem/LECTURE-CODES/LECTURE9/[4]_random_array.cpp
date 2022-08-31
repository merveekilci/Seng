//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// random.cpp
// Program that does generates random numbers
//==================================================

#include <iostream> 
#include <iomanip> 
#include <stdlib.h>
#include <ctime>					// for time() function
//#define MAX 10

using namespace std;

const int MAX = 10;

int main()
{
	int numbers[MAX];
	 
	cout << setw(5) << "INDEX" << setw(10) << "VALUE" << endl;

	srand(time(NULL));						

	for (int i = 0; i < MAX; i++)
	{
		numbers[i] = rand() % 100;			
		cout << setw(3) << i << setw(10) << numbers[i] << endl;
	}

	system("pause");

	return 0;
}

