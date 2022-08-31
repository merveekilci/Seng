//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Compares dynamic string and number arrays
// dynamic_array.cpp
//==================================================

#include <iostream>
using namespace std;

const int SIZE = 100;

enum DEPARTMENT { computer, informatics, software };

struct STUDENT
{
	string	number;
	string  name;
	string  surname;
    DEPARTMENT dept;
	float	average;
};

int main()
{
	int numberofStudens = 0;	
    cin >> numberofStudens;

	STUDENT*  students= new STUDENT[numberofStudens];                   // array of students

	for (int i = 0; i < numberofStudens; i++)
	{
		cout << "NUMBER        : ";	 cin >> students[i].number;
		cout << "NAME          : ";	 cin >> students[i].name;
		cout << "SURNAME       : ";	 cin >> students[i].surname;

        int deptID;
        cout << "DEPARTMENT    : ";  cin>>deptID;	 
        students[i].dept = static_cast<DEPARTMENT>(deptID);
		
        cout << "AVERAGE       : ";	 cin >> students[i].average;		
        cout << "\n------------------------------\n";
	}

	for (int i = 0; i < numberofStudens; i++)
	{
        cout << "NUMBER        : " << students[i].number << endl;
		cout << "NAME          : " << students[i].name << endl;
		cout << "SURNAME       : " << students[i].surname << endl;
        
        cout << "DEPARTMENT    : ";

        switch(students[i].dept) 
        {
            case 0:cout << "COMPUTER ENGINEERING" << endl; break;
            case 1:cout << "INFORMATICS" << endl; break;
            case 2:cout << "SOFTWARE ENGINEERING" << endl; break;
            default:cout<< "\n";break;
        }
        
        cout << "AVERAGE       : " << students[i].average << endl;
        cout << "\n------------------------------\n";
	}

    delete[] students;
	students = NULL;

	return 0;
}