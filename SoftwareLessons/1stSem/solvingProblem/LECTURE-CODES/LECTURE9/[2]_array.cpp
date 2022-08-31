//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// array.cpp
//==================================================

#include <iostream>
#include <iomanip>

using namespace std;

// #define MAX 10           // preprocessor constant declaration
//const int MAX = 10;

int main()
{
	const int MAX = 10;
    
    int numbers[MAX];

	for (int i = 0; i < MAX; i++)
		cin >> numbers[i];      // numbers[i] = i+1;
	
	for (int i = 0; i < MAX; i++)
	{
		cout << left << setw(6) << numbers[i];
		if ((i + 1) % 5 == 0)   cout << endl;
	}

	return 0;
}

