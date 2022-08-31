//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Compares dynamic string and number arrays
// dynamic_array.cpp
//==================================================

#include <iostream>
using namespace std;

const int SIZE = 20;

int main()
{
    
	int *ptrInt = new int[SIZE];        //allocated n integers in the heap memory

    cout << ptrInt << endl;             //prints the starting address of n integers 
                                        //allocated in the heap memory

    ptrInt[0]=10;
    cout << *ptrInt << endl;            //it prints 10

    char *message = new char[SIZE];     
    cout << message << endl;            //we expect to print the starting address
                                        //of the memory allocated for the 'message'
                                        //but it prints the string because
                                        //it is a pointer variable that points to a string

    int *ptrChar = (int*)message;       
    cout << ptrChar << endl;            //prints the starting address of the memory
                                        //allocated for the 'message'

    delete[] ptrInt;
    delete[] message;

    ptrInt = NULL;
    message = NULL;


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
