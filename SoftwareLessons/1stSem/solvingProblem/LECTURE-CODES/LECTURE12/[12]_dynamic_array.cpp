//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers & Struct
// dynamic_array.cpp
//==================================================

#include <iostream>
using namespace std;

int main()
{
	int *numbers;
	
	int N;	cout << "ENTER ARRAY SIZE : "; cin >> N;
	
	numbers = new int[N];

	//numbers=NULL;
	if (numbers == NULL) return 0;
	
	for (int i = 0; i < N; i++)
	{
		cout << "ENTER A NUMBER : ";
		cin >> numbers[i];
	}

	cout << "VALUES OF ARRAY :   ";
	
	for (int i = 0; i < N; i++)
		cout << numbers[i] << ", ";
	
	delete[] numbers;

    
	return 0;
}
