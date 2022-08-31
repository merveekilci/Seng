//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// struct_date.cpp
//==================================================

#include <iostream>
using namespace std;

struct structTime {                   
	int hour;
	int minute;
};

struct structCalendar {               
	int year;
	int month;
	int day;
	structTime time;            // nested struct
};


int main()
{
	structCalendar calendar;

	cout << "YEAR - MONTH - DAY - HOUR - MINUTE";
	cin >> calendar.year >> calendar.month >> calendar.day;
	cin >> calendar.time.hour >> calendar.time.minute;

	cout << calendar.day << calendar.month << calendar.year << '\t' 
		 << calendar.time.hour << ':' << calendar.time.minute;

	// assigning initial value to a nested struct variable
	calendar = {2020, 12, 7, {14, 0}};

	return 0;
}

