//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Pointers as Function Parameters 
// function_copy.cpp
//==================================================

#include <iostream>
using namespace std;

void copyString(char*, const char*); 

int main()
{
	const char* string1 = "SAKARYA UNIVERSITESI";
	char string2[80];               

	copyString(string2, string1);//copy string1 into string2
	cout << string2 << endl;
	
	return 0;
}

void copyString(char* target, const char* source)
{
	while (*source)				//until NULL character,
		*target++ = *source++;	//copies the characters from the source to the target	
	*target= '\0';              //ends target with NULL character
}

