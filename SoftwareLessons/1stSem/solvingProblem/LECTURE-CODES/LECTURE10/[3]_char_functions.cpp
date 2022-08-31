//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// char_functions.cpp
//==================================================

#include <iostream>
#include <cctype>       // for character classification & transform functions
using namespace std;

int main()
{
    char ch = 'A';

    if (isdigit(ch))        // a character between '0' and '9' 
        cout << "NUMBER\n";
    else if (isalpha(ch))   // a character between 'A(a)' and 'Z(z)'   
        {
            cout << "ALPHABETIC\n";
            if (islower(ch))
                cout << "LOWERCASE\n";  // a character between 'a' and 'z'
            else
                cout << "UPPERCASE\n";  // a character between 'A' and 'Z'
        }
    else if (isalnum(ch))   // a character between A(a)-Z(z) or 0 to 9.
        cout << "ALPHANUMERIC\n";
    else
        cout << "OTHER\n";
    
    return 0;
}

