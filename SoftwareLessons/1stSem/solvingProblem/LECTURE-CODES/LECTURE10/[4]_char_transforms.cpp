//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// char_transform.cpp
//==================================================

#include <iostream>
#include <cctype>       // for character classification & transform functions
#include <cstring>      // for strlen() function
using namespace std;

const int MAX = 100;

int main()
{
    char message[] = "hello world";

    // gets the length of "str1"
    unsigned int length = strlen(message);

	// convert the characters of 'message' to uppercase 
    for (int i = 0; i < length; i++)
        if (islower(message[i]))
            message[i] = toupper(message[i]);        // add 32 to ASCII code
	
    cout << message << endl;

    return 0;
}

