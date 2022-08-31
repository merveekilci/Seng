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

	//get a string with cin
    cout << "ENTER A MESSAGE    : ";
    cin >> str;
    cout << "ENTERED MESSAGE    : " << str;
    
    //get a string with cin.get
    cout << "ENTER A MESSAGE    : ";
	cin.get(str, MAX); // also takes the whitespace characters
	cout << "ENTERED MESSAGE    : " << str << endl;

	//get a multi-line string with cin.get
    cout << "ENTER A MESSAGE (MULTI-LINE) : ";
	cin.get(str, MAX, '.');  // multi-line ends up with dot (.) character                                
	cout << "ENTERED MESSAGE              : " << str << endl;

    //get a single line string with cin.getline
    cout << "ENTERED MESSAGE    : " << str;
    char str1[MAX];
    char str2[MAX];

	cout << "ENTER A MESSAGE    : ";

	cin.getline(str1, MAX); //reads the '\n' character
    cin.get(str2, MAX);    

	cout << "ENTERED MESSAGE    : " << str1 << endl;
    cout << "ENTERED MESSAGE    : " << str2 << endl;
    
    return 0;
}

