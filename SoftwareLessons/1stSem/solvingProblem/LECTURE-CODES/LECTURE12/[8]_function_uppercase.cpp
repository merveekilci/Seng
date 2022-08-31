//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers as Function Parameters 
// function_uppercase.cpp
//==================================================

#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 100;
void toUpper(char*, char*); 

int main()
{
	char string1[SIZE];
	//char *string1 = new char[SIZE];

	cout << "ENTER A STRING : ";
	cin.get(string1,SIZE);

	char string2[SIZE];               

	toUpper(string2, string1);//copy string1 into string2
	cout << string2 << endl;
	
	return 0;
}

void toUpper(char* target, char* source)
{
	while (*source)				     	//until NULL character,
		if (islower(*source))
			*target++=toupper(*source++);//copies the characters from the source 
         					     	 	//to the targetin the uppercase format
	*target= '\0';                   	//ends target with NULL character
}

