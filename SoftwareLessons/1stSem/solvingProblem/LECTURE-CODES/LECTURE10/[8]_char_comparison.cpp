//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// char_comparison.cpp
//==================================================

#include <iostream>
#include <cstring>					// for C-type string functions (strlen(), ctrcpy(),...)
using namespace std;

const int MAX = 100;

int main()
{
    char message[] = "HELLO WORLD. TODAY IS MONDAY!...";

	char word[MAX];

	cout << "ENTER A WORD   : ";
	cin >> word;

	if (strncmp(message, word, strlen(word)) == 0)	    // compares the message with word
        cout << "WORD IS FOUND IN MESSAGE";
    else
        cout << "WORD IS NOT FOUND IN MESSAGE";
    
	return 0;
}

