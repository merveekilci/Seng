//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers
// pointer.cpp
//==================================================

#include <iostream>

using namespace std;

int main()
{
	int x;
	int *xPtr;

	x = 3;						// stack memory
	xPtr = &x;

	cout << "address of 'x'     : " << &x << endl;
	cout << "content of 'xptr'  : " << xPtr << endl;
	cout << "value of 'x'       : " << x << endl;
	cout << "value of '*xptr'   : " << *xPtr << endl;

	cout << "\n\n* ve & operators are complement of each other\n";
	cout << "&*xptr: " << &*xPtr << endl;
	cout << "*&xptr: " << *&xPtr << endl;

	/*char   a;
	char  *b;
	char **c;

	a = 'z';
	b = &a;
	c = &b;*/

	return 0;
}
