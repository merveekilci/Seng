//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// random_frequency.cpp
// Program that calculates 
// the frequency of a number in an array
//==================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>					// for time() function

using namespace std;

const int MAX = 25000;

int main()
{
	int array[MAX];
	int number, repeat;
	char selection;

	do
	{
		repeat = 0;
		
		srand(time(0));

		for (int i = 0; i < MAX; i++)
		{
			array[i] = rand() % 11;
			cout << array[i] << " ";
		}

		do {
			cout << "\nEnter a number betwwen [0-10] : ";   cin >> number;
		} while (!(number >= 0 && number <= 10));

		for (int j = 0; j < MAX; j++)
			if (number == array[j])	repeat ++;

		cout << "\n" << repeat << endl;
		
		do
		{
			cout << "DO YOU WANT TO CONTINUE [Y / N]";
			cin >> selection;
		} while (!(selection == 'y' || selection == 'Y' || selection == 'n' || selection == 'N'));
		
	} while (selection == 'y' || selection == 'Y');

	return 0;
}
