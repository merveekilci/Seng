//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers as Function Parameters 
// function_uppercase.cpp
//==================================================

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	//without 'nothrow'
	/*int *ptr1;
	int *ptr2=new int[3];	// allocates memory as 3*sizeof(int)

	delete ptr1;			// deallocates memory for ptr1 int
	delete[] ptr2;			// deallocates memory for ptr2 int array
	*/

	//with 'nothrow'
	int *ptr;
	ptr = new (nothrow) int[3];

	if (ptr)	cout << "Memory Allocation is Performed";
	else		cout << "Memory Allocation is not Performed";
	
	delete[] ptr;

	return 0;
}


// m1->meter means
m1*.meter

