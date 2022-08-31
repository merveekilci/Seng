//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointer Arithmetics
// arithmetic.cpp
//==================================================

#include <iostream>
using namespace std;

const int MAX = 5;

int main()
{
	/*int a[5] 	= {0};	// let the initial address of array 'a' be '0100'
						// and size of int as 2 bytes
	
	int *aPtr 	= a ;	// 'aPtr' points to array 'a'
						// so value of 'aPtr' is '0100' 

	aPtr++;				// increases address value of aPtr by 1
						// so value of 'aPtr' becomes '0102'
						// now, it points to 'a[1]'

	*(aPtr)++;			// increases the value stored in the address 
						// that 'aPtr' points to by 1
						// so, the value in 'a[1]' becomes '1'
	*/

	int a[MAX] = { 0,1,2,5,7 };
	
	int *aPtr;
	aPtr = a;

	cout << "*(a + 3)     => " << *(a + 3) << endl;
	cout << "*(aPtr++)    => " << *(aPtr++) << endl;
	cout << "*(aPtr)      => " << *(aPtr) << endl<<endl;
	//cout<<*(++a);		//error, 'a' is a pointer, it is constant

	for (int j = 0; j < 5; j++)
		cout << *(a + j) << endl;

	return 0;
}
