//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// string_class.cpp
//==================================================

#include <iostream>
#include <string>
using namespace std;

const int MAX = 80;

int main()
{
    string str1 = "";

	char str2[MAX];

	cin >> str1;

	unsigned int len = str1.length(); 

	for (int i = 0; i < len; i++)
		str2[i] = toupper(str1[i]);
	
	str2[len] = NULL;

	cout << str2 << endl;

    return 0;
}

