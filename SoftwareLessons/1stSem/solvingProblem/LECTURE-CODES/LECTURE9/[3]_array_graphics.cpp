//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// array_graphics.cpp
// Program that creates graphics of array elements
//==================================================

#include <iostream>
#include <iomanip>

using namespace std;

// #define MAX 10           // preprocessor constant declaration
//const int MAX = 10;

int main()
{
	const int MAX = 10;
    
	int numbers[MAX] = { 19, 3, 15, 7, 11, 9, 13, 5, 17, 1 };
    
    cout << setw(5) << "INDEX" << setw(8) << "VALUE" << setw(20) << "GRAPHICS" << endl;
    cout << "----------------------------------------------\n";

	for (int i = 0; i < MAX; i++)
	{
		cout << setw(5) << i << setw(8) 
             << numbers[i] << setw(15);
		
        for (int j = 0; j < numbers[i]; j++)
			cout << '*';
		cout << endl;
	};


	return 0;
}

