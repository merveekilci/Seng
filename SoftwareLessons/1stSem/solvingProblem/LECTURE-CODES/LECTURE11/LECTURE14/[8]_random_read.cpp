//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// FILES IN C++ (random access)
//==================================================


// This program executes records with empty data fields
#include <iostream>
#include <fstream>
using namespace std;

struct Data
{
	char definition[31];
	float price;
};

int main()
{
	fstream readData("myData.dat", ios::in | ios::binary);

	Data record = { "", 0.0 };

	// records are read and printed on the screen
	readData.read((char*)&record, sizeof(record));

	while (!readData.eof())
	{
		cout << "Definition....: " << record.definition << endl;
		cout << "Price.........: " << record.price << endl;

		readData.read((char*)&record, sizeof(record));
	}

	readData.close();


	system("pause");
	return 0;
}



