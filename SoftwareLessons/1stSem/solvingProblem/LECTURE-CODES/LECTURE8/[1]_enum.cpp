//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// enum.cpp
//==================================================

#include <iostream>
using namespace std;

// Example 1:
// computer is 0, informatics is 1 and so on... 
// variable is declared here
//enum enumDepartments { computer, informatics, software } department;

// Example 2:
// computer is 1, informatics is 4 and software is 5 (4+1)  
// variable should be declared in main()
//enum enumDepartments { computer=1, informatics=4, software };

// Example 3:
// variable should be declared in main()
enum enumDepartments { computer, informatics, software };

int main()
{
	enum enumDepartments department;
	department = computer;
	cout << department << endl;
	
	department=static_cast<enumDepartments>(department+1);
	cout << department << endl;
	
	return 0;
}

