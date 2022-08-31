//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// char_array.cpp
//==================================================

#include <iostream>
using namespace std;

const int MAX = 100;

int main()
{
    char str[MAX];

    cout << "ENTER A MESSAGE";
    cin >> str;

    cout << "ENTERED MESSAGE : " << str;


/*char str[MAX];

	cout << "ENTER A MESSAGE    : ";
    cin >> str;

    /*cout << "ENTER A MESSAGE    : ";
	cin.get(str, MAX); // also takes the whitespace characters

	cout << "ENTERED MESSAGE    : " << str << endl;

	cout << "ENTER A MESSAGE (MULTI-LINE) : ";
	// '.' - dot character
	cin.get(str, MAX, '.');  // multi-line                                
	cout << "ENTERED MESSAGE              : " << str << endl;

    cout << "ENTERED MESSAGE    : " << str;
*/
    return 0;


}

