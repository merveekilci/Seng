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
const int MAX = 10;

int main()
{
	int numbers[MAX] = { 19, 3, 15, 7, 11, 9, 13, 5, 17, 1 };

	cout << setw(5) << "INDEX" << setw(5) << "VALUE" << endl;
    cout << "-------------------------------\n";

	for (int i = 0; i < MAX; i++)
		cout << setw(5) << i << setw(5) << numbers[i] << endl;

	return 0;
}


