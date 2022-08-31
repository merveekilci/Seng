//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// string.cpp
//==================================================

#include <iostream>
using namespace std;

int main()
{
    const int DAY = 7;
	const int MAX = 10;

	// C-type string (array of characters)
    char days_of_week[DAY][MAX] = { "Monday", "Tuesday","Wednesday",
							        "Thursday","Friday","Saturday","Sunday" };
	
	for (int i = 0; i < DAY; i++)
		cout << days_of_week[i] << endl;

	// C++ string type
    string days_of_week_2[DAY]= { "Monday", "Tuesday","Wednesday",
							      "Thursday","Friday","Saturday","Sunday" };
    
	for (int i = 0; i < DAY; i++)
		cout << days_of_week_2[i] << endl;

    //cout << sizeof (string) << endl;

    return 0;
}

