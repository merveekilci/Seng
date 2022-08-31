//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// Struct Definition - struct
//==================================================
#include <iostream>

using namespace std;

typedef int number;
number x, y;			// x and y are integer data type


struct measure {
	number meter;
	number cm;
};

int main()
{



	measure width = { 2,40 };

	measure height;
	cout << "Enter Height (meter):";
	cin >> height.meter;

	cout << "Enter Height (cm):";
	cin >>  height.cm;

	measure circumference;
	circumference.meter = 2 * (width.meter + height.meter);
	circumference.cm = 2 * (width.cm + height.cm);

	if (circumference.cm >= 100)
	{
		int add = circumference.cm / 100;
		int remain = circumference.cm % 100;

		circumference.cm = remain;
		circumference.meter += add;
	}

	cout << "Width         : " << width.meter << " m " << width.cm << " cm" << endl;
	cout << "Height  	   : " << height.meter << " m " << height.cm << " cm" << endl;
	cout << "Circumference : " << circumference.meter << " m " << circumference.cm << " cm" << endl;

	cout << sizeof(int) << endl;
	cout << sizeof(measure) << endl;

	system("pause");
	return 0;
}