//==================================================
// SWE 101 - Problem Solving in Software Engineering
// 2021-2022 Fall Semester
//==================================================
// FILES IN C++
//==================================================

#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>				// header file, used for purposes of localization.
using namespace std;

struct phoneBook {
	string fullName;		// name + surname
	string email;
	string telNumber;
};


int main() {
	setlocale(LC_ALL, "Turkish");	// set 

	phoneBook person1, person2;

	person1.fullName = "Gülüzar ÇİT";
	person1.email = "gulizar@sakarya.edu.tr";
	person1.telNumber = "000000000";

	person2.fullName = "A.Salih Bayraktar";
	person2.email = "asbayraktar@sakarya.edu.tr";
	person2.telNumber = "11111111";


	// 1 - open the file
	ofstream writeData("data.txt", ios::out);
	
	// 2 - do the operations 
	writeData << person1.fullName << "\t"<< person1.email << "\t"<< person1.telNumber << endl;
	writeData << person2.fullName << "\t"<< person2.email << "\t"<< person2.telNumber << endl;

	// 3 - close the file
	writeData.close();
	//-----------------------------------

	system("cls");

	string data;

	ifstream readData("data.txt", ios::in);

	phoneBook record;

	if (readData.is_open())
	{
		cout << "The file is opened successfully\n";
		cout << "--------------------------------------------------\n";


		while (!readData.eof()) {
			// read data word by word - totally a phone record
			readData >> data;	record.fullName = data;
			readData >> data;	record.fullName += " " + data;
			readData >> data;	record.email = data;
			readData >> data;	record.telNumber = data;

			// write the read data on the screen
			cout << record.fullName << "\t"
				<< record.email << "\t"
				<< record.telNumber << endl;

			cout << "--------------------------------------------------\n";
		}
	}

	readData.close();






}

