//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// char_copy.cpp
//==================================================

#include <iostream>
#include <cstring>					// for strlen() function
using namespace std;

const int MAX = 100;

int main()
{
    char str1[] = "HELLO WORLD. TODAY IS MONDAY!...";

	char str2[MAX];

	// gets the length of "str1"
    unsigned int length = strlen(str1);

	// copy each character of "str1" to "str2"
    for (int i = 0; i < length; i++)
		str2[i] = str1[i];
	
	// assign NULL character at the end of "str2"
    str2[length] = NULL;			// '\0'
    
	cout << str2 << endl;

    return 0;
}

