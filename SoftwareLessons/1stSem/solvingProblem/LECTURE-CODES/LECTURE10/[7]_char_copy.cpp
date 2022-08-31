//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// char_copy.cpp
//==================================================

#include <iostream>
#include <cstring>					// for C-type string functions (strlen(), ctrcpy(),...)
using namespace std;

const int MAX = 100;

int main()
{
    char str1[] = "HELLO WORLD. TODAY IS MONDAY!...";

	char str2[MAX];
    char str3[MAX];

	cout << "Length of 1st string : " <<  strlen(str1) << endl;

	strcpy(str2, str1);         // copy str1 into str2
    cout << str2 << endl;

    strncpy(str3, str1,11);     // copy first 11 characters of str1 into str2
    cout << str3 << endl;
	
    return 0;
}

