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
	fstream writeData("myData.dat", ios::out | ios::binary);
	
	Data record= { "", 0.0 };   

	// Boş kayıtlar yazılıyor
	for (int count = 0; count < 5; count++)
	{
		cout << "Now writing records into file..." << count << endl;
		writeData.write((char*)&record, sizeof(record));
	}
	writeData.close();

	system("pause");
	return 0;
}



