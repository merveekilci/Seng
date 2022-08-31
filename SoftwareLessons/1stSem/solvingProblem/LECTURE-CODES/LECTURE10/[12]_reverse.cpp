//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// reverse.cpp
//==================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string message;

	getline(cin, message);  	//reads also the whitespace...
	cout << message.length();
	
	//writes the string vice verse
	for (int i = message.length() - 1; i >= 0; i--)
		cout << message[i];

    return 0;
}

